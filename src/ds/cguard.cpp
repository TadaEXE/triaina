#include "ds/cguard.hpp"

#include "ds/trivec.hpp"

namespace ds {

GuardMatch CGuard::allows(const TriVec& tv) const {
  if (tv.length() == 0) return GuardMatch::No;

  auto& lst = tv[0];
  if (lst == a) return GuardMatch::Yes;
  if (!has_b) return GuardMatch::No;
  if (lst == b) return GuardMatch::Yes;
  return GuardMatch::No;
}
}  // namespace ds
