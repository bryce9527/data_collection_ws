from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node

def generate_launch_description():
    # Declare arguments
    rate_hz = LaunchConfiguration('rate_hz')
    left_port = LaunchConfiguration('left_port')
    right_port = LaunchConfiguration('right_port')
    mode = LaunchConfiguration('mode')
    calib_file = LaunchConfiguration('calib_file')

    return LaunchDescription([
        DeclareLaunchArgument(
            'rate_hz', default_value='50.0',
            description='Publishing rate in Hz'
        ),
        DeclareLaunchArgument(
            'left_port', default_value='/dev/cyberglove_left',
            description='Left glove serial port'
        ),
        DeclareLaunchArgument(
            'right_port', default_value='/dev/cyberglove_right',
            description='Right glove serial port'
        ),
        DeclareLaunchArgument(
            'mode', default_value='load',
            description='Calibration mode: calibrate or load'
        ),
        DeclareLaunchArgument(
            'calib_file',
            default_value='/home/bryce/master_robotics_ws/src/open_cyber_glove/calibration/glove_calibration.json',
            description='Calibration file path'
        ),

        # Glove joint state dual publisher
        Node(
            package='open_cyber_glove_ros2',
            executable='glove_joint_state_dual_publisher',
            name='glove_joint_state_dual_publisher',
            output='screen',
            parameters=[{
                'rate_hz': rate_hz,
                'left_port': left_port,
                'right_port': right_port,
                'mode': mode,
                'calib_file': calib_file,
            }]
        ),

        # Heartbeat publishers
        Node(
            package='data_recorder_ros2',
            executable='heartbeat_publisher',
            name='glove_left_heartbeat_node',
            output='screen',
            arguments=['glove_left', '/glove_left/joint_states', 'sensor_msgs/JointState']
        ),
        Node(
            package='data_recorder_ros2',
            executable='heartbeat_publisher',
            name='glove_right_heartbeat_node',
            output='screen',
            arguments=['glove_right', '/glove_right/joint_states', 'sensor_msgs/JointState']
        ),
    ])
