#include "ds/gate.hpp"

#include <cmath>
#include <expected>
#include <format>

#include "ds/errors.hpp"
#include "ds/trivec.hpp"
#include "resty.hpp"

namespace ds {

res::vexpected Gate::add_arm(const GateArm& arm) {
  auto expans = arm.pattern.expand_wildcards();
  if (!arm.pattern.has_wildcards()) {
    auto& pat = expans[0];
    if (spec_.match(pat)) {
      return res::unexpected(std::to_string(pat).append(" is already defined."),
                             DSError::Redefinition);
    }

    spec_.add(pat, arm.result);
    ++arm_count_;
    return {};
  }

  for (auto& expan : expans) {
    auto match = spec_.match(expan);
    if (!arm.pattern.only_wildcrads() && match && *match != arm.result) {
      return res::unexpected(
          std::format("Redefinition of {} => {} to {}", std::to_string(expan),
                      std::to_string(*match), std::to_string(arm.result)),
          DSError::Redefinition);
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
    return res::unexpected(
        std::format("Gate defined {} out of {} expected arms", arm_count_,
                    exp_arm_count),
        DSError::InvalidDefinition);

  inited_ = true;
  return {};
}

res::vexpected Gate::init(std::vector<GateArm> arms) {
  if (arms.empty())
    return res::unexpected("Arms empty", DSError::InvalidDefinition);

  for (auto& arm : arms) {
    if (auto e = add_arm(arm); !e.has_value()) {
      return e;
    }
  }

  return init();
}

res::expected<Trit> Gate::eval(const TriVec& tv) const {
  if (!inited_) {
    return res::unexpected("Uninitialized gate can not evaluate input",
                           DSError::UseBeforeInit);
  }
  if (auto m = spec_.match(tv)) return *m;

  return res::unexpected("Trit could not be matched due to malformed gate.",
                         DSError::MalformedStructure);
}

res::expected<TriVec> Gate::call(const std::vector<TriVec>& tvs) const {
  if (!inited_) {
    return res::unexpected("Uninitialized gate can not evaluate input",
                           DSError::UseBeforeInit);
  }

  if (tvs.size() != width_) {
    return res::unexpected(
        std::format("Gate of width {} was called with {} arguments.", width_,
                    tvs.size()),
        DSError::InvalidArgs);
  }

  auto resolved = TriVec::try_length_resolve(tvs);
  if (!resolved) {
    return res::unexpected(resolved.error(), "Invalid arguments for gate call",
                           DSError::InvalidArgs);
  }

  auto cuts = TriVec::get_tritwise_cut(*resolved);
  if (!cuts) {
    return res::unexpected(cuts.error(), "Invalid arguments for gate call",
                           DSError::InvalidArgs);
  }

  std::vector<Trit> result;
  for (auto& cut : *cuts) {
    auto trit = eval(cut);
    if (!trit) {
      return res::unexpected(trit.error().msg);
    }
    result.push_back(*trit);
  }

  return TriVec(result);
}

}  // namespace ds
