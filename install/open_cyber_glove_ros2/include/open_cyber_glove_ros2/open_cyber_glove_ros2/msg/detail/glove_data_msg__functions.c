// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from open_cyber_glove_ros2:msg/GloveDataMsg.idl
// generated code does not contain a copyright notice
#include "open_cyber_glove_ros2/msg/detail/glove_data_msg__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"

bool
open_cyber_glove_ros2__msg__GloveDataMsg__init(open_cyber_glove_ros2__msg__GloveDataMsg * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    open_cyber_glove_ros2__msg__GloveDataMsg__fini(msg);
    return false;
  }
  // linear_acceleration
  // angular_velocity
  // temperature
  // tensile_data
  // joint_angles
  // timestamp
  return true;
}

void
open_cyber_glove_ros2__msg__GloveDataMsg__fini(open_cyber_glove_ros2__msg__GloveDataMsg * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // linear_acceleration
  // angular_velocity
  // temperature
  // tensile_data
  // joint_angles
  // timestamp
}

bool
open_cyber_glove_ros2__msg__GloveDataMsg__are_equal(const open_cyber_glove_ros2__msg__GloveDataMsg * lhs, const open_cyber_glove_ros2__msg__GloveDataMsg * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__are_equal(
      &(lhs->header), &(rhs->header)))
  {
    return false;
  }
  // linear_acceleration
  for (size_t i = 0; i < 3; ++i) {
    if (lhs->linear_acceleration[i] != rhs->linear_acceleration[i]) {
      return false;
    }
  }
  // angular_velocity
  for (size_t i = 0; i < 3; ++i) {
    if (lhs->angular_velocity[i] != rhs->angular_velocity[i]) {
      return false;
    }
  }
  // temperature
  if (lhs->temperature != rhs->temperature) {
    return false;
  }
  // tensile_data
  for (size_t i = 0; i < 19; ++i) {
    if (lhs->tensile_data[i] != rhs->tensile_data[i]) {
      return false;
    }
  }
  // joint_angles
  for (size_t i = 0; i < 22; ++i) {
    if (lhs->joint_angles[i] != rhs->joint_angles[i]) {
      return false;
    }
  }
  // timestamp
  if (lhs->timestamp != rhs->timestamp) {
    return false;
  }
  return true;
}

bool
open_cyber_glove_ros2__msg__GloveDataMsg__copy(
  const open_cyber_glove_ros2__msg__GloveDataMsg * input,
  open_cyber_glove_ros2__msg__GloveDataMsg * output)
{
  if (!input || !output) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__copy(
      &(input->header), &(output->header)))
  {
    return false;
  }
  // linear_acceleration
  for (size_t i = 0; i < 3; ++i) {
    output->linear_acceleration[i] = input->linear_acceleration[i];
  }
  // angular_velocity
  for (size_t i = 0; i < 3; ++i) {
    output->angular_velocity[i] = input->angular_velocity[i];
  }
  // temperature
  output->temperature = input->temperature;
  // tensile_data
  for (size_t i = 0; i < 19; ++i) {
    output->tensile_data[i] = input->tensile_data[i];
  }
  // joint_angles
  for (size_t i = 0; i < 22; ++i) {
    output->joint_angles[i] = input->joint_angles[i];
  }
  // timestamp
  output->timestamp = input->timestamp;
  return true;
}

open_cyber_glove_ros2__msg__GloveDataMsg *
open_cyber_glove_ros2__msg__GloveDataMsg__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  open_cyber_glove_ros2__msg__GloveDataMsg * msg = (open_cyber_glove_ros2__msg__GloveDataMsg *)allocator.allocate(sizeof(open_cyber_glove_ros2__msg__GloveDataMsg), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(open_cyber_glove_ros2__msg__GloveDataMsg));
  bool success = open_cyber_glove_ros2__msg__GloveDataMsg__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
open_cyber_glove_ros2__msg__GloveDataMsg__destroy(open_cyber_glove_ros2__msg__GloveDataMsg * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    open_cyber_glove_ros2__msg__GloveDataMsg__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
open_cyber_glove_ros2__msg__GloveDataMsg__Sequence__init(open_cyber_glove_ros2__msg__GloveDataMsg__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  open_cyber_glove_ros2__msg__GloveDataMsg * data = NULL;

  if (size) {
    data = (open_cyber_glove_ros2__msg__GloveDataMsg *)allocator.zero_allocate(size, sizeof(open_cyber_glove_ros2__msg__GloveDataMsg), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = open_cyber_glove_ros2__msg__GloveDataMsg__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        open_cyber_glove_ros2__msg__GloveDataMsg__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
open_cyber_glove_ros2__msg__GloveDataMsg__Sequence__fini(open_cyber_glove_ros2__msg__GloveDataMsg__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      open_cyber_glove_ros2__msg__GloveDataMsg__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

open_cyber_glove_ros2__msg__GloveDataMsg__Sequence *
open_cyber_glove_ros2__msg__GloveDataMsg__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  open_cyber_glove_ros2__msg__GloveDataMsg__Sequence * array = (open_cyber_glove_ros2__msg__GloveDataMsg__Sequence *)allocator.allocate(sizeof(open_cyber_glove_ros2__msg__GloveDataMsg__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = open_cyber_glove_ros2__msg__GloveDataMsg__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
open_cyber_glove_ros2__msg__GloveDataMsg__Sequence__destroy(open_cyber_glove_ros2__msg__GloveDataMsg__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    open_cyber_glove_ros2__msg__GloveDataMsg__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
open_cyber_glove_ros2__msg__GloveDataMsg__Sequence__are_equal(const open_cyber_glove_ros2__msg__GloveDataMsg__Sequence * lhs, const open_cyber_glove_ros2__msg__GloveDataMsg__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!open_cyber_glove_ros2__msg__GloveDataMsg__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
open_cyber_glove_ros2__msg__GloveDataMsg__Sequence__copy(
  const open_cyber_glove_ros2__msg__GloveDataMsg__Sequence * input,
  open_cyber_glove_ros2__msg__GloveDataMsg__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(open_cyber_glove_ros2__msg__GloveDataMsg);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    open_cyber_glove_ros2__msg__GloveDataMsg * data =
      (open_cyber_glove_ros2__msg__GloveDataMsg *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!open_cyber_glove_ros2__msg__GloveDataMsg__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          open_cyber_glove_ros2__msg__GloveDataMsg__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!open_cyber_glove_ros2__msg__GloveDataMsg__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
