#pragma once

#include "runtime/ids.hpp"

namespace rtm {

enum class SymbolKind : uint8_t {
  Gate,
  Func,
  Lambda,
  Reg,
  Var,
};

struct SymbolInfo {
  SymbolKind kind;
  eid<ety::Symbol> sym;
  eid<ety::Gate> gate;
  eid<ety::Func> func;
};

}  // namespace rtm
