from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        Node(
            package='data_recorder_ros2',
            executable='recorder_service',
            name='recorder_service',
            output='screen',
            parameters=[{
                'save_dir': '/home/bryce/rosbags',
                'topics': (
                    '/glove_left/joint_states '
                    '/glove_right/joint_states '
                    '/d435i/d435i_camera/color/image_raw '
                    '/d435i/d435i_camera/depth/image_rect_raw '
                    '/d415/d415_camera/color/image_raw '
                    '/d415/d415_camera/aligned_depth_to_color/image_raw'
                )
            }]
        )
    ])
