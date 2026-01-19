// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__rosidl_typesupport_fastrtps_cpp.hpp.em
// with input from open_cyber_glove_ros2:msg/GloveDataMsg.idl
// generated code does not contain a copyright notice

#ifndef OPEN_CYBER_GLOVE_ROS2__MSG__DETAIL__GLOVE_DATA_MSG__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
#define OPEN_CYBER_GLOVE_ROS2__MSG__DETAIL__GLOVE_DATA_MSG__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_

#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_interface/macros.h"
#include "open_cyber_glove_ros2/msg/rosidl_typesupport_fastrtps_cpp__visibility_control.h"
#include "open_cyber_glove_ros2/msg/detail/glove_data_msg__struct.hpp"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

#include "fastcdr/Cdr.h"

namespace open_cyber_glove_ros2
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_open_cyber_glove_ros2
cdr_serialize(
  const open_cyber_glove_ros2::msg::GloveDataMsg & ros_message,
  eprosima::fastcdr::Cdr & cdr);

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_open_cyber_glove_ros2
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  open_cyber_glove_ros2::msg::GloveDataMsg & ros_message);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_open_cyber_glove_ros2
get_serialized_size(
  const open_cyber_glove_ros2::msg::GloveDataMsg & ros_message,
  size_t current_alignment);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_open_cyber_glove_ros2
max_serialized_size_GloveDataMsg(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace open_cyber_glove_ros2

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_open_cyber_glove_ros2
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, open_cyber_glove_ros2, msg, GloveDataMsg)();

#ifdef __cplusplus
}
#endif

#endif  // OPEN_CYBER_GLOVE_ROS2__MSG__DETAIL__GLOVE_DATA_MSG__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
