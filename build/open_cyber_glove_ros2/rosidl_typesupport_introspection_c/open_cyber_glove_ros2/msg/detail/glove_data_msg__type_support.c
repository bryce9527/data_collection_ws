// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from open_cyber_glove_ros2:msg/GloveDataMsg.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "open_cyber_glove_ros2/msg/detail/glove_data_msg__rosidl_typesupport_introspection_c.h"
#include "open_cyber_glove_ros2/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "open_cyber_glove_ros2/msg/detail/glove_data_msg__functions.h"
#include "open_cyber_glove_ros2/msg/detail/glove_data_msg__struct.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/header.h"
// Member `header`
#include "std_msgs/msg/detail/header__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void open_cyber_glove_ros2__msg__GloveDataMsg__rosidl_typesupport_introspection_c__GloveDataMsg_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  open_cyber_glove_ros2__msg__GloveDataMsg__init(message_memory);
}

void open_cyber_glove_ros2__msg__GloveDataMsg__rosidl_typesupport_introspection_c__GloveDataMsg_fini_function(void * message_memory)
{
  open_cyber_glove_ros2__msg__GloveDataMsg__fini(message_memory);
}

size_t open_cyber_glove_ros2__msg__GloveDataMsg__rosidl_typesupport_introspection_c__size_function__GloveDataMsg__linear_acceleration(
  const void * untyped_member)
{
  (void)untyped_member;
  return 3;
}

const void * open_cyber_glove_ros2__msg__GloveDataMsg__rosidl_typesupport_introspection_c__get_const_function__GloveDataMsg__linear_acceleration(
  const void * untyped_member, size_t index)
{
  const float * member =
    (const float *)(untyped_member);
  return &member[index];
}

void * open_cyber_glove_ros2__msg__GloveDataMsg__rosidl_typesupport_introspection_c__get_function__GloveDataMsg__linear_acceleration(
  void * untyped_member, size_t index)
{
  float * member =
    (float *)(untyped_member);
  return &member[index];
}

void open_cyber_glove_ros2__msg__GloveDataMsg__rosidl_typesupport_introspection_c__fetch_function__GloveDataMsg__linear_acceleration(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const float * item =
    ((const float *)
    open_cyber_glove_ros2__msg__GloveDataMsg__rosidl_typesupport_introspection_c__get_const_function__GloveDataMsg__linear_acceleration(untyped_member, index));
  float * value =
    (float *)(untyped_value);
  *value = *item;
}

void open_cyber_glove_ros2__msg__GloveDataMsg__rosidl_typesupport_introspection_c__assign_function__GloveDataMsg__linear_acceleration(
  void * untyped_member, size_t index, const void * untyped_value)
{
  float * item =
    ((float *)
    open_cyber_glove_ros2__msg__GloveDataMsg__rosidl_typesupport_introspection_c__get_function__GloveDataMsg__linear_acceleration(untyped_member, index));
  const float * value =
    (const float *)(untyped_value);
  *item = *value;
}

size_t open_cyber_glove_ros2__msg__GloveDataMsg__rosidl_typesupport_introspection_c__size_function__GloveDataMsg__angular_velocity(
  const void * untyped_member)
{
  (void)untyped_member;
  return 3;
}

const void * open_cyber_glove_ros2__msg__GloveDataMsg__rosidl_typesupport_introspection_c__get_const_function__GloveDataMsg__angular_velocity(
  const void * untyped_member, size_t index)
{
  const float * member =
    (const float *)(untyped_member);
  return &member[index];
}

void * open_cyber_glove_ros2__msg__GloveDataMsg__rosidl_typesupport_introspection_c__get_function__GloveDataMsg__angular_velocity(
  void * untyped_member, size_t index)
{
  float * member =
    (float *)(untyped_member);
  return &member[index];
}

void open_cyber_glove_ros2__msg__GloveDataMsg__rosidl_typesupport_introspection_c__fetch_function__GloveDataMsg__angular_velocity(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const float * item =
    ((const float *)
    open_cyber_glove_ros2__msg__GloveDataMsg__rosidl_typesupport_introspection_c__get_const_function__GloveDataMsg__angular_velocity(untyped_member, index));
  float * value =
    (float *)(untyped_value);
  *value = *item;
}

void open_cyber_glove_ros2__msg__GloveDataMsg__rosidl_typesupport_introspection_c__assign_function__GloveDataMsg__angular_velocity(
  void * untyped_member, size_t index, const void * untyped_value)
{
  float * item =
    ((float *)
    open_cyber_glove_ros2__msg__GloveDataMsg__rosidl_typesupport_introspection_c__get_function__GloveDataMsg__angular_velocity(untyped_member, index));
  const float * value =
    (const float *)(untyped_value);
  *item = *value;
}

size_t open_cyber_glove_ros2__msg__GloveDataMsg__rosidl_typesupport_introspection_c__size_function__GloveDataMsg__tensile_data(
  const void * untyped_member)
{
  (void)untyped_member;
  return 19;
}

const void * open_cyber_glove_ros2__msg__GloveDataMsg__rosidl_typesupport_introspection_c__get_const_function__GloveDataMsg__tensile_data(
  const void * untyped_member, size_t index)
{
  const int32_t * member =
    (const int32_t *)(untyped_member);
  return &member[index];
}

void * open_cyber_glove_ros2__msg__GloveDataMsg__rosidl_typesupport_introspection_c__get_function__GloveDataMsg__tensile_data(
  void * untyped_member, size_t index)
{
  int32_t * member =
    (int32_t *)(untyped_member);
  return &member[index];
}

void open_cyber_glove_ros2__msg__GloveDataMsg__rosidl_typesupport_introspection_c__fetch_function__GloveDataMsg__tensile_data(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const int32_t * item =
    ((const int32_t *)
    open_cyber_glove_ros2__msg__GloveDataMsg__rosidl_typesupport_introspection_c__get_const_function__GloveDataMsg__tensile_data(untyped_member, index));
  int32_t * value =
    (int32_t *)(untyped_value);
  *value = *item;
}

void open_cyber_glove_ros2__msg__GloveDataMsg__rosidl_typesupport_introspection_c__assign_function__GloveDataMsg__tensile_data(
  void * untyped_member, size_t index, const void * untyped_value)
{
  int32_t * item =
    ((int32_t *)
    open_cyber_glove_ros2__msg__GloveDataMsg__rosidl_typesupport_introspection_c__get_function__GloveDataMsg__tensile_data(untyped_member, index));
  const int32_t * value =
    (const int32_t *)(untyped_value);
  *item = *value;
}

size_t open_cyber_glove_ros2__msg__GloveDataMsg__rosidl_typesupport_introspection_c__size_function__GloveDataMsg__joint_angles(
  const void * untyped_member)
{
  (void)untyped_member;
  return 22;
}

const void * open_cyber_glove_ros2__msg__GloveDataMsg__rosidl_typesupport_introspection_c__get_const_function__GloveDataMsg__joint_angles(
  const void * untyped_member, size_t index)
{
  const float * member =
    (const float *)(untyped_member);
  return &member[index];
}

void * open_cyber_glove_ros2__msg__GloveDataMsg__rosidl_typesupport_introspection_c__get_function__GloveDataMsg__joint_angles(
  void * untyped_member, size_t index)
{
  float * member =
    (float *)(untyped_member);
  return &member[index];
}

void open_cyber_glove_ros2__msg__GloveDataMsg__rosidl_typesupport_introspection_c__fetch_function__GloveDataMsg__joint_angles(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const float * item =
    ((const float *)
    open_cyber_glove_ros2__msg__GloveDataMsg__rosidl_typesupport_introspection_c__get_const_function__GloveDataMsg__joint_angles(untyped_member, index));
  float * value =
    (float *)(untyped_value);
  *value = *item;
}

void open_cyber_glove_ros2__msg__GloveDataMsg__rosidl_typesupport_introspection_c__assign_function__GloveDataMsg__joint_angles(
  void * untyped_member, size_t index, const void * untyped_value)
{
  float * item =
    ((float *)
    open_cyber_glove_ros2__msg__GloveDataMsg__rosidl_typesupport_introspection_c__get_function__GloveDataMsg__joint_angles(untyped_member, index));
  const float * value =
    (const float *)(untyped_value);
  *item = *value;
}

static rosidl_typesupport_introspection_c__MessageMember open_cyber_glove_ros2__msg__GloveDataMsg__rosidl_typesupport_introspection_c__GloveDataMsg_message_member_array[7] = {
  {
    "header",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(open_cyber_glove_ros2__msg__GloveDataMsg, header),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "linear_acceleration",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    3,  // array size
    false,  // is upper bound
    offsetof(open_cyber_glove_ros2__msg__GloveDataMsg, linear_acceleration),  // bytes offset in struct
    NULL,  // default value
    open_cyber_glove_ros2__msg__GloveDataMsg__rosidl_typesupport_introspection_c__size_function__GloveDataMsg__linear_acceleration,  // size() function pointer
    open_cyber_glove_ros2__msg__GloveDataMsg__rosidl_typesupport_introspection_c__get_const_function__GloveDataMsg__linear_acceleration,  // get_const(index) function pointer
    open_cyber_glove_ros2__msg__GloveDataMsg__rosidl_typesupport_introspection_c__get_function__GloveDataMsg__linear_acceleration,  // get(index) function pointer
    open_cyber_glove_ros2__msg__GloveDataMsg__rosidl_typesupport_introspection_c__fetch_function__GloveDataMsg__linear_acceleration,  // fetch(index, &value) function pointer
    open_cyber_glove_ros2__msg__GloveDataMsg__rosidl_typesupport_introspection_c__assign_function__GloveDataMsg__linear_acceleration,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "angular_velocity",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    3,  // array size
    false,  // is upper bound
    offsetof(open_cyber_glove_ros2__msg__GloveDataMsg, angular_velocity),  // bytes offset in struct
    NULL,  // default value
    open_cyber_glove_ros2__msg__GloveDataMsg__rosidl_typesupport_introspection_c__size_function__GloveDataMsg__angular_velocity,  // size() function pointer
    open_cyber_glove_ros2__msg__GloveDataMsg__rosidl_typesupport_introspection_c__get_const_function__GloveDataMsg__angular_velocity,  // get_const(index) function pointer
    open_cyber_glove_ros2__msg__GloveDataMsg__rosidl_typesupport_introspection_c__get_function__GloveDataMsg__angular_velocity,  // get(index) function pointer
    open_cyber_glove_ros2__msg__GloveDataMsg__rosidl_typesupport_introspection_c__fetch_function__GloveDataMsg__angular_velocity,  // fetch(index, &value) function pointer
    open_cyber_glove_ros2__msg__GloveDataMsg__rosidl_typesupport_introspection_c__assign_function__GloveDataMsg__angular_velocity,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "temperature",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(open_cyber_glove_ros2__msg__GloveDataMsg, temperature),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "tensile_data",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    19,  // array size
    false,  // is upper bound
    offsetof(open_cyber_glove_ros2__msg__GloveDataMsg, tensile_data),  // bytes offset in struct
    NULL,  // default value
    open_cyber_glove_ros2__msg__GloveDataMsg__rosidl_typesupport_introspection_c__size_function__GloveDataMsg__tensile_data,  // size() function pointer
    open_cyber_glove_ros2__msg__GloveDataMsg__rosidl_typesupport_introspection_c__get_const_function__GloveDataMsg__tensile_data,  // get_const(index) function pointer
    open_cyber_glove_ros2__msg__GloveDataMsg__rosidl_typesupport_introspection_c__get_function__GloveDataMsg__tensile_data,  // get(index) function pointer
    open_cyber_glove_ros2__msg__GloveDataMsg__rosidl_typesupport_introspection_c__fetch_function__GloveDataMsg__tensile_data,  // fetch(index, &value) function pointer
    open_cyber_glove_ros2__msg__GloveDataMsg__rosidl_typesupport_introspection_c__assign_function__GloveDataMsg__tensile_data,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "joint_angles",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    22,  // array size
    false,  // is upper bound
    offsetof(open_cyber_glove_ros2__msg__GloveDataMsg, joint_angles),  // bytes offset in struct
    NULL,  // default value
    open_cyber_glove_ros2__msg__GloveDataMsg__rosidl_typesupport_introspection_c__size_function__GloveDataMsg__joint_angles,  // size() function pointer
    open_cyber_glove_ros2__msg__GloveDataMsg__rosidl_typesupport_introspection_c__get_const_function__GloveDataMsg__joint_angles,  // get_const(index) function pointer
    open_cyber_glove_ros2__msg__GloveDataMsg__rosidl_typesupport_introspection_c__get_function__GloveDataMsg__joint_angles,  // get(index) function pointer
    open_cyber_glove_ros2__msg__GloveDataMsg__rosidl_typesupport_introspection_c__fetch_function__GloveDataMsg__joint_angles,  // fetch(index, &value) function pointer
    open_cyber_glove_ros2__msg__GloveDataMsg__rosidl_typesupport_introspection_c__assign_function__GloveDataMsg__joint_angles,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "timestamp",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(open_cyber_glove_ros2__msg__GloveDataMsg, timestamp),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers open_cyber_glove_ros2__msg__GloveDataMsg__rosidl_typesupport_introspection_c__GloveDataMsg_message_members = {
  "open_cyber_glove_ros2__msg",  // message namespace
  "GloveDataMsg",  // message name
  7,  // number of fields
  sizeof(open_cyber_glove_ros2__msg__GloveDataMsg),
  open_cyber_glove_ros2__msg__GloveDataMsg__rosidl_typesupport_introspection_c__GloveDataMsg_message_member_array,  // message members
  open_cyber_glove_ros2__msg__GloveDataMsg__rosidl_typesupport_introspection_c__GloveDataMsg_init_function,  // function to initialize message memory (memory has to be allocated)
  open_cyber_glove_ros2__msg__GloveDataMsg__rosidl_typesupport_introspection_c__GloveDataMsg_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t open_cyber_glove_ros2__msg__GloveDataMsg__rosidl_typesupport_introspection_c__GloveDataMsg_message_type_support_handle = {
  0,
  &open_cyber_glove_ros2__msg__GloveDataMsg__rosidl_typesupport_introspection_c__GloveDataMsg_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_open_cyber_glove_ros2
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, open_cyber_glove_ros2, msg, GloveDataMsg)() {
  open_cyber_glove_ros2__msg__GloveDataMsg__rosidl_typesupport_introspection_c__GloveDataMsg_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, std_msgs, msg, Header)();
  if (!open_cyber_glove_ros2__msg__GloveDataMsg__rosidl_typesupport_introspection_c__GloveDataMsg_message_type_support_handle.typesupport_identifier) {
    open_cyber_glove_ros2__msg__GloveDataMsg__rosidl_typesupport_introspection_c__GloveDataMsg_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &open_cyber_glove_ros2__msg__GloveDataMsg__rosidl_typesupport_introspection_c__GloveDataMsg_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
