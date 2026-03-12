#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
import subprocess
import os
from std_srvs.srv import Trigger
from data_recorder_interfaces.srv import StartRecording  # custom ROS2 service
from ament_index_python.packages import get_package_share_directory
import os

class RosbagRecorder(Node):
    def __init__(self):
        super().__init__('rosbag_recorder_service')
        self.record_process = None
        self.current_file = None

        # Declare parameters
        self.declare_parameter('topics', '')

        # Resolve save_dir relative to the package directory
        package_dir = get_package_share_directory('data_recorder_ros2')
        self.save_dir = os.path.join(package_dir, 'rosbags')

        if not os.path.exists(self.save_dir):
            os.makedirs(self.save_dir)

        self.topics = self.get_parameter('topics').value

        # Create services
        self.create_service(StartRecording, '/start_recording', self.start_recording_cb)
        self.create_service(Trigger, '/stop_recording', self.stop_recording_cb)

        self.get_logger().info(f"Recorder services ready. Saving to: {self.save_dir}")

    def start_recording_cb(self, request, response):
        if self.record_process is not None:
            response.success = False
            response.message = "Already recording"
            return response

        filename = f"{request.item_type}_{request.operator_id}_{self.get_clock().now().to_msg().sec}.db3"
        filepath = os.path.join(self.save_dir, filename)
        self.current_file = filepath

        # Use ros2 bag instead of rosbag
        cmd = ["ros2", "bag", "record", "-o", filepath] + self.topics.split()
        self.record_process = subprocess.Popen(cmd)

        self.get_logger().info(f"Operator {request.operator_id} started recording to {filepath}")
        response.success = True
        response.message = f"Recording to {filepath}"
        return response

    def stop_recording_cb(self, request, response):
        if self.record_process is None:
            response.success = False
            response.message = "Not recording"
            return response

        self.record_process.terminate()
        self.record_process.wait()
        self.record_process = None

        self.get_logger().info(f"Stopped recording {self.current_file}")
        response.success = True
        response.message = self.current_file or "Recording stopped"
        return response


def main(args=None):
    rclpy.init(args=args)
    node = RosbagRecorder()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()


if __name__ == '__main__':
    main()
