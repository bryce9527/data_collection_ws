from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        Node(
            package='tracker_bridge',
            executable='tracker_server',   # matches console_scripts entry point
            name='tracker_server',
            output='screen',
        ),
        Node(
            package='data_recorder_ros2',
            executable='heartbeat_publisher',
            name='tracker_heartbeat_node',
            output='screen',
            arguments=['tracker1', 'vive_tracker/tracker1', 'geometry_msgs/msg/PoseStamped']
        ),
        Node(
            package='data_recorder_ros2',
            executable='heartbeat_publisher',
            name='tracker_heartbeat_node',
            output='screen',
            arguments=['tracker2', 'vive_tracker/tracker2', 'geometry_msgs/msg/PoseStamped']
        ),
        Node(
            package='data_recorder_ros2',
            executable='heartbeat_publisher',
            name='tracker_heartbeat_node',
            output='screen',
            arguments=['tracker3', 'vive_tracker/tracker3', 'geometry_msgs/msg/PoseStamped']
        ),
    ])
