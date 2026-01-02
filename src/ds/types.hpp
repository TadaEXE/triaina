#pragma once

#include <cstdint>
#include <string>
#include <string_view>

namespace ds {

enum class Trit : int8_t {
  Minus = -1,
  Zero = 0,
  Plus = 1,
};

enum class TritMatch : int8_t {
  Minus = -1,
  Zero = 0,
  Plus = 1,
  Wild = 2,
};

}  // namespace ds

namespace std {
static constexpr std::string_view to_string(ds::Trit t) {
  switch (t) {
    case ds::Trit::Minus:
      return "-";
    case ds::Trit::Zero:
      return "0";
    case ds::Trit::Plus:
      return "+";
  }
}

static constexpr std::string_view to_string(ds::TritMatch t) {
  switch (t) {
    case ds::TritMatch::Minus:
      return "-";
    case ds::TritMatch::Zero:
      return "0";
    case ds::TritMatch::Plus:
      return "+";
    case ds::TritMatch::Wild:
      return "_";
  }
}

typedef struct __attribute__((packed)) EntityID {
  const uint32_t ptr;
  const uint32_t id;

  EntityID(uint64_t i64)
      : ptr(static_cast<uint32_t>(i64 >> 32)),
        id(static_cast<uint32_t>(i64 & 0xFFFFFFFF)) {}
} eid;

}  // namespace std
