#pragma once

#include "ds/trit.hpp"
#include "ds/trivec.hpp"

namespace ds {

enum class GuardMatch : uint8_t {
  No,
  Yes,
};

struct CGuard {
  Trit a{Trit::Plus};
  bool has_b{false};
  Trit b{Trit::Zero};

  GuardMatch allows(const TriVec& tv) const;
};

}  // namespace ds
