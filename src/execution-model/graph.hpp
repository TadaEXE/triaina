#pragma once

#include <cstddef>
#include <cstdint>

namespace model {

struct Node {
  size_t arity;

  uint64_t last_visited_step = 0;
};

class Graph {};
}  // namespace model
