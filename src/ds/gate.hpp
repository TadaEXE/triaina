#pragma once

#include "ds/tree.hpp"
#include "ds/trit.hpp"
#include "ds/vectors.hpp"

namespace ds {

struct GateArm {
  TriMaVec pattern;
  Trit result;
};

class Gate {
 public:
  Gate() = default;

  bool init(std::vector<GateArm> arms);

 private:
  Tree spec;
};

}  // namespace ds
