#pragma once

#include <cstddef>
#include <span>

#include "resty.hpp"

namespace ds {

struct Width {
  enum class Kind : uint8_t { Fixed, Dynamic } kind{Kind::Dynamic};
  size_t w{0};

  constexpr bool fixed() const { return kind == Kind::Fixed; }

  constexpr bool dynamic() const { return kind == Kind::Dynamic; }

  /// Policy:
  /// - All fixed inputs must agree on the same width.
  /// - Mixed fixed and dynamic inputs unify to the fixed width when the
  ///   fixed widths agree.
  /// - All dynamic inputs unify to the widest runtime length.
  /// - Failure is reported when fixed widths disagree or inputs cannot be
  ///   reconciled under the policy.
  static res::expected<Width> unify(std::span<const Width> widths);

  static constexpr Width Fixed(size_t v) { return Width{Kind::Fixed, v}; }
  static constexpr Width Dynamic(size_t w) { return Width{Kind::Dynamic, 0}; }
};

}  // namespace ds
