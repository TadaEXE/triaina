#include "ds/width.hpp"

#include <cstddef>
#include <span>

#include "ds/errors.hpp"
#include "resty.hpp"

namespace ds {

res::expected<Width> Width::unify(std::span<const Width> widths) {
  size_t biggest = 0;
  bool fixed = false;
  for (auto& w : widths) {
    if (fixed && w.fixed() && w.w != biggest) {
      return res::unexpected("Could not unify widths.", DSError::InvalidArgs);
    }

    if (!fixed) {
      if (w.fixed()) {
        fixed = true;
        biggest = w.w;
      } else if (w.w > biggest) {
        biggest = w.w;
      }
    }
  }
  return Width{fixed ? Width::Kind::Fixed : Width::Kind::Dynamic, biggest};
}
}  // namespace ds
