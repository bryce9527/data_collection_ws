// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from data_recorder_interfaces:srv/StartRecording.idl
// generated code does not contain a copyright notice

#ifndef DATA_RECORDER_INTERFACES__SRV__DETAIL__START_RECORDING__TRAITS_HPP_
#define DATA_RECORDER_INTERFACES__SRV__DETAIL__START_RECORDING__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "data_recorder_interfaces/srv/detail/start_recording__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace data_recorder_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const StartRecording_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: item_type
  {
    out << "item_type: ";
    rosidl_generator_traits::value_to_yaml(msg.item_type, out);
    out << ", ";
  }

  // member: operator_id
  {
    out << "operator_id: ";
    rosidl_generator_traits::value_to_yaml(msg.operator_id, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const StartRecording_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: item_type
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "item_type: ";
    rosidl_generator_traits::value_to_yaml(msg.item_type, out);
    out << "\n";
  }

  // member: operator_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "operator_id: ";
    rosidl_generator_traits::value_to_yaml(msg.operator_id, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const StartRecording_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace data_recorder_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use data_recorder_interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const data_recorder_interfaces::srv::StartRecording_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  data_recorder_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use data_recorder_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const data_recorder_interfaces::srv::StartRecording_Request & msg)
{
  return data_recorder_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<data_recorder_interfaces::srv::StartRecording_Request>()
{
  return "data_recorder_interfaces::srv::StartRecording_Request";
}

template<>
inline const char * name<data_recorder_interfaces::srv::StartRecording_Request>()
{
  return "data_recorder_interfaces/srv/StartRecording_Request";
}

template<>
struct has_fixed_size<data_recorder_interfaces::srv::StartRecording_Request>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<data_recorder_interfaces::srv::StartRecording_Request>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<data_recorder_interfaces::srv::StartRecording_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace data_recorder_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const StartRecording_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: success
  {
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
    out << ", ";
  }

  // member: message
  {
    out << "message: ";
    rosidl_generator_traits::value_to_yaml(msg.message, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const StartRecording_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: success
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
    out << "\n";
  }

  // member: message
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "message: ";
    rosidl_generator_traits::value_to_yaml(msg.message, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const StartRecording_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace data_recorder_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use data_recorder_interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const data_recorder_interfaces::srv::StartRecording_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  data_recorder_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use data_recorder_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const data_recorder_interfaces::srv::StartRecording_Response & msg)
{
  return data_recorder_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<data_recorder_interfaces::srv::StartRecording_Response>()
{
  return "data_recorder_interfaces::srv::StartRecording_Response";
}

template<>
inline const char * name<data_recorder_interfaces::srv::StartRecording_Response>()
{
  return "data_recorder_interfaces/srv/StartRecording_Response";
}

template<>
struct has_fixed_size<data_recorder_interfaces::srv::StartRecording_Response>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<data_recorder_interfaces::srv::StartRecording_Response>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<data_recorder_interfaces::srv::StartRecording_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<data_recorder_interfaces::srv::StartRecording>()
{
  return "data_recorder_interfaces::srv::StartRecording";
}

template<>
inline const char * name<data_recorder_interfaces::srv::StartRecording>()
{
  return "data_recorder_interfaces/srv/StartRecording";
}

template<>
struct has_fixed_size<data_recorder_interfaces::srv::StartRecording>
  : std::integral_constant<
    bool,
    has_fixed_size<data_recorder_interfaces::srv::StartRecording_Request>::value &&
    has_fixed_size<data_recorder_interfaces::srv::StartRecording_Response>::value
  >
{
};

template<>
struct has_bounded_size<data_recorder_interfaces::srv::StartRecording>
  : std::integral_constant<
    bool,
    has_bounded_size<data_recorder_interfaces::srv::StartRecording_Request>::value &&
    has_bounded_size<data_recorder_interfaces::srv::StartRecording_Response>::value
  >
{
};

template<>
struct is_service<data_recorder_interfaces::srv::StartRecording>
  : std::true_type
{
};

template<>
struct is_service_request<data_recorder_interfaces::srv::StartRecording_Request>
  : std::true_type
{
};

template<>
struct is_service_response<data_recorder_interfaces::srv::StartRecording_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // DATA_RECORDER_INTERFACES__SRV__DETAIL__START_RECORDING__TRAITS_HPP_
