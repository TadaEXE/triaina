#pragma once

#include <cstdint>

#include "runtime/model/state.hpp"

namespace rtm {
class Port;

class Edge {
 public:
  const uintptr_t id() { return _id; }
  const Port* begin() { return _begin; }
  const Port* end() { return _end; }

 private:
  uintptr_t _id;
  Port* _begin;
  Port* _end;
};
} // namespace rtm
