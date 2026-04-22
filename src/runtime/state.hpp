#pragma once

#include <cstdint>
#include <format>
#include <string>

namespace rtm {

enum class State : uint8_t {
  Error,
  HighZ,
  Plus,
  Minus,
  Zero,
};

inline std::string state_to_string(const State s) {
  switch (s) {
    case State::Error:
      return "Error";
    case State::HighZ:
      return "HighZ";
    case State::Plus:
      return "Plus";
    case State::Minus:
      return "Minus";
    case State::Zero:
      return "Zero";
  }
  return "Unknown";
}

}  // namespace rtm

template <>
struct std::formatter<rtm::State> : std::formatter<std::string> {
  auto format(const rtm::State& s, format_context& ctx) const {
    return std::formatter<std::string>::format(rtm::state_to_string(s), ctx);
  }
};
