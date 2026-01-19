// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from data_recorder_interfaces:srv/StartRecording.idl
// generated code does not contain a copyright notice

#ifndef DATA_RECORDER_INTERFACES__SRV__DETAIL__START_RECORDING__STRUCT_H_
#define DATA_RECORDER_INTERFACES__SRV__DETAIL__START_RECORDING__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'item_type'
// Member 'operator_id'
#include "rosidl_runtime_c/string.h"

/// Struct defined in srv/StartRecording in the package data_recorder_interfaces.
typedef struct data_recorder_interfaces__srv__StartRecording_Request
{
  rosidl_runtime_c__String item_type;
  rosidl_runtime_c__String operator_id;
} data_recorder_interfaces__srv__StartRecording_Request;

// Struct for a sequence of data_recorder_interfaces__srv__StartRecording_Request.
typedef struct data_recorder_interfaces__srv__StartRecording_Request__Sequence
{
  data_recorder_interfaces__srv__StartRecording_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} data_recorder_interfaces__srv__StartRecording_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'message'
// already included above
// #include "rosidl_runtime_c/string.h"

/// Struct defined in srv/StartRecording in the package data_recorder_interfaces.
typedef struct data_recorder_interfaces__srv__StartRecording_Response
{
  bool success;
  rosidl_runtime_c__String message;
} data_recorder_interfaces__srv__StartRecording_Response;

// Struct for a sequence of data_recorder_interfaces__srv__StartRecording_Response.
typedef struct data_recorder_interfaces__srv__StartRecording_Response__Sequence
{
  data_recorder_interfaces__srv__StartRecording_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} data_recorder_interfaces__srv__StartRecording_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // DATA_RECORDER_INTERFACES__SRV__DETAIL__START_RECORDING__STRUCT_H_
