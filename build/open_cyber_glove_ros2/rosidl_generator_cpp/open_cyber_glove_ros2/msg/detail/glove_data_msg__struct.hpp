// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from open_cyber_glove_ros2:msg/GloveDataMsg.idl
// generated code does not contain a copyright notice

#ifndef OPEN_CYBER_GLOVE_ROS2__MSG__DETAIL__GLOVE_DATA_MSG__STRUCT_HPP_
#define OPEN_CYBER_GLOVE_ROS2__MSG__DETAIL__GLOVE_DATA_MSG__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__open_cyber_glove_ros2__msg__GloveDataMsg __attribute__((deprecated))
#else
# define DEPRECATED__open_cyber_glove_ros2__msg__GloveDataMsg __declspec(deprecated)
#endif

namespace open_cyber_glove_ros2
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct GloveDataMsg_
{
  using Type = GloveDataMsg_<ContainerAllocator>;

  explicit GloveDataMsg_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      std::fill<typename std::array<float, 3>::iterator, float>(this->linear_acceleration.begin(), this->linear_acceleration.end(), 0.0f);
      std::fill<typename std::array<float, 3>::iterator, float>(this->angular_velocity.begin(), this->angular_velocity.end(), 0.0f);
      this->temperature = 0.0f;
      std::fill<typename std::array<int32_t, 19>::iterator, int32_t>(this->tensile_data.begin(), this->tensile_data.end(), 0l);
      std::fill<typename std::array<float, 22>::iterator, float>(this->joint_angles.begin(), this->joint_angles.end(), 0.0f);
      this->timestamp = 0ul;
    }
  }

  explicit GloveDataMsg_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init),
    linear_acceleration(_alloc),
    angular_velocity(_alloc),
    tensile_data(_alloc),
    joint_angles(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      std::fill<typename std::array<float, 3>::iterator, float>(this->linear_acceleration.begin(), this->linear_acceleration.end(), 0.0f);
      std::fill<typename std::array<float, 3>::iterator, float>(this->angular_velocity.begin(), this->angular_velocity.end(), 0.0f);
      this->temperature = 0.0f;
      std::fill<typename std::array<int32_t, 19>::iterator, int32_t>(this->tensile_data.begin(), this->tensile_data.end(), 0l);
      std::fill<typename std::array<float, 22>::iterator, float>(this->joint_angles.begin(), this->joint_angles.end(), 0.0f);
      this->timestamp = 0ul;
    }
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _linear_acceleration_type =
    std::array<float, 3>;
  _linear_acceleration_type linear_acceleration;
  using _angular_velocity_type =
    std::array<float, 3>;
  _angular_velocity_type angular_velocity;
  using _temperature_type =
    float;
  _temperature_type temperature;
  using _tensile_data_type =
    std::array<int32_t, 19>;
  _tensile_data_type tensile_data;
  using _joint_angles_type =
    std::array<float, 22>;
  _joint_angles_type joint_angles;
  using _timestamp_type =
    uint32_t;
  _timestamp_type timestamp;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__linear_acceleration(
    const std::array<float, 3> & _arg)
  {
    this->linear_acceleration = _arg;
    return *this;
  }
  Type & set__angular_velocity(
    const std::array<float, 3> & _arg)
  {
    this->angular_velocity = _arg;
    return *this;
  }
  Type & set__temperature(
    const float & _arg)
  {
    this->temperature = _arg;
    return *this;
  }
  Type & set__tensile_data(
    const std::array<int32_t, 19> & _arg)
  {
    this->tensile_data = _arg;
    return *this;
  }
  Type & set__joint_angles(
    const std::array<float, 22> & _arg)
  {
    this->joint_angles = _arg;
    return *this;
  }
  Type & set__timestamp(
    const uint32_t & _arg)
  {
    this->timestamp = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    open_cyber_glove_ros2::msg::GloveDataMsg_<ContainerAllocator> *;
  using ConstRawPtr =
    const open_cyber_glove_ros2::msg::GloveDataMsg_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<open_cyber_glove_ros2::msg::GloveDataMsg_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<open_cyber_glove_ros2::msg::GloveDataMsg_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      open_cyber_glove_ros2::msg::GloveDataMsg_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<open_cyber_glove_ros2::msg::GloveDataMsg_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      open_cyber_glove_ros2::msg::GloveDataMsg_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<open_cyber_glove_ros2::msg::GloveDataMsg_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<open_cyber_glove_ros2::msg::GloveDataMsg_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<open_cyber_glove_ros2::msg::GloveDataMsg_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__open_cyber_glove_ros2__msg__GloveDataMsg
    std::shared_ptr<open_cyber_glove_ros2::msg::GloveDataMsg_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__open_cyber_glove_ros2__msg__GloveDataMsg
    std::shared_ptr<open_cyber_glove_ros2::msg::GloveDataMsg_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const GloveDataMsg_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->linear_acceleration != other.linear_acceleration) {
      return false;
    }
    if (this->angular_velocity != other.angular_velocity) {
      return false;
    }
    if (this->temperature != other.temperature) {
      return false;
    }
    if (this->tensile_data != other.tensile_data) {
      return false;
    }
    if (this->joint_angles != other.joint_angles) {
      return false;
    }
    if (this->timestamp != other.timestamp) {
      return false;
    }
    return true;
  }
  bool operator!=(const GloveDataMsg_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct GloveDataMsg_

// alias to use template instance with default allocator
using GloveDataMsg =
  open_cyber_glove_ros2::msg::GloveDataMsg_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace open_cyber_glove_ros2

#endif  // OPEN_CYBER_GLOVE_ROS2__MSG__DETAIL__GLOVE_DATA_MSG__STRUCT_HPP_
