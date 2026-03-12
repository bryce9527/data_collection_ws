// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from data_recorder_interfaces:msg/Float32Stamped.idl
// generated code does not contain a copyright notice

#ifndef DATA_RECORDER_INTERFACES__MSG__DETAIL__FLOAT32_STAMPED__STRUCT_H_
#define DATA_RECORDER_INTERFACES__MSG__DETAIL__FLOAT32_STAMPED__STRUCT_H_

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

/// Struct defined in msg/Float32Stamped in the package data_recorder_interfaces.
typedef struct data_recorder_interfaces__msg__Float32Stamped
{
  std_msgs__msg__Header header;
  float data;
} data_recorder_interfaces__msg__Float32Stamped;

// Struct for a sequence of data_recorder_interfaces__msg__Float32Stamped.
typedef struct data_recorder_interfaces__msg__Float32Stamped__Sequence
{
  data_recorder_interfaces__msg__Float32Stamped * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} data_recorder_interfaces__msg__Float32Stamped__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // DATA_RECORDER_INTERFACES__MSG__DETAIL__FLOAT32_STAMPED__STRUCT_H_
