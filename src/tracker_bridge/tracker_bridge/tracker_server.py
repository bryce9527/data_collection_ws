import socket, struct
import rclpy
from rclpy.node import Node
from geometry_msgs.msg import PoseStamped

class TrackerServer(Node):
    def __init__(self):
        super().__init__('tracker_server')

        # Fixed mapping: serial → friendly topic name
        self.serial_map = {
            "58-A33403576": "vive_tracker/tracker1",
            "58-A33403591": "vive_tracker/tracker2",
            "58-A33403525": "vive_tracker/tracker3",
        }

        # Publishers dictionary, created only when tracker connects
        self.pubs = {}

        server_ip = '0.0.0.0'
        server_port = 9000
        self.sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        self.sock.bind((server_ip, server_port))
        self.sock.listen(1)

        self.get_logger().info("Waiting for Windows client...")
        self.conn, addr = self.sock.accept()
        self.get_logger().info(f"Connected by {addr}")

        self.create_timer(0.01, self.receive_data)

    def receive_data(self):
        header = self.conn.recv(8)
        if not header:
            return
        (length,) = struct.unpack("Q", header)
        data = self.conn.recv(length).decode()

        parts = data.split(',')
        if len(parts) != 8:
            return
        serial, x, y, z, w, qx, qy, qz = parts

        msg = PoseStamped()
        msg.header.stamp = self.get_clock().now().to_msg()
        msg.header.frame_id = "world"
        msg.pose.position.x = float(x)
        msg.pose.position.y = float(y)
        msg.pose.position.z = float(z)
        msg.pose.orientation.w = float(w)
        msg.pose.orientation.x = float(qx)
        msg.pose.orientation.y = float(qy)
        msg.pose.orientation.z = float(qz)

        # Only create publisher when tracker connects
        if serial in self.serial_map:
            topic_name = self.serial_map[serial]
            if serial not in self.pubs:
                self.pubs[serial] = self.create_publisher(PoseStamped, topic_name, 10)
                self.get_logger().info(f"Created publisher for {serial} on {topic_name}")
            self.pubs[serial].publish(msg)
        else:
            self.get_logger().warn(f"Unknown serial {serial}, skipping")

def main():
    rclpy.init()
    node = TrackerServer()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()
