from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        # D415 Camera
        Node(
            package='realsense2_camera',
            executable='realsense2_camera_node',
            namespace='d415',
            name='d415_camera',
            output='screen',
            parameters=[{
                'serial_no': '126222060276',
                'use_device_time': True,
                'tf_prefix': 'd415',
                'enable_color': True,
                'enable_depth.': True,
                'enable_infra1': True,
                'enable_infra2': True,
                'enable_pointcloud': True,
                'align_depth.enable': True,
                'enable_sync': True,
                'enable_gyro': False,
                'enable_accel': False,
                'color_width': 640,
                'color_height': 480,
                'color_fps': 30,
            }]
        ),

        # D435i Camera
        Node(
            package='realsense2_camera',
            executable='realsense2_camera_node',
            namespace='d435i',
            name='d435i_camera',
            output='screen',
            parameters=[{
                'serial_no': '215222076232',
                'use_device_time': True,
                'tf_prefix': 'd435i',
                'enable_color': True,
                'enable_depth': True,
                'enable_infra1': True,
                'enable_infra2': True,
                'enable_pointcloud': True,
                'align_depth.enable': True,
                'enable_sync': True,
                'enable_gyro': False,
                'enable_accel': False,
                'color_width': 640,
                'color_height': 480,
                'color_fps': 30,
            }]
        ),

        # Heartbeat publishers
        Node(
            package='data_recorder_ros2',
            executable='heartbeat_publisher',
            name='d435i_heartbeat_node',
            output='screen',
            arguments=['d435i', '/d435i/d435i_camera/color/image_raw', 'sensor_msgs/msg/Image']
        ),
        Node(
            package='data_recorder_ros2',
            executable='heartbeat_publisher',
            name='d415_heartbeat_node',
            output='screen',
            arguments=['d415', '/d415/d415_camera/color/image_raw', 'sensor_msgs/msg/Image']
        ),
    ])
