import sys
if sys.prefix == '/usr':
    sys.real_prefix = sys.prefix
    sys.prefix = sys.exec_prefix = '/home/bryce/ros2_workspace/data_collection_ws/install/open_cyber_glove_ros2'
