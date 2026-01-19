import sys
if sys.prefix == '/usr':
    sys.real_prefix = sys.prefix
    sys.prefix = sys.exec_prefix = '/home/bryce/ros2_workspace/data_collection_ws/install/data_recorder_ros2'
