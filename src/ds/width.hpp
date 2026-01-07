#pragma once

#include <cstdint>
#include <span>

#include "resty.hpp"

namespace ds {

struct Width {
  enum class Kind : uint8_t { Fixed, Dynamic };

  Kind kind{Kind::Dynamic};
  uint32_t n{0};

  static constexpr Width fixed(uint32_t v) { return Width{Kind::Fixed, v}; }

  static constexpr Width dynamic() { return Width{Kind::Dynamic, 0}; }

  constexpr bool is_fixed() const { return kind == Kind::Fixed; }

  constexpr bool is_dynamic() const { return kind == Kind::Dynamic; }
};

struct WidthUnifyResult {
  size_t chosen_width{0};
};

/// Policy:
/// - All fixed inputs must agree on the same width.
/// - Mixed fixed and dynamic inputs unify to the fixed width when the
///   fixed widths agree.
/// - All dynamic inputs unify to the widest runtime length.
/// - Failure is reported when fixed widths disagree or inputs cannot be
///   reconciled under the policy.
res::expected<WidthUnifyResult> unify_widths_for_elementwise(
    std::span<const Width> declared, std::span<const size_t> actual_lengths);
}  // namespace ds
