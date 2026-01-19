from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        Node(
            package='data_recorder_ros2',
            executable='anheng_scale_node',   # matches console_scripts entry point
            name='anheng_scale_node',
            output='screen',
            parameters=[{
                'port': '/dev/scale',
                'baud': 9600,
                'mode': 'stable',
                'debug': False,
            }]
        ),
        Node(
            package='data_recorder_ros2',
            executable='heartbeat_publisher',
            name='scale_heartbeat_node',
            output='screen',
            arguments=['scale', '/scale/weight', 'std_msgs/Float32']
        )
    ])
