// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from open_cyber_glove_ros2:msg/GloveDataMsg.idl
// generated code does not contain a copyright notice

#ifndef OPEN_CYBER_GLOVE_ROS2__MSG__DETAIL__GLOVE_DATA_MSG__BUILDER_HPP_
#define OPEN_CYBER_GLOVE_ROS2__MSG__DETAIL__GLOVE_DATA_MSG__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "open_cyber_glove_ros2/msg/detail/glove_data_msg__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace open_cyber_glove_ros2
{

namespace msg
{

namespace builder
{

class Init_GloveDataMsg_timestamp
{
public:
  explicit Init_GloveDataMsg_timestamp(::open_cyber_glove_ros2::msg::GloveDataMsg & msg)
  : msg_(msg)
  {}
  ::open_cyber_glove_ros2::msg::GloveDataMsg timestamp(::open_cyber_glove_ros2::msg::GloveDataMsg::_timestamp_type arg)
  {
    msg_.timestamp = std::move(arg);
    return std::move(msg_);
  }

private:
  ::open_cyber_glove_ros2::msg::GloveDataMsg msg_;
};

class Init_GloveDataMsg_joint_angles
{
public:
  explicit Init_GloveDataMsg_joint_angles(::open_cyber_glove_ros2::msg::GloveDataMsg & msg)
  : msg_(msg)
  {}
  Init_GloveDataMsg_timestamp joint_angles(::open_cyber_glove_ros2::msg::GloveDataMsg::_joint_angles_type arg)
  {
    msg_.joint_angles = std::move(arg);
    return Init_GloveDataMsg_timestamp(msg_);
  }

private:
  ::open_cyber_glove_ros2::msg::GloveDataMsg msg_;
};

class Init_GloveDataMsg_tensile_data
{
public:
  explicit Init_GloveDataMsg_tensile_data(::open_cyber_glove_ros2::msg::GloveDataMsg & msg)
  : msg_(msg)
  {}
  Init_GloveDataMsg_joint_angles tensile_data(::open_cyber_glove_ros2::msg::GloveDataMsg::_tensile_data_type arg)
  {
    msg_.tensile_data = std::move(arg);
    return Init_GloveDataMsg_joint_angles(msg_);
  }

private:
  ::open_cyber_glove_ros2::msg::GloveDataMsg msg_;
};

class Init_GloveDataMsg_temperature
{
public:
  explicit Init_GloveDataMsg_temperature(::open_cyber_glove_ros2::msg::GloveDataMsg & msg)
  : msg_(msg)
  {}
  Init_GloveDataMsg_tensile_data temperature(::open_cyber_glove_ros2::msg::GloveDataMsg::_temperature_type arg)
  {
    msg_.temperature = std::move(arg);
    return Init_GloveDataMsg_tensile_data(msg_);
  }

private:
  ::open_cyber_glove_ros2::msg::GloveDataMsg msg_;
};

class Init_GloveDataMsg_angular_velocity
{
public:
  explicit Init_GloveDataMsg_angular_velocity(::open_cyber_glove_ros2::msg::GloveDataMsg & msg)
  : msg_(msg)
  {}
  Init_GloveDataMsg_temperature angular_velocity(::open_cyber_glove_ros2::msg::GloveDataMsg::_angular_velocity_type arg)
  {
    msg_.angular_velocity = std::move(arg);
    return Init_GloveDataMsg_temperature(msg_);
  }

private:
  ::open_cyber_glove_ros2::msg::GloveDataMsg msg_;
};

class Init_GloveDataMsg_linear_acceleration
{
public:
  explicit Init_GloveDataMsg_linear_acceleration(::open_cyber_glove_ros2::msg::GloveDataMsg & msg)
  : msg_(msg)
  {}
  Init_GloveDataMsg_angular_velocity linear_acceleration(::open_cyber_glove_ros2::msg::GloveDataMsg::_linear_acceleration_type arg)
  {
    msg_.linear_acceleration = std::move(arg);
    return Init_GloveDataMsg_angular_velocity(msg_);
  }

private:
  ::open_cyber_glove_ros2::msg::GloveDataMsg msg_;
};

class Init_GloveDataMsg_header
{
public:
  Init_GloveDataMsg_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_GloveDataMsg_linear_acceleration header(::open_cyber_glove_ros2::msg::GloveDataMsg::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_GloveDataMsg_linear_acceleration(msg_);
  }

private:
  ::open_cyber_glove_ros2::msg::GloveDataMsg msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::open_cyber_glove_ros2::msg::GloveDataMsg>()
{
  return open_cyber_glove_ros2::msg::builder::Init_GloveDataMsg_header();
}

}  // namespace open_cyber_glove_ros2

#endif  // OPEN_CYBER_GLOVE_ROS2__MSG__DETAIL__GLOVE_DATA_MSG__BUILDER_HPP_
