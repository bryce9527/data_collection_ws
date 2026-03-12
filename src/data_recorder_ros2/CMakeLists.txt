cmake_minimum_required(VERSION 3.5)
project(data_recorder_ros2)

find_package(ament_cmake REQUIRED)
find_package(rosidl_default_generators REQUIRED)

# Generate message bindings
rosidl_generate_interfaces(${PROJECT_NAME}
)

# Install your Python package (this is the missing piece)
ament_python_install_package(${PROJECT_NAME})

ament_export_dependencies(rosidl_default_runtime)
ament_package()