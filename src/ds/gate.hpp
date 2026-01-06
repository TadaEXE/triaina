#pragma once

#include "ds/tree.hpp"
#include "ds/trit.hpp"
#include "ds/vectors.hpp"
#include "resty.hpp"

namespace ds {

struct GateArm {
  TriMaVec pattern;
  Trit result;
};

class Gate {
 public:
  Gate() = default;

  res::vexpected init(std::vector<GateArm> arms);

  Trit eval(TriVec tv);

 private:
  Tree spec;
};

}  // namespace ds
