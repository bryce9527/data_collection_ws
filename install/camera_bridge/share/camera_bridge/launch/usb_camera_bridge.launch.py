from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        Node(
            package='camera_bridge',
            executable='camera_receiver',   # matches console_scripts entry point
            name='camera_receiver',
            output='screen',
        ),
        Node(
            package='data_recorder_ros2',
            executable='heartbeat_publisher',
            name='camera_heartbeat_node',
            output='screen',
            arguments=['usb_camera1', '/scale/weight', 'std_msgs/Float32']
        )
    ])
