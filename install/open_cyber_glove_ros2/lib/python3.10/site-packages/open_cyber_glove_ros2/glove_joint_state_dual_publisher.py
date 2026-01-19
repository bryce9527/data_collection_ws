#!/usr/bin/env python3
import os, json, time, signal
import numpy as np
import rclpy
from rclpy.node import Node
from sensor_msgs.msg import JointState
from std_msgs.msg import Bool
from geometry_msgs.msg import PoseArray, Pose, Point
from open_cyber_glove.sdk import OpenCyberGlove
from open_cyber_glove.visualizer import HandVisualizer

class GlovePublisher(Node):
    def __init__(self):
        super().__init__('dual_glove_joint_state_publisher')

        # Declare parameters with defaults
        self.declare_parameter('left_port', '/dev/cyberglove_left')
        self.declare_parameter('right_port', '/dev/cyberglove_right')
        self.declare_parameter('rate_hz', 50.0)
        self.declare_parameter('mode', 'load')
        self.declare_parameter('calib_file', 'glove_calibration.json')
        self.declare_parameter('hand_model', '/home/bryce/ros2_workspace/data_collection_ws/src/open_cyber_glove/model/hand_model.pkl')
        self.declare_parameter('model_path', '/home/bryce/ros2_workspace/data_collection_ws/src/open_cyber_glove/model/20250703_110909.onnx')

        # Get parameter values
        left_port  = self.get_parameter('left_port').value
        right_port = self.get_parameter('right_port').value
        rate_hz    = float(self.get_parameter('rate_hz').value)
        mode       = self.get_parameter('mode').value
        calib_file = self.get_parameter('calib_file').value
        hand_model = self.get_parameter('hand_model').value
        model_path = self.get_parameter('model_path').value

        # Publishers
        self.pub_left = self.create_publisher(JointState, '/glove_left/joint_states', 10)
        self.pub_right = self.create_publisher(JointState, '/glove_right/joint_states', 10)
        self.heartbeat_left = self.create_publisher(Bool, '/heartbeat/glove_left', 1)
        self.heartbeat_right = self.create_publisher(Bool, '/heartbeat/glove_right', 1)
        self.pub_left_pose = self.create_publisher(PoseArray, '/glove_left/joint_positions', 10)
        self.pub_right_pose = self.create_publisher(PoseArray, '/glove_right/joint_positions', 10)

        # Visualizer and glove SDK
        self.visualizer = HandVisualizer(model_path=hand_model)
        self.glove = OpenCyberGlove(left_port=left_port, right_port=right_port, model_path=model_path)
        self.glove.start()
        self.handle_calibration(mode, calib_file)

        # Timer for publishing loop
        self.timer = self.create_timer(1.0 / rate_hz, self.timer_callback)

    def handle_calibration(self, mode, calib_file):
        # same logic as your ROS1 version, but use self.get_logger().info/warn instead of rospy.loginfo/warn
        def save_calibration():
            calib = {
                "left_min_val": self.glove.left_glove.min_val,
                "left_max_val": self.glove.left_glove.max_val,
                "left_avg_val": self.glove.left_glove.avg_val.tolist(),
                "right_min_val": self.glove.right_glove.min_val,
                "right_max_val": self.glove.right_glove.max_val,
                "right_avg_val": self.glove.right_glove.avg_val.tolist(),
            }
            dirpath = os.path.dirname(calib_file)
            if dirpath:
                os.makedirs(dirpath, exist_ok=True)
            with open(calib_file, "w") as f:
                json.dump(calib, f)
            self.get_logger().info(f"Calibration saved to {calib_file}")

        def load_calibration():
            with open(calib_file) as f:
                calib = json.load(f)
            self.glove.left_glove.min_val  = calib["left_min_val"]
            self.glove.left_glove.max_val  = calib["left_max_val"]
            self.glove.left_glove.avg_val  = np.array(calib["left_avg_val"])
            self.glove.right_glove.min_val = calib["right_min_val"]
            self.glove.right_glove.max_val = calib["right_max_val"]
            self.glove.right_glove.avg_val = np.array(calib["right_avg_val"])
            self.glove.is_calibrated = True
            self.get_logger().info(f"Loaded calibration from {calib_file}")

        # Main decision logic
        if mode == "calibrate":
            self.get_logger().info("Running calibration (forced)...")
            self.glove.calibrate()
            save_calibration()
        elif mode == "load":
            if os.path.exists(calib_file):
                load_calibration()
            else:
                self.get_logger().warn("Calibration file missing, running calibration instead...")
                self.glove.calibrate()
                save_calibration()
        else:
            self.get_logger().warn(f"Unknown mode '{mode}', defaulting to load‑or‑calibrate fallback")
            if os.path.exists(calib_file):
                load_calibration()
            else:
                self.glove.calibrate()
                save_calibration()



    def timer_callback(self):
        # publish heartbeat
        self.heartbeat_left.publish(Bool(data=True))
        self.heartbeat_right.publish(Bool(data=True))

        # build and publish JointState + PoseArray
        js_left = JointState()
        js_right = JointState()
        now = self.get_clock().now().to_msg()
        js_left.header.stamp = now
        js_right.header.stamp = now

        if self.glove.left_glove is not None:
            angles_left = self.glove.get_angles(hand_type='left', method='model')
            js_left.name = [f"left_joint_{i}" for i in range(len(angles_left))]
            js_left.position = angles_left.tolist()
            self.pub_left.publish(js_left)

            joints_left = self.visualizer.get_joints(angles_left, hand_type='left')
            pose_array_left = PoseArray()
            pose_array_left.header.stamp = now
            pose_array_left.poses = []
            for pos in joints_left:
                p = Pose()
                p.position = Point(x=pos[0], y=pos[1], z=pos[2])
                pose_array_left.poses.append(p)
            self.pub_left_pose.publish(pose_array_left)

        if self.glove.right_glove is not None:
            angles_right = self.glove.get_angles(hand_type='right', method='model')
            js_right.name = [f"right_joint_{i}" for i in range(len(angles_right))]
            js_right.position = angles_right.tolist()
            self.pub_right.publish(js_right)

            joints_right = self.visualizer.get_joints(angles_right, hand_type='right')
            pose_array_right = PoseArray()
            pose_array_right.header.stamp = now
            pose_array_right.poses = []
            for pos in joints_right:
                p = Pose()
                p.position = Point(x=pos[0], y=pos[1], z=pos[2])
                pose_array_right.poses.append(p)
            self.pub_right_pose.publish(pose_array_right)



def main(args=None):
    rclpy.init(args=args)
    node = GlovePublisher()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()
