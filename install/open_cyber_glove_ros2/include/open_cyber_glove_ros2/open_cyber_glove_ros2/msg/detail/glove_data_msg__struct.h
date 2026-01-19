// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from open_cyber_glove_ros2:msg/GloveDataMsg.idl
// generated code does not contain a copyright notice

#ifndef OPEN_CYBER_GLOVE_ROS2__MSG__DETAIL__GLOVE_DATA_MSG__STRUCT_H_
#define OPEN_CYBER_GLOVE_ROS2__MSG__DETAIL__GLOVE_DATA_MSG__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.h"

/// Struct defined in msg/GloveDataMsg in the package open_cyber_glove_ros2.
typedef struct open_cyber_glove_ros2__msg__GloveDataMsg
{
  std_msgs__msg__Header header;
  float linear_acceleration[3];
  float angular_velocity[3];
  float temperature;
  int32_t tensile_data[19];
  float joint_angles[22];
  uint32_t timestamp;
} open_cyber_glove_ros2__msg__GloveDataMsg;

// Struct for a sequence of open_cyber_glove_ros2__msg__GloveDataMsg.
typedef struct open_cyber_glove_ros2__msg__GloveDataMsg__Sequence
{
  open_cyber_glove_ros2__msg__GloveDataMsg * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} open_cyber_glove_ros2__msg__GloveDataMsg__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // OPEN_CYBER_GLOVE_ROS2__MSG__DETAIL__GLOVE_DATA_MSG__STRUCT_H_
