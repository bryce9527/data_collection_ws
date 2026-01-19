// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from open_cyber_glove_ros2:msg/GloveDataMsg.idl
// generated code does not contain a copyright notice

#ifndef OPEN_CYBER_GLOVE_ROS2__MSG__DETAIL__GLOVE_DATA_MSG__FUNCTIONS_H_
#define OPEN_CYBER_GLOVE_ROS2__MSG__DETAIL__GLOVE_DATA_MSG__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "open_cyber_glove_ros2/msg/rosidl_generator_c__visibility_control.h"

#include "open_cyber_glove_ros2/msg/detail/glove_data_msg__struct.h"

/// Initialize msg/GloveDataMsg message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * open_cyber_glove_ros2__msg__GloveDataMsg
 * )) before or use
 * open_cyber_glove_ros2__msg__GloveDataMsg__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_open_cyber_glove_ros2
bool
open_cyber_glove_ros2__msg__GloveDataMsg__init(open_cyber_glove_ros2__msg__GloveDataMsg * msg);

/// Finalize msg/GloveDataMsg message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_open_cyber_glove_ros2
void
open_cyber_glove_ros2__msg__GloveDataMsg__fini(open_cyber_glove_ros2__msg__GloveDataMsg * msg);

/// Create msg/GloveDataMsg message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * open_cyber_glove_ros2__msg__GloveDataMsg__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_open_cyber_glove_ros2
open_cyber_glove_ros2__msg__GloveDataMsg *
open_cyber_glove_ros2__msg__GloveDataMsg__create();

/// Destroy msg/GloveDataMsg message.
/**
 * It calls
 * open_cyber_glove_ros2__msg__GloveDataMsg__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_open_cyber_glove_ros2
void
open_cyber_glove_ros2__msg__GloveDataMsg__destroy(open_cyber_glove_ros2__msg__GloveDataMsg * msg);

/// Check for msg/GloveDataMsg message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_open_cyber_glove_ros2
bool
open_cyber_glove_ros2__msg__GloveDataMsg__are_equal(const open_cyber_glove_ros2__msg__GloveDataMsg * lhs, const open_cyber_glove_ros2__msg__GloveDataMsg * rhs);

/// Copy a msg/GloveDataMsg message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_open_cyber_glove_ros2
bool
open_cyber_glove_ros2__msg__GloveDataMsg__copy(
  const open_cyber_glove_ros2__msg__GloveDataMsg * input,
  open_cyber_glove_ros2__msg__GloveDataMsg * output);

/// Initialize array of msg/GloveDataMsg messages.
/**
 * It allocates the memory for the number of elements and calls
 * open_cyber_glove_ros2__msg__GloveDataMsg__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_open_cyber_glove_ros2
bool
open_cyber_glove_ros2__msg__GloveDataMsg__Sequence__init(open_cyber_glove_ros2__msg__GloveDataMsg__Sequence * array, size_t size);

/// Finalize array of msg/GloveDataMsg messages.
/**
 * It calls
 * open_cyber_glove_ros2__msg__GloveDataMsg__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_open_cyber_glove_ros2
void
open_cyber_glove_ros2__msg__GloveDataMsg__Sequence__fini(open_cyber_glove_ros2__msg__GloveDataMsg__Sequence * array);

/// Create array of msg/GloveDataMsg messages.
/**
 * It allocates the memory for the array and calls
 * open_cyber_glove_ros2__msg__GloveDataMsg__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_open_cyber_glove_ros2
open_cyber_glove_ros2__msg__GloveDataMsg__Sequence *
open_cyber_glove_ros2__msg__GloveDataMsg__Sequence__create(size_t size);

/// Destroy array of msg/GloveDataMsg messages.
/**
 * It calls
 * open_cyber_glove_ros2__msg__GloveDataMsg__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_open_cyber_glove_ros2
void
open_cyber_glove_ros2__msg__GloveDataMsg__Sequence__destroy(open_cyber_glove_ros2__msg__GloveDataMsg__Sequence * array);

/// Check for msg/GloveDataMsg message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_open_cyber_glove_ros2
bool
open_cyber_glove_ros2__msg__GloveDataMsg__Sequence__are_equal(const open_cyber_glove_ros2__msg__GloveDataMsg__Sequence * lhs, const open_cyber_glove_ros2__msg__GloveDataMsg__Sequence * rhs);

/// Copy an array of msg/GloveDataMsg messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_open_cyber_glove_ros2
bool
open_cyber_glove_ros2__msg__GloveDataMsg__Sequence__copy(
  const open_cyber_glove_ros2__msg__GloveDataMsg__Sequence * input,
  open_cyber_glove_ros2__msg__GloveDataMsg__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // OPEN_CYBER_GLOVE_ROS2__MSG__DETAIL__GLOVE_DATA_MSG__FUNCTIONS_H_
