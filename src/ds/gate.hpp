#pragma once

#include "ds/trit.hpp"
#include "ds/vectors.hpp"

namespace ds {

struct GateSpec {
  const TriVec pattern;
  const Trit result;
};

class Gate {
 public:
 private:
  std::vector<GateSpec> spec;
};

}  // namespace ds
