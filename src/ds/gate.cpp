#include "ds/gate.hpp"

#include <cmath>
#include <expected>
#include <format>

#include "ds/trivec.hpp"
#include "resty.hpp"

namespace ds {

res::vexpected Gate::add_arm(const GateArm& arm) {
  auto expans = arm.pattern.expand_wildcards();
  if (!arm.pattern.has_wildcards()) {
    auto& pat = expans[0];
    if (spec_.match(pat))
      return std::unexpected(
          std::to_string(pat).append(" is already defined."));

    spec_.add(pat, arm.result);
    ++arm_count_;
    return {};
  }

  for (auto& expan : expans) {
    auto match = spec_.match(expan);
    if (!arm.pattern.only_wildcrads() && match && *match != arm.result) {
      return std::unexpected(
          std::format("Redefinition of {} => {} to {}", std::to_string(expan),
                      std::to_string(*match), std::to_string(arm.result)));
    }
    if (match) continue;

    spec_.add(expan, arm.result);
    ++arm_count_;
  }
  return {};
}

res::vexpected Gate::init() {
  auto exp_arm_count = std::pow(3, width_);
  if (arm_count_ != exp_arm_count)
    return std::unexpected(std::format(
        "Gate defined {} out of {} expected arms", arm_count_, exp_arm_count));

  inited_ = true;
  return {};
}

res::vexpected Gate::init(std::vector<GateArm> arms) {
  if (arms.empty()) return std::unexpected("Arms empty");

  for (auto& arm : arms) {
    if (auto e = add_arm(arm); !e.has_value()) {
      return e;
    }
  }

  return init();
}

res::expected<Trit> Gate::eval(TriVec tv) const {
  if (!inited_)
    return std::unexpected("Uninitialized gate can not evaluate input");
  if (auto m = spec_.match(tv)) return *m;

  return std::unexpected("Trit could not be matched due to maleformed gate.");
}

res::expected<TriVec> Gate::call(std::vector<TriVec> tvs) const {
  if (tvs.size() != width_) {
    return std::unexpected(std::format(
        "Gate of width {} was called with {} arguments.", width_, tvs.size()));
  }
}

}  // namespace ds
