from launch import LaunchDescription
from launch_ros.actions import Node
import os

def generate_launch_description():
    return LaunchDescription([
        Node(
            package='v4l2_camera',
            executable='v4l2_camera_node',
            name='camera1',
            output='screen',
            parameters=[os.path.join(
                os.path.dirname(__file__), '..', 'config', 'camera1.yaml')],
            remappings=[('/image_raw', '/camera1/image_raw'),
                        ('/camera_info', '/camera1/camera_info')]
        ),
        Node(
            package='v4l2_camera',
            executable='v4l2_camera_node',
            name='camera2',
            output='screen',
            parameters=[os.path.join(
                os.path.dirname(__file__), '..', 'config', 'camera2.yaml')],
            remappings=[('/image_raw', '/camera2/image_raw'),
                        ('/camera_info', '/camera2/camera_info')]
        )
    ])
