import rclpy
from rclpy.node import Node
from geometry_msgs.msg import PoseStamped
from piper_msgs.msg import PosCmd
import transforms3d.euler
import transforms3d.quaternions as tq
import threading
import sys
import math

def safe_normalize_quat(q):
    """Normalize quaternion safely, return [w,x,y,z] or None if invalid."""
    norm = (q[0]**2 + q[1]**2 + q[2]**2 + q[3]**2) ** 0.5
    if norm < 1e-8:
        return None
    return [q[0]/norm, q[1]/norm, q[2]/norm, q[3]/norm]

def safe_quat_to_euler(q):
    """Convert quaternion to euler safely, return (roll,pitch,yaw)."""
    qn = safe_normalize_quat(q)
    if qn is None:
        return 0.0, 0.0, 0.0
    try:
        return transforms3d.euler.quat2euler(qn)
    except Exception:
        return 0.0, 0.0, 0.0

def clamp_nan(value, default=0.0):
    """Replace NaN with default."""
    return value if not math.isnan(value) else default

class TeleopNode(Node):
    def __init__(self):
        super().__init__('teleop_node')

        # Subscriptions
        self.tracker_sub = self.create_subscription(
            PoseStamped,
            '/vive_tracker/tracker2',
            self.tracker_callback,
            10)
        self.robot_sub = self.create_subscription(
            PoseStamped,
            '/end_pose_stamped',
            self.robot_callback,
            10)

        self.publisher = self.create_publisher(PosCmd, '/pos_cmd', 10)

        # Calibration states
        self.robot_alignment_quat = None   # robot quaternion at alignment
        self.robot_home = None             # robot position at alignment
        self.latest_tracker_msg = None     # always store latest tracker msg
        self.wrist_baseline_pose = None
        self.teleop_active = False
        self.q_rel = None

        # Start keyboard listener
        threading.Thread(target=self.keyboard_listener, daemon=True).start()

    def robot_callback(self, msg):
        # Only capture once
        if self.robot_home is None:
            q = msg.pose.orientation
            self.robot_alignment_quat = [q.w, q.x, q.y, q.z]
            p = msg.pose.position
            self.robot_home = {"x": p.x, "y": p.y, "z": p.z}
            self.get_logger().info(
                f"Robot home captured: pos=({p.x:.3f}, {p.y:.3f}, {p.z:.3f}), quat={self.robot_alignment_quat}"
            )

    def tracker_callback(self, msg):
        # Always store latest tracker message
        self.latest_tracker_msg = msg

        if not self.teleop_active or self.robot_home is None or self.wrist_baseline_pose is None:
            return

        # Relative displacement
        dx = msg.pose.position.x - self.wrist_baseline_pose.x
        dy = msg.pose.position.y - self.wrist_baseline_pose.y
        dz = msg.pose.position.z - self.wrist_baseline_pose.z

        # Map tracker axes to robot axes
        robot_dx = -dz
        robot_dy = -dx
        robot_dz = dy

        # Orientation from tracker
        q_tracker_now = [msg.pose.orientation.w,
                         msg.pose.orientation.x,
                         msg.pose.orientation.y,
                         msg.pose.orientation.z]
        q_tracker_now = safe_normalize_quat(q_tracker_now)
        if q_tracker_now is None:
            roll, pitch, yaw = 0.0, 0.0, 0.0
        else:
            if self.q_rel is not None:
                q_robot_target = tq.qmult(self.q_rel, q_tracker_now)
                roll, pitch, yaw = safe_quat_to_euler(q_robot_target)
            else:
                roll, pitch, yaw = safe_quat_to_euler(q_tracker_now)

        # Clamp NaNs and ranges
        roll = clamp_nan(max(-1.5, min(1.0, roll)))
        pitch = clamp_nan(max(-1.5, min(1.0, pitch)))
        yaw = clamp_nan(max(-2.0, min(1.5, yaw)))

        # Target pose relative to robot home
        cmd = PosCmd()
        cmd.x = max(-0.62, min(0.62, self.robot_home["x"] + robot_dx))
        cmd.y = max(-0.62, min(0.62, self.robot_home["y"] + robot_dy))
        cmd.z = max(0.0, min(0.74, self.robot_home["z"] + robot_dz))
        cmd.roll = 3.14
        cmd.pitch = 0.0
        cmd.yaw = 1.57
        cmd.gripper = 0.0
        cmd.mode1 = 0
        cmd.mode2 = 0

        self.publisher.publish(cmd)

    def keyboard_listener(self):
        self.get_logger().info("Keys: 'c' = calibrate, 'w' = set wrist baseline, 's' = start teleop, 'q' = stop teleop.")
        while True:
            key = sys.stdin.read(1)
            if key == 'c':
                if self.robot_alignment_quat is not None and self.latest_tracker_msg is not None:
                    # Robot quaternion
                    q_robot = safe_normalize_quat(self.robot_alignment_quat)
                    # Tracker quaternion
                    q_tracker = [self.latest_tracker_msg.pose.orientation.w,
                                 self.latest_tracker_msg.pose.orientation.x,
                                 self.latest_tracker_msg.pose.orientation.y,
                                 self.latest_tracker_msg.pose.orientation.z]
                    q_tracker = safe_normalize_quat(q_tracker)

                    if q_robot is not None and q_tracker is not None:
                        self.q_rel = tq.qmult(q_robot, tq.qconjugate(q_tracker))
                        self.get_logger().info("Calibration complete. q_rel set.")
                    else:
                        self.get_logger().warn("Calibration failed: invalid quaternion.")
                else:
                    self.get_logger().warn("Calibration failed: missing robot or tracker data.")

            elif key == 'w':
                if self.latest_tracker_msg is not None:
                    self.wrist_baseline_pose = self.latest_tracker_msg.pose.position
                    self.get_logger().info(
                        f"Wrist baseline set at ({self.wrist_baseline_pose.x:.3f}, "
                        f"{self.wrist_baseline_pose.y:.3f}, {self.wrist_baseline_pose.z:.3f}).")
                else:
                    self.get_logger().warn("No tracker data yet to set wrist baseline.")

            elif key == 's':
                if self.q_rel is not None and self.wrist_baseline_pose is not None:
                    self.teleop_active = True
                    self.get_logger().info("Teleoperation started.")
                else:
                    self.get_logger().warn("Cannot start teleop: calibration and baseline required.")

            elif key == 'q':
                self.teleop_active = False
                self.get_logger().info("Teleoperation stopped.")

def main():
    rclpy.init()
    node = TeleopNode()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
