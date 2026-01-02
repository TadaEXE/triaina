#pragma once

#include "ds/tree.hpp"
#include "ds/types.hpp"
#include "ds/vectors.hpp"

namespace ds {

struct GateSpec {
  const TriVec pattern;
  const Trit result;
};

class Gate {};

}  // namespace ds
