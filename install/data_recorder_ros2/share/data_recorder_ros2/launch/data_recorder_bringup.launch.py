from launch import LaunchDescription
from launch.actions import IncludeLaunchDescription
from launch.launch_description_sources import (
    PythonLaunchDescriptionSource,
    FrontendLaunchDescriptionSource
)
from ament_index_python.packages import get_package_share_directory
import os


def generate_launch_description():
    return LaunchDescription([
        IncludeLaunchDescription(
            FrontendLaunchDescriptionSource(
                os.path.join(
                    get_package_share_directory('rosbridge_server'),
                    'launch',
                    'rosbridge_websocket_launch.xml'   # rosbridge uses XML launch files
                )
            ),
            launch_arguments={'allow_origin': '*'}.items()
        ),
        IncludeLaunchDescription(
            PythonLaunchDescriptionSource(
                os.path.join(
                    get_package_share_directory('data_recorder_ros2'),
                    'launch',
                    'rs_d435i.launch.py'
                )
            )
        ),
        IncludeLaunchDescription(
            PythonLaunchDescriptionSource(
                os.path.join(
                    get_package_share_directory('open_cyber_glove_ros2'),
                    'launch',
                    'glove_joint_state_heartbeat_publisher.launch.py'
                )
            )
        ),
        IncludeLaunchDescription(
            PythonLaunchDescriptionSource(
                os.path.join(
                    get_package_share_directory('data_recorder_ros2'),
                    'launch',
                    'scale.launch.py'
                )
            )
        ),
        IncludeLaunchDescription(
            PythonLaunchDescriptionSource(
                os.path.join(
                    get_package_share_directory('data_recorder_ros2'),
                    'launch',
                    'recorder.launch.py'
                )
            )
        ),
        # IncludeLaunchDescription(
        #     PythonLaunchDescriptionSource(
        #         os.path.join(
        #             get_package_share_directory('camera_bridge'),
        #             'launch',
        #             'usb_camera_bridge.launch.py'
        #         )
        #     )
        # ),
        IncludeLaunchDescription(
            PythonLaunchDescriptionSource(
                os.path.join(
                    get_package_share_directory('tracker_bridge'),
                    'launch',
                    'tracker_bridge.launch.py'
                )
            )
        ),
    ])
