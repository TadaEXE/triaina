#include "ds/gate.hpp"
#include <cmath>

#include "ds/vectors.hpp"

namespace ds {

bool Gate::init(std::vector<GateArm> arms) {
  if (arms.empty()) return false;
  size_t added = 0;
  for (auto& arm : arms) {
    auto expans = arm.pattern.expand_wildcards();
    if (!arm.pattern.has_wildcards()) {
      auto& pat = expans[0];
      if (spec.match(pat)) return false;

      spec.add(pat, arm.result);
      ++added;
      continue;
    }

    for (auto& expan : expans) {
      auto match = spec.match(expan);
      if (match && *match != arm.result) return false;
      if (match) continue;

      spec.add(expan, arm.result);
      ++added;
    }
  }

  if (added != std::pow(arms.size(), 3)) return false;
  return true;
}

}  // namespace ds
