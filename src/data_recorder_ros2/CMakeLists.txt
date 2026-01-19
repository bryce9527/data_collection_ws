cmake_minimum_required(VERSION 3.5)
project(data_recorder_ros2)

find_package(ament_cmake REQUIRED)
find_package(rosidl_default_generators REQUIRED)

# Generate service code
rosidl_generate_interfaces(${PROJECT_NAME}

)

ament_export_dependencies(rosidl_default_runtime)
ament_package()
