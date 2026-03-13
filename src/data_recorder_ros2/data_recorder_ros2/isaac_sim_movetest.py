#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from sensor_msgs.msg import JointState
import time

class JointCommandPublisher(Node):
    def __init__(self):
        super().__init__('joint_command_sequence')
        self.publisher_ = self.create_publisher(JointState, '/joint_command', 10)

    def send_command(self, names, positions):
        msg = JointState()
        msg.name = names
        msg.position = positions
        msg.velocity = [0.0] * len(names)
        msg.effort = [0.0] * len(names)
        self.publisher_.publish(msg)
        self.get_logger().info(f'Published command: {positions}')

def main(args=None):
    rclpy.init(args=args)
    node = JointCommandPublisher()

    joint_names = ['joint1','joint2','joint3','joint4','joint5','joint6']

    # Define the sequence of positions
    sequence = [
        [-1.5, 1.51, -1.17, 0.0, 1.2, 0.0],
        [-1.5, 1.86, -1.08, 0.0, 0.785, 0.0],
        [-1.5, 1.51, -1.17, 0.0, 1.2, 0.0],
        [ 1.5, 1.51, -1.17, 0.0, 1.2, 0.0],
        [ 1.5, 1.86, -1.08, 0.0, 0.785, 0.0],
    ]
    time.sleep(5.0)
    # Publish each command with a delay
    for positions in sequence:
        node.send_command(joint_names, positions)
        time.sleep(1.0)  # wait 2 seconds between commands

    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
