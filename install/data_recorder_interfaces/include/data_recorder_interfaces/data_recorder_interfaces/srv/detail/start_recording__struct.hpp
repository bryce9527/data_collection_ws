// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from data_recorder_interfaces:srv/StartRecording.idl
// generated code does not contain a copyright notice

#ifndef DATA_RECORDER_INTERFACES__SRV__DETAIL__START_RECORDING__STRUCT_HPP_
#define DATA_RECORDER_INTERFACES__SRV__DETAIL__START_RECORDING__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__data_recorder_interfaces__srv__StartRecording_Request __attribute__((deprecated))
#else
# define DEPRECATED__data_recorder_interfaces__srv__StartRecording_Request __declspec(deprecated)
#endif

namespace data_recorder_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct StartRecording_Request_
{
  using Type = StartRecording_Request_<ContainerAllocator>;

  explicit StartRecording_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->item_type = "";
      this->operator_id = "";
    }
  }

  explicit StartRecording_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : item_type(_alloc),
    operator_id(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->item_type = "";
      this->operator_id = "";
    }
  }

  // field types and members
  using _item_type_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _item_type_type item_type;
  using _operator_id_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _operator_id_type operator_id;

  // setters for named parameter idiom
  Type & set__item_type(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->item_type = _arg;
    return *this;
  }
  Type & set__operator_id(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->operator_id = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    data_recorder_interfaces::srv::StartRecording_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const data_recorder_interfaces::srv::StartRecording_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<data_recorder_interfaces::srv::StartRecording_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<data_recorder_interfaces::srv::StartRecording_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      data_recorder_interfaces::srv::StartRecording_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<data_recorder_interfaces::srv::StartRecording_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      data_recorder_interfaces::srv::StartRecording_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<data_recorder_interfaces::srv::StartRecording_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<data_recorder_interfaces::srv::StartRecording_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<data_recorder_interfaces::srv::StartRecording_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__data_recorder_interfaces__srv__StartRecording_Request
    std::shared_ptr<data_recorder_interfaces::srv::StartRecording_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__data_recorder_interfaces__srv__StartRecording_Request
    std::shared_ptr<data_recorder_interfaces::srv::StartRecording_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const StartRecording_Request_ & other) const
  {
    if (this->item_type != other.item_type) {
      return false;
    }
    if (this->operator_id != other.operator_id) {
      return false;
    }
    return true;
  }
  bool operator!=(const StartRecording_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct StartRecording_Request_

// alias to use template instance with default allocator
using StartRecording_Request =
  data_recorder_interfaces::srv::StartRecording_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace data_recorder_interfaces


#ifndef _WIN32
# define DEPRECATED__data_recorder_interfaces__srv__StartRecording_Response __attribute__((deprecated))
#else
# define DEPRECATED__data_recorder_interfaces__srv__StartRecording_Response __declspec(deprecated)
#endif

namespace data_recorder_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct StartRecording_Response_
{
  using Type = StartRecording_Response_<ContainerAllocator>;

  explicit StartRecording_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
      this->message = "";
    }
  }

  explicit StartRecording_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : message(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
      this->message = "";
    }
  }

  // field types and members
  using _success_type =
    bool;
  _success_type success;
  using _message_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _message_type message;

  // setters for named parameter idiom
  Type & set__success(
    const bool & _arg)
  {
    this->success = _arg;
    return *this;
  }
  Type & set__message(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->message = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    data_recorder_interfaces::srv::StartRecording_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const data_recorder_interfaces::srv::StartRecording_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<data_recorder_interfaces::srv::StartRecording_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<data_recorder_interfaces::srv::StartRecording_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      data_recorder_interfaces::srv::StartRecording_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<data_recorder_interfaces::srv::StartRecording_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      data_recorder_interfaces::srv::StartRecording_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<data_recorder_interfaces::srv::StartRecording_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<data_recorder_interfaces::srv::StartRecording_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<data_recorder_interfaces::srv::StartRecording_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__data_recorder_interfaces__srv__StartRecording_Response
    std::shared_ptr<data_recorder_interfaces::srv::StartRecording_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__data_recorder_interfaces__srv__StartRecording_Response
    std::shared_ptr<data_recorder_interfaces::srv::StartRecording_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const StartRecording_Response_ & other) const
  {
    if (this->success != other.success) {
      return false;
    }
    if (this->message != other.message) {
      return false;
    }
    return true;
  }
  bool operator!=(const StartRecording_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct StartRecording_Response_

// alias to use template instance with default allocator
using StartRecording_Response =
  data_recorder_interfaces::srv::StartRecording_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace data_recorder_interfaces

namespace data_recorder_interfaces
{

namespace srv
{

struct StartRecording
{
  using Request = data_recorder_interfaces::srv::StartRecording_Request;
  using Response = data_recorder_interfaces::srv::StartRecording_Response;
};

}  // namespace srv

}  // namespace data_recorder_interfaces

#endif  // DATA_RECORDER_INTERFACES__SRV__DETAIL__START_RECORDING__STRUCT_HPP_
