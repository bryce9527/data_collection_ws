// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from data_recorder_interfaces:srv/StartRecording.idl
// generated code does not contain a copyright notice

#ifndef DATA_RECORDER_INTERFACES__SRV__DETAIL__START_RECORDING__BUILDER_HPP_
#define DATA_RECORDER_INTERFACES__SRV__DETAIL__START_RECORDING__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "data_recorder_interfaces/srv/detail/start_recording__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace data_recorder_interfaces
{

namespace srv
{

namespace builder
{

class Init_StartRecording_Request_operator_id
{
public:
  explicit Init_StartRecording_Request_operator_id(::data_recorder_interfaces::srv::StartRecording_Request & msg)
  : msg_(msg)
  {}
  ::data_recorder_interfaces::srv::StartRecording_Request operator_id(::data_recorder_interfaces::srv::StartRecording_Request::_operator_id_type arg)
  {
    msg_.operator_id = std::move(arg);
    return std::move(msg_);
  }

private:
  ::data_recorder_interfaces::srv::StartRecording_Request msg_;
};

class Init_StartRecording_Request_item_type
{
public:
  Init_StartRecording_Request_item_type()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_StartRecording_Request_operator_id item_type(::data_recorder_interfaces::srv::StartRecording_Request::_item_type_type arg)
  {
    msg_.item_type = std::move(arg);
    return Init_StartRecording_Request_operator_id(msg_);
  }

private:
  ::data_recorder_interfaces::srv::StartRecording_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::data_recorder_interfaces::srv::StartRecording_Request>()
{
  return data_recorder_interfaces::srv::builder::Init_StartRecording_Request_item_type();
}

}  // namespace data_recorder_interfaces


namespace data_recorder_interfaces
{

namespace srv
{

namespace builder
{

class Init_StartRecording_Response_message
{
public:
  explicit Init_StartRecording_Response_message(::data_recorder_interfaces::srv::StartRecording_Response & msg)
  : msg_(msg)
  {}
  ::data_recorder_interfaces::srv::StartRecording_Response message(::data_recorder_interfaces::srv::StartRecording_Response::_message_type arg)
  {
    msg_.message = std::move(arg);
    return std::move(msg_);
  }

private:
  ::data_recorder_interfaces::srv::StartRecording_Response msg_;
};

class Init_StartRecording_Response_success
{
public:
  Init_StartRecording_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_StartRecording_Response_message success(::data_recorder_interfaces::srv::StartRecording_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return Init_StartRecording_Response_message(msg_);
  }

private:
  ::data_recorder_interfaces::srv::StartRecording_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::data_recorder_interfaces::srv::StartRecording_Response>()
{
  return data_recorder_interfaces::srv::builder::Init_StartRecording_Response_success();
}

}  // namespace data_recorder_interfaces

#endif  // DATA_RECORDER_INTERFACES__SRV__DETAIL__START_RECORDING__BUILDER_HPP_
