import rclpy
from rclpy.node import Node
from geometry_msgs.msg import PoseStamped
from piper_msgs.msg import PosCmd
import transforms3d.euler
import transforms3d.quaternions as tq
import threading
import sys
import math
import numpy as np

def safe_normalize_quat(q):
    norm = (q[0]**2 + q[1]**2 + q[2]**2 + q[3]**2) ** 0.5
    if norm < 1e-8:
        return None
    return [q[0]/norm, q[1]/norm, q[2]/norm, q[3]/norm]

def safe_quat_to_euler(q):
    qn = safe_normalize_quat(q)
    if qn is None:
        return 0.0, 0.0, 0.0
    try:
        return transforms3d.euler.quat2euler(qn)
    except Exception:
        return 0.0, 0.0, 0.0

def clamp_nan(value, default=0.0):
    return value if not math.isnan(value) else default

class TeleopNode(Node):
    def __init__(self):
        super().__init__('teleop_absolute_calibrated')

        # Subscriptions
        self.tracker_sub = self.create_subscription(
            PoseStamped,
            '/vive_tracker/tracker3',
            self.tracker_callback,
            10)
        self.robot_sub = self.create_subscription(
            PoseStamped,
            '/end_pose_stamped',
            self.robot_callback,
            10)

        self.publisher = self.create_publisher(PosCmd, '/pos_cmd', 10)

        # Calibration states
        self.robot_alignment_quat = None
        self.robot_home = None
        self.tracker_home = None
        self.tracker_alignment_quat = None
        self.latest_tracker_msg = None
        self.teleop_active = False
        self.q_rel = None

        # User-defined offset (adjustable live)
        self.offset = {"x": 0.0, "y": 0.2, "z": 0.0}

        threading.Thread(target=self.keyboard_listener, daemon=True).start()

    def robot_callback(self, msg):
        if self.robot_home is None:
            # Anchor to base origin, not end-effector
            self.robot_home = {"x": 0.0, "y": 0.0, "z": 0.0}
            self.robot_alignment_quat = [1.0, 0.0, 0.0, 0.0]  # identity quaternion
            self.get_logger().info("Robot base set to origin (0,0,0)")


    def tracker_callback(self, msg):
        self.latest_tracker_msg = msg

        if not self.teleop_active or self.robot_home is None or self.q_rel is None:
            return

        # Displacement relative to tracker calibration origin
        dx = msg.pose.position.x - self.tracker_home["x"]
        dy = msg.pose.position.y - self.tracker_home["y"]
        dz = msg.pose.position.z - self.tracker_home["z"]

        # Map tracker axes to robot axes
        robot_dx = -dz
        robot_dy = -dx
        robot_dz = dy

        # Apply fixed calibration offset + live fine-tune offset
        robot_dx += self.pos_offset["x"] + self.offset["x"]
        robot_dy += self.pos_offset["y"] + self.offset["y"]
        robot_dz += self.pos_offset["z"] + self.offset["z"]

        # Target pose (anchored to base origin)
        cmd = PosCmd()
        cmd.x = max(-0.62, min(0.62, robot_dx))
        cmd.y = max(-0.62, min(0.62, robot_dy))
        cmd.z = max(0.0, min(0.74, robot_dz))

        # Option1: use tracker orientation
        # cmd.roll = roll
        # cmd.pitch = pitch
        # cmd.yaw = yaw

        # Option2: fix orientation downward
        # cmd.roll = 3.14
        # cmd.pitch = 0.0
        # cmd.yaw = 1.57

        # --- Orientation: outward + downward tilt ---
        vec = np.array([cmd.x - self.robot_home["x"],
                        cmd.y - self.robot_home["y"],
                        cmd.z - self.robot_home["z"]])

        norm = np.linalg.norm(vec)
        if norm > 1e-6:
            dir_out = vec / norm
        else:
            dir_out = np.array([0.0, 1.0, 0.0])  # default forward

        down = np.array([0.0, 0.0, -1.0])

        # Blend outward and downward equally (≈45° tilt)
        blend = dir_out + down
        blend = blend / np.linalg.norm(blend)

        # Palm Z-axis = blend
        z_axis = blend / np.linalg.norm(blend)

        # Start from stored reference axis
        x_axis = self.x_axis_ref

        # Re-orthogonalize smoothly
        x_axis = x_axis - np.dot(x_axis, z_axis) * z_axis
        x_axis = x_axis / np.linalg.norm(x_axis)

        # Compute Y-axis
        y_axis = np.cross(z_axis, x_axis)

        # Build rotation matrix
        R = np.column_stack((x_axis, y_axis, z_axis))

        # Optional: apply fixed roll offset around z_axis
        roll_offset = 0.0  # set to e.g. math.pi/2 for palm-down
        q_offset = tq.axangle2quat(z_axis, roll_offset)
        q_tilt = tq.qmult(tq.mat2quat(R), q_offset)

        roll, pitch, yaw = safe_quat_to_euler(q_tilt)
        cmd.roll, cmd.pitch, cmd.yaw = clamp_nan(roll), clamp_nan(pitch), clamp_nan(yaw)

        cmd.gripper = 0.0
        cmd.mode1 = 0
        cmd.mode2 = 0

        self.publisher.publish(cmd)


    def keyboard_listener(self):
        self.get_logger().info(
            "Keyboard controls:\n"
            "  c = calibrate (capture robot + tracker alignment)\n"
            "  s = start teleop (begin following tracker)\n"
            "  q = stop teleop\n"
            "  i = offset +Y (move robot forward)\n"
            "  k = offset -Y (move robot backward)\n"
            "  j = offset -X (move robot left)\n"
            "  l = offset +X (move robot right)\n"
            "  u = offset +Z (raise robot)\n"
            "  o = offset -Z (lower robot)"
        )

        while True:
            key = sys.stdin.read(1)
            # if key == 'c':
            #     if self.robot_alignment_quat is not None and self.latest_tracker_msg is not None:
            #         # Capture tracker home (for orientation alignment only)
            #         p = self.latest_tracker_msg.pose.position
            #         self.tracker_home = {"x": p.x, "y": p.y, "z": p.z}
            #         q = self.latest_tracker_msg.pose.orientation
            #         self.tracker_alignment_quat = [q.w, q.x, q.y, q.z]

            #         # Set the known fixed offset between tracker mount and robot base (robot coordinates)
            #         self.pos_offset = {
            #             "x": 0.10,   # example: 10 cm right
            #             "y": 0.00,   # example: aligned forward
            #             "z": 0.015   # example: 1.5 cm higher
            #         }

            #         # Compute orientation offset
            #         q_robot = safe_normalize_quat(self.robot_alignment_quat)
            #         q_tracker = safe_normalize_quat(self.tracker_alignment_quat)
            #         if q_robot is not None and q_tracker is not None:
            #             self.q_rel = tq.qmult(q_robot, tq.qconjugate(q_tracker))
            #             self.get_logger().info(
            #                 f"Calibration complete. q_rel set. Fixed pos_offset = {self.pos_offset}"
            #             )
            #         else:
            #             self.get_logger().warn("Calibration failed: invalid quaternion.")
            #     else:
            #         self.get_logger().warn("Calibration failed: missing robot or tracker data.")
            if key == 'c':
                if self.robot_alignment_quat is not None and self.latest_tracker_msg is not None:
                    # Capture tracker home (for orientation alignment only)
                    p = self.latest_tracker_msg.pose.position
                    self.tracker_home = {"x": p.x, "y": p.y, "z": p.z}
                    q = self.latest_tracker_msg.pose.orientation
                    self.tracker_alignment_quat = [q.w, q.x, q.y, q.z]

                    # Set the known fixed offset between tracker mount and robot base (robot coordinates)
                    self.pos_offset = {
                        "x": 0.10,
                        "y": 0.00,
                        "z": 0.015
                    }

                    # Compute orientation offset
                    q_robot = safe_normalize_quat(self.robot_alignment_quat)
                    q_tracker = safe_normalize_quat(self.tracker_alignment_quat)
                    if q_robot is not None and q_tracker is not None:
                        self.q_rel = tq.qmult(q_robot, tq.qconjugate(q_tracker))

                        # --- NEW: capture wrist roll reference axis ---
                        # Palm pointing direction at calibration (outward + downward blend)
                        dir_out = np.array([0.0, 1.0, 0.0])   # forward
                        down = np.array([0.0, 0.0, -1.0])     # downward
                        blend = dir_out + down
                        blend = blend / np.linalg.norm(blend)
                        z_axis = blend

                        # Choose a fixed world axis to lock wrist roll

                        # Option A: world X
                        # ref_axis = np.array([1.0, 0.0, 0.0])

                        # Option B: world Y
                        # ref_axis = np.array([0.0, 1.0, 0.0])

                        # Option C: world -X
                        # ref_axis = np.array([-1.0, 0.0, 0.0])

                        # Option D: world -Y
                        ref_axis = np.array([0.0, -1.0, 0.0])


                        x_axis = ref_axis - np.dot(ref_axis, z_axis) * z_axis
                        x_axis = x_axis / np.linalg.norm(x_axis)

                        # Store reference axis for later use
                        self.x_axis_ref = x_axis

                        self.get_logger().info(
                            f"Calibration complete. q_rel set. Fixed pos_offset = {self.pos_offset}. Wrist roll reference captured."
                        )
                    else:
                        self.get_logger().warn("Calibration failed: invalid quaternion.")
                else:
                    self.get_logger().warn("Calibration failed: missing robot or tracker data.")

            elif key == 's':
                if self.q_rel is not None and self.tracker_home is not None:
                    self.teleop_active = True
                    self.get_logger().info("Teleoperation started.")
                else:
                    self.get_logger().warn("Cannot start teleop: calibration required.")

            elif key == 'q':
                self.teleop_active = False
                self.get_logger().info("Teleoperation stopped.")

            # Live offset adjustment
            elif key == 'i':  # increase Y
                self.offset["y"] += 0.01
                self.get_logger().info(f"Offset Y increased: {self.offset['y']:.3f}")
            elif key == 'k':  # decrease Y
                self.offset["y"] -= 0.01
                self.get_logger().info(f"Offset Y decreased: {self.offset['y']:.3f}")
            elif key == 'j':  # decrease X
                self.offset["x"] -= 0.01
                self.get_logger().info(f"Offset X decreased: {self.offset['x']:.3f}")
            elif key == 'l':  # increase X
                self.offset["x"] += 0.01
                self.get_logger().info(f"Offset X increased: {self.offset['x']:.3f}")
            elif key == 'u':  # increase Z
                self.offset["z"] += 0.01
                self.get_logger().info(f"Offset Z increased: {self.offset['z']:.3f}")
            elif key == 'o':  # decrease Z
                self.offset["z"] -= 0.01
                self.get_logger().info(f"Offset Z decreased: {self.offset['z']:.3f}")

def main():
    rclpy.init()
    node = TeleopNode()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
