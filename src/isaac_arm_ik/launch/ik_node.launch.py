from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        Node(
            package='isaac_arm_ik',
            executable='ik_node',
            name='ik_node',
            output='screen'
        )
    ])
