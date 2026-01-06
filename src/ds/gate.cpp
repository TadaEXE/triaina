#include "ds/gate.hpp"

#include <cmath>
#include <expected>

#include "ds/vectors.hpp"
#include "resty.hpp"

namespace ds {

res::vexpected Gate::init(std::vector<GateArm> arms) {
  if (arms.empty()) return std::unexpected("Arms empty");
  size_t added = 0;
  for (auto& arm : arms) {
    auto expans = arm.pattern.expand_wildcards();
    if (!arm.pattern.has_wildcards()) {
      auto& pat = expans[0];
      if (spec.match(pat))
        return std::unexpected(std::to_string(pat).append(" is already defined."));

      spec.add(pat, arm.result);
      ++added;
      continue;
    }

    for (auto& expan : expans) {
      auto match = spec.match(expan);
      if (match && *match != arm.result) return std::unexpected("Illegal match");
      if (match) continue;

      spec.add(expan, arm.result);
      ++added;
    }
  }

  if (added != std::pow(arms.size(), 3))
    return std::unexpected("Not enough arms where defined");

  return {};
}

Trit Gate::eval(TriVec tv) {
  if (auto m = spec.match(tv)) { return *m; }
  return Trit::Zero;
}

}  // namespace ds
