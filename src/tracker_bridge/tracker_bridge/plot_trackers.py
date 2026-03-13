import rclpy
from rclpy.node import Node
from geometry_msgs.msg import PoseStamped
import matplotlib.pyplot as plt
import time

class TrackerPlot(Node):
    def __init__(self):
        super().__init__('tracker_plot')
        self.last_update = time.time()

        # Candidate topics (you can add/remove here)
        self.topics = [
            '/vive_tracker/tracker1',
            '/vive_tracker/tracker2',
            '/vive_tracker/tracker3'
        ]

        self.colors = ['r', 'g', 'b']
        self.data = {}

        # Create subscriptions for all topics, but only store data when messages arrive
        for topic, color in zip(self.topics, self.colors):
            self.data[topic] = ([], [], [], color)
            self.create_subscription(
                PoseStamped,
                topic,
                lambda msg, t=topic: self.listener_callback(msg, t),
                10
            )

        # Matplotlib setup
        self.fig = plt.figure()
        self.ax = self.fig.add_subplot(111, projection='3d')
        plt.ion()

    def listener_callback(self, msg, topic):
        xs, ys, zs, color = self.data[topic]
        xs.append(msg.pose.position.x)
        ys.append(msg.pose.position.y)
        zs.append(msg.pose.position.z)

        # Update plot, # Only redraw every 0.1s
        if time.time() - self.last_update > 0.1:
            self.ax.clear()
            for t, (xs, ys, zs, color) in self.data.items():
                if xs:  # only plot if we have data
                    self.ax.plot(xs, ys, zs, color=color, marker='o', label=t)
            self.ax.legend()
            plt.pause(0.01)
            self.last_update = time.time()

def main():
    rclpy.init()
    node = TrackerPlot()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
