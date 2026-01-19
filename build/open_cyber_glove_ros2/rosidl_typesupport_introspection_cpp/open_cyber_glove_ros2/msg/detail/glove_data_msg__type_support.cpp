// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from open_cyber_glove_ros2:msg/GloveDataMsg.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "open_cyber_glove_ros2/msg/detail/glove_data_msg__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace open_cyber_glove_ros2
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void GloveDataMsg_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) open_cyber_glove_ros2::msg::GloveDataMsg(_init);
}

void GloveDataMsg_fini_function(void * message_memory)
{
  auto typed_message = static_cast<open_cyber_glove_ros2::msg::GloveDataMsg *>(message_memory);
  typed_message->~GloveDataMsg();
}

size_t size_function__GloveDataMsg__linear_acceleration(const void * untyped_member)
{
  (void)untyped_member;
  return 3;
}

const void * get_const_function__GloveDataMsg__linear_acceleration(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::array<float, 3> *>(untyped_member);
  return &member[index];
}

void * get_function__GloveDataMsg__linear_acceleration(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::array<float, 3> *>(untyped_member);
  return &member[index];
}

void fetch_function__GloveDataMsg__linear_acceleration(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const float *>(
    get_const_function__GloveDataMsg__linear_acceleration(untyped_member, index));
  auto & value = *reinterpret_cast<float *>(untyped_value);
  value = item;
}

void assign_function__GloveDataMsg__linear_acceleration(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<float *>(
    get_function__GloveDataMsg__linear_acceleration(untyped_member, index));
  const auto & value = *reinterpret_cast<const float *>(untyped_value);
  item = value;
}

size_t size_function__GloveDataMsg__angular_velocity(const void * untyped_member)
{
  (void)untyped_member;
  return 3;
}

const void * get_const_function__GloveDataMsg__angular_velocity(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::array<float, 3> *>(untyped_member);
  return &member[index];
}

void * get_function__GloveDataMsg__angular_velocity(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::array<float, 3> *>(untyped_member);
  return &member[index];
}

void fetch_function__GloveDataMsg__angular_velocity(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const float *>(
    get_const_function__GloveDataMsg__angular_velocity(untyped_member, index));
  auto & value = *reinterpret_cast<float *>(untyped_value);
  value = item;
}

void assign_function__GloveDataMsg__angular_velocity(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<float *>(
    get_function__GloveDataMsg__angular_velocity(untyped_member, index));
  const auto & value = *reinterpret_cast<const float *>(untyped_value);
  item = value;
}

size_t size_function__GloveDataMsg__tensile_data(const void * untyped_member)
{
  (void)untyped_member;
  return 19;
}

const void * get_const_function__GloveDataMsg__tensile_data(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::array<int32_t, 19> *>(untyped_member);
  return &member[index];
}

void * get_function__GloveDataMsg__tensile_data(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::array<int32_t, 19> *>(untyped_member);
  return &member[index];
}

void fetch_function__GloveDataMsg__tensile_data(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const int32_t *>(
    get_const_function__GloveDataMsg__tensile_data(untyped_member, index));
  auto & value = *reinterpret_cast<int32_t *>(untyped_value);
  value = item;
}

void assign_function__GloveDataMsg__tensile_data(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<int32_t *>(
    get_function__GloveDataMsg__tensile_data(untyped_member, index));
  const auto & value = *reinterpret_cast<const int32_t *>(untyped_value);
  item = value;
}

size_t size_function__GloveDataMsg__joint_angles(const void * untyped_member)
{
  (void)untyped_member;
  return 22;
}

const void * get_const_function__GloveDataMsg__joint_angles(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::array<float, 22> *>(untyped_member);
  return &member[index];
}

void * get_function__GloveDataMsg__joint_angles(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::array<float, 22> *>(untyped_member);
  return &member[index];
}

void fetch_function__GloveDataMsg__joint_angles(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const float *>(
    get_const_function__GloveDataMsg__joint_angles(untyped_member, index));
  auto & value = *reinterpret_cast<float *>(untyped_value);
  value = item;
}

void assign_function__GloveDataMsg__joint_angles(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<float *>(
    get_function__GloveDataMsg__joint_angles(untyped_member, index));
  const auto & value = *reinterpret_cast<const float *>(untyped_value);
  item = value;
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember GloveDataMsg_message_member_array[7] = {
  {
    "header",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<std_msgs::msg::Header>(),  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(open_cyber_glove_ros2::msg::GloveDataMsg, header),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "linear_acceleration",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    3,  // array size
    false,  // is upper bound
    offsetof(open_cyber_glove_ros2::msg::GloveDataMsg, linear_acceleration),  // bytes offset in struct
    nullptr,  // default value
    size_function__GloveDataMsg__linear_acceleration,  // size() function pointer
    get_const_function__GloveDataMsg__linear_acceleration,  // get_const(index) function pointer
    get_function__GloveDataMsg__linear_acceleration,  // get(index) function pointer
    fetch_function__GloveDataMsg__linear_acceleration,  // fetch(index, &value) function pointer
    assign_function__GloveDataMsg__linear_acceleration,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "angular_velocity",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    3,  // array size
    false,  // is upper bound
    offsetof(open_cyber_glove_ros2::msg::GloveDataMsg, angular_velocity),  // bytes offset in struct
    nullptr,  // default value
    size_function__GloveDataMsg__angular_velocity,  // size() function pointer
    get_const_function__GloveDataMsg__angular_velocity,  // get_const(index) function pointer
    get_function__GloveDataMsg__angular_velocity,  // get(index) function pointer
    fetch_function__GloveDataMsg__angular_velocity,  // fetch(index, &value) function pointer
    assign_function__GloveDataMsg__angular_velocity,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "temperature",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(open_cyber_glove_ros2::msg::GloveDataMsg, temperature),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "tensile_data",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    19,  // array size
    false,  // is upper bound
    offsetof(open_cyber_glove_ros2::msg::GloveDataMsg, tensile_data),  // bytes offset in struct
    nullptr,  // default value
    size_function__GloveDataMsg__tensile_data,  // size() function pointer
    get_const_function__GloveDataMsg__tensile_data,  // get_const(index) function pointer
    get_function__GloveDataMsg__tensile_data,  // get(index) function pointer
    fetch_function__GloveDataMsg__tensile_data,  // fetch(index, &value) function pointer
    assign_function__GloveDataMsg__tensile_data,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "joint_angles",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    22,  // array size
    false,  // is upper bound
    offsetof(open_cyber_glove_ros2::msg::GloveDataMsg, joint_angles),  // bytes offset in struct
    nullptr,  // default value
    size_function__GloveDataMsg__joint_angles,  // size() function pointer
    get_const_function__GloveDataMsg__joint_angles,  // get_const(index) function pointer
    get_function__GloveDataMsg__joint_angles,  // get(index) function pointer
    fetch_function__GloveDataMsg__joint_angles,  // fetch(index, &value) function pointer
    assign_function__GloveDataMsg__joint_angles,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "timestamp",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_UINT32,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(open_cyber_glove_ros2::msg::GloveDataMsg, timestamp),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers GloveDataMsg_message_members = {
  "open_cyber_glove_ros2::msg",  // message namespace
  "GloveDataMsg",  // message name
  7,  // number of fields
  sizeof(open_cyber_glove_ros2::msg::GloveDataMsg),
  GloveDataMsg_message_member_array,  // message members
  GloveDataMsg_init_function,  // function to initialize message memory (memory has to be allocated)
  GloveDataMsg_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t GloveDataMsg_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &GloveDataMsg_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace open_cyber_glove_ros2


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<open_cyber_glove_ros2::msg::GloveDataMsg>()
{
  return &::open_cyber_glove_ros2::msg::rosidl_typesupport_introspection_cpp::GloveDataMsg_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, open_cyber_glove_ros2, msg, GloveDataMsg)() {
  return &::open_cyber_glove_ros2::msg::rosidl_typesupport_introspection_cpp::GloveDataMsg_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
