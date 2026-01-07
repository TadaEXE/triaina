#include "ds/slice.hpp"

#include <cstdint>
#include <optional>

namespace ds {

inline size_t abs(int64_t x, size_t len) { return x >= 0 ? x : len + x; }

NormalizedSlice Slice::normalize_slice(size_t len) {
  size_t l = abs(lo.value_or(1), len);
  size_t h = abs(hi.value_or(len), len);

  return NormalizedSlice{.lo = l, .hi = h, .step = step};
}

NormalizedSlice Slice::normalize_slice(Slice s, size_t len) {
  return s.normalize_slice(len);
}

}  // namespace ds
