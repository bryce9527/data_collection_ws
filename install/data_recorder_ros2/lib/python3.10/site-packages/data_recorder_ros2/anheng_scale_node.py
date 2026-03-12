#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
import serial
from data_recorder_interfaces.msg import Float32Stamped

class AnhengScaleNode(Node):
    def __init__(self):
        super().__init__('anheng_scale_node')

        # Publishers
        self.pub_event = self.create_publisher(Float32Stamped, '/scale/weight_event', 10)
        self.pub_stream = self.create_publisher(Float32Stamped, '/scale/weight_stream', 10)

        # Parameters
        self.declare_parameter('port', '/dev/scale')
        self.declare_parameter('baud', 9600)
        port = self.get_parameter('port').value
        baud = self.get_parameter('baud').value
        self.get_logger().info('Scale node started, publishing to /scale/weight_event and /scale/weight_stream')

        # Serial config
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

                # Only process stable lines like "ST,NT,   120.0 g"
                if line.startswith("ST"):
                    parts = line.split(',')
                    if len(parts) < 3:
                        continue

                    weight_field = parts[-1].strip()
                    tokens = weight_field.split()
                    if len(tokens) < 2 or not tokens[0].replace('.', '', 1).isdigit():
                        continue

                    try:
                        weight_val = float(tokens[0])
                    except ValueError:
                        continue

                    # Build message with timestamp
                    msg = Float32Stamped()
                    msg.header.stamp = self.get_clock().now().to_msg()
                    msg.data = weight_val

                    # Event-based publishing (only when value changes)
                    if weight_val != self.last_val:
                        self.pub_event.publish(msg)
                        self.get_logger().info(f"Weight changed: {weight_val}")
                        self.last_val = weight_val

                    # Continuous stream publishing (always publish last value)
                    self.pub_stream.publish(msg)

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