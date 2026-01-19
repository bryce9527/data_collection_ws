// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from open_cyber_glove_ros2:msg/GloveDataMsg.idl
// generated code does not contain a copyright notice

#ifndef OPEN_CYBER_GLOVE_ROS2__MSG__DETAIL__GLOVE_DATA_MSG__TRAITS_HPP_
#define OPEN_CYBER_GLOVE_ROS2__MSG__DETAIL__GLOVE_DATA_MSG__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "open_cyber_glove_ros2/msg/detail/glove_data_msg__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"

namespace open_cyber_glove_ros2
{

namespace msg
{

inline void to_flow_style_yaml(
  const GloveDataMsg & msg,
  std::ostream & out)
{
  out << "{";
  // member: header
  {
    out << "header: ";
    to_flow_style_yaml(msg.header, out);
    out << ", ";
  }

  // member: linear_acceleration
  {
    if (msg.linear_acceleration.size() == 0) {
      out << "linear_acceleration: []";
    } else {
      out << "linear_acceleration: [";
      size_t pending_items = msg.linear_acceleration.size();
      for (auto item : msg.linear_acceleration) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: angular_velocity
  {
    if (msg.angular_velocity.size() == 0) {
      out << "angular_velocity: []";
    } else {
      out << "angular_velocity: [";
      size_t pending_items = msg.angular_velocity.size();
      for (auto item : msg.angular_velocity) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: temperature
  {
    out << "temperature: ";
    rosidl_generator_traits::value_to_yaml(msg.temperature, out);
    out << ", ";
  }

  // member: tensile_data
  {
    if (msg.tensile_data.size() == 0) {
      out << "tensile_data: []";
    } else {
      out << "tensile_data: [";
      size_t pending_items = msg.tensile_data.size();
      for (auto item : msg.tensile_data) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: joint_angles
  {
    if (msg.joint_angles.size() == 0) {
      out << "joint_angles: []";
    } else {
      out << "joint_angles: [";
      size_t pending_items = msg.joint_angles.size();
      for (auto item : msg.joint_angles) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: timestamp
  {
    out << "timestamp: ";
    rosidl_generator_traits::value_to_yaml(msg.timestamp, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const GloveDataMsg & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: header
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "header:\n";
    to_block_style_yaml(msg.header, out, indentation + 2);
  }

  // member: linear_acceleration
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.linear_acceleration.size() == 0) {
      out << "linear_acceleration: []\n";
    } else {
      out << "linear_acceleration:\n";
      for (auto item : msg.linear_acceleration) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: angular_velocity
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.angular_velocity.size() == 0) {
      out << "angular_velocity: []\n";
    } else {
      out << "angular_velocity:\n";
      for (auto item : msg.angular_velocity) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: temperature
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "temperature: ";
    rosidl_generator_traits::value_to_yaml(msg.temperature, out);
    out << "\n";
  }

  // member: tensile_data
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.tensile_data.size() == 0) {
      out << "tensile_data: []\n";
    } else {
      out << "tensile_data:\n";
      for (auto item : msg.tensile_data) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: joint_angles
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.joint_angles.size() == 0) {
      out << "joint_angles: []\n";
    } else {
      out << "joint_angles:\n";
      for (auto item : msg.joint_angles) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: timestamp
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "timestamp: ";
    rosidl_generator_traits::value_to_yaml(msg.timestamp, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const GloveDataMsg & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace open_cyber_glove_ros2

namespace rosidl_generator_traits
{

[[deprecated("use open_cyber_glove_ros2::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const open_cyber_glove_ros2::msg::GloveDataMsg & msg,
  std::ostream & out, size_t indentation = 0)
{
  open_cyber_glove_ros2::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use open_cyber_glove_ros2::msg::to_yaml() instead")]]
inline std::string to_yaml(const open_cyber_glove_ros2::msg::GloveDataMsg & msg)
{
  return open_cyber_glove_ros2::msg::to_yaml(msg);
}

template<>
inline const char * data_type<open_cyber_glove_ros2::msg::GloveDataMsg>()
{
  return "open_cyber_glove_ros2::msg::GloveDataMsg";
}

template<>
inline const char * name<open_cyber_glove_ros2::msg::GloveDataMsg>()
{
  return "open_cyber_glove_ros2/msg/GloveDataMsg";
}

template<>
struct has_fixed_size<open_cyber_glove_ros2::msg::GloveDataMsg>
  : std::integral_constant<bool, has_fixed_size<std_msgs::msg::Header>::value> {};

template<>
struct has_bounded_size<open_cyber_glove_ros2::msg::GloveDataMsg>
  : std::integral_constant<bool, has_bounded_size<std_msgs::msg::Header>::value> {};

template<>
struct is_message<open_cyber_glove_ros2::msg::GloveDataMsg>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // OPEN_CYBER_GLOVE_ROS2__MSG__DETAIL__GLOVE_DATA_MSG__TRAITS_HPP_
