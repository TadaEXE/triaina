#pragma once

#include <cstdint>
#include <optional>

namespace ds {

struct NormalizedSlice {
  size_t lo;
  size_t hi;
  int8_t step;
};

struct Slice {
  std::optional<int64_t> lo;
  std::optional<int64_t> hi;
  int8_t step;

  NormalizedSlice normalize(size_t len);
  static NormalizedSlice normalize(Slice s, size_t len);
};

}  // namespace ds
