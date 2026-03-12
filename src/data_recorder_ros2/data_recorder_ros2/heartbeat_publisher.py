#!/usr/bin/env python3

import rclpy
from rclpy.node import Node
import importlib
import sys
from std_msgs.msg import Bool
from data_recorder_interfaces.msg import Float32Stamped

class HeartbeatPublisher(Node):
    def __init__(self, sensor_name, topic_to_watch, topic_type):
        super().__init__(f'{sensor_name}_heartbeat_node')
        self.sensor_name = sensor_name
        self.topic_to_watch = topic_to_watch
        self.topic_type = topic_type
        self.last_msg_time = None

        # Normalize topic_type string
        parts = topic_type.split('/')
        if len(parts) == 2:
            pkg, msg = parts
        elif len(parts) == 3 and parts[1] == 'msg':
            pkg, msg = parts[0], parts[2]
        else:
            raise ValueError(f"Unexpected topic_type format: {topic_type}")

        # Dynamically import the message class
        msg_module = importlib.import_module(pkg + ".msg")
        msg_class = getattr(msg_module, msg)

        # Publisher
        self.pub = self.create_publisher(Bool, f'/heartbeat/{sensor_name}', 10)

        # Subscriber
        self.sub = self.create_subscription(
            msg_class,
            topic_to_watch,
            self.make_callback(f"{pkg}/{msg}"),
            10
        )

        # Timer at 1 Hz
        self.timer = self.create_timer(1.0, self.publish_heartbeat)

        self.get_logger().info(
            f"Heartbeat publisher for {sensor_name} watching {topic_to_watch} ({pkg}/{msg})"
        )

    def make_callback(self, msg_type):
        def callback(msg):
            valid = False
            if msg_type in ("data_recorder_interfaces/Float32Stamped", "data_recorder_interfaces/msg/Float32Stamped"):
                # Simple validity check: data field exists
                valid = hasattr(msg, "data")
            elif msg_type in ("sensor_msgs/Image", "sensor_msgs/msg/Image"):
                valid = hasattr(msg, "data") and len(msg.data) > 0
            elif msg_type in ("sensor_msgs/PointCloud2", "sensor_msgs/msg/PointCloud2"):
                valid = msg.width > 0 and msg.height > 0
            elif msg_type in ("sensor_msgs/JointState", "sensor_msgs/msg/JointState"):
                valid = len(msg.position) > 0 or len(msg.velocity) > 0
            elif msg_type in ("geometry_msgs/PoseStamped", "geometry_msgs/msg/PoseStamped"):
                # Check that position and orientation are non-trivial
                valid = (
                    not (msg.pose.position.x == 0.0 and
                        msg.pose.position.y == 0.0 and
                        msg.pose.position.z == 0.0)
                    or
                    not (msg.pose.orientation.x == 0.0 and
                        msg.pose.orientation.y == 0.0 and
                        msg.pose.orientation.z == 0.0 and
                        msg.pose.orientation.w == 0.0)
                )
            else:
                valid = True

            if valid:
                self.last_msg_time = self.get_clock().now()
        return callback


    def publish_heartbeat(self):
        alive = False
        now = self.get_clock().now()

        if self.last_msg_time is None:
            alive = False
        elif (now - self.last_msg_time).nanoseconds / 1e9 > 2.0:
            alive = False
        else:
            alive = True

        msg = Bool()
        msg.data = alive
        self.pub.publish(msg)

def main(args=None):
    rclpy.init(args=args)
    if len(sys.argv) < 4:
        print("Usage: heartbeat_publisher.py <sensor_name> <topic_to_watch> <topic_type>")
        return

    sensor_name = sys.argv[1]
    topic_to_watch = sys.argv[2]
    topic_type = sys.argv[3]

    node = HeartbeatPublisher(sensor_name, topic_to_watch, topic_type)
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()
