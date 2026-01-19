#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
import serial
from std_msgs.msg import Float32

class AnhengScaleNode(Node):
    def __init__(self):
        super().__init__('anheng_scale_node')
        self.pub = self.create_publisher(Float32, '/scale/weight', 10)
        self.declare_parameter('port', '/dev/scale')
        self.declare_parameter('baud', 9600)
        port = self.get_parameter('port').value
        baud = self.get_parameter('baud').value
        self.get_logger().info('Scale node started, publishing to /scale/weight')

        # Explicit serial config to match minicom
        self.ser = serial.Serial(
            port,
            baudrate=baud,
            timeout=1,
            bytesize=serial.EIGHTBITS,
            parity=serial.PARITY_NONE,
            stopbits=serial.STOPBITS_ONE
        )

        self.last_val = None
        self.timer = self.create_timer(0.05, self.timer_callback)  # 20 Hz

    def timer_callback(self):
        try:
            raw = self.ser.read(64)
            if not raw:
                return

            for chunk in raw.split(b'\r'):
                line = chunk.decode('ascii', errors='ignore').strip()
                if not line:
                    continue

                # Only process stable lines that look like "ST,NT,   120.0 g"
                if line.startswith("ST"):
                    parts = line.split(',')
                    if len(parts) < 3:
                        self.get_logger().debug(f"Ignoring malformed line: {line}")
                        continue

                    weight_field = parts[-1].strip()
                    tokens = weight_field.split()
                    if len(tokens) < 2 or not tokens[0].replace('.', '', 1).isdigit():
                        self.get_logger().debug(f"Ignoring bad weight field: {line}")
                        continue

                    try:
                        weight_val = float(tokens[0])
                    except ValueError:
                        self.get_logger().debug(f"Failed to parse weight from: {line}")
                        continue

                    # Publish only if value changed
                    if weight_val != self.last_val:
                        msg = Float32()
                        msg.data = weight_val
                        self.pub.publish(msg)
                        self.last_val = weight_val
                        self.get_logger().info(f"Stable Weight: {weight_val}")
        except Exception as e:
            self.get_logger().warn(f"Exception while reading scale: {e}")




def main(args=None):
    rclpy.init(args=args)
    node = AnhengScaleNode()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.ser.close()
        node.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()
