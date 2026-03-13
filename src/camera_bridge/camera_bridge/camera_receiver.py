import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Image
from cv_bridge import CvBridge
import socket, pickle, struct

class CameraReceiver(Node):
    def __init__(self):
        super().__init__('camera_receiver')
        self.bridge = CvBridge()
        self.cam_publishers = {}  # one publisher per camera index

        # --- Socket server setup ---
        server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        server_socket.bind(('0.0.0.0', 9001))   # listen on all interfaces
        server_socket.listen(5)
        self.get_logger().info("CameraReceiver listening on port 9001...")
        self.conn, addr = server_socket.accept()
        self.get_logger().info(f"Connection from {addr}")

        # Timer to poll incoming frames
        self.timer = self.create_timer(0.01, self.receive_frame)

    def receive_frame(self):
        try:
            payload_size = struct.calcsize("Q")

            # Read message length
            data = b""
            while len(data) < payload_size:
                packet = self.conn.recv(4096)
                if not packet:
                    return
                data += packet
            msg_size = struct.unpack("Q", data[:payload_size])[0]

            # Read full message
            data = data[payload_size:]
            while len(data) < msg_size:
                packet = self.conn.recv(4096)
                if not packet:
                    return
                data += packet

            cam_index, frame = pickle.loads(data[:msg_size])

            # Create publisher if not exists
            topic_name = f"/camera{cam_index}/image_raw"
            if cam_index not in self.cam_publishers:
                self.cam_publishers[cam_index] = self.create_publisher(Image, topic_name, 10)
                self.get_logger().info(f"Publishing camera {cam_index} to {topic_name}")

            # Convert frame to ROS Image and publish
            ros_img = self.bridge.cv2_to_imgmsg(frame, "bgr8")
            self.cam_publishers[cam_index].publish(ros_img)

        except Exception as e:
            self.get_logger().error(f"Error receiving frame: {e}")


def main():
    rclpy.init()
    node = CameraReceiver()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()
