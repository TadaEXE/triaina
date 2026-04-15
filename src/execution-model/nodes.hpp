#pragma once

#include <cstddef>
#include <cstdint>
#include <vector>

namespace exec {
  class Node {
    public:
      const size_t arity() const { return inputs_.size(); }
      const uint64_t last_visited() const { return last_visited_; }
      const std::vector<Node*> inputs() const { return inputs_; }
      const Node* output() const { return output_; }

      virtual Node* run() = 0;
      
    private:
      uint64_t last_visited_ = 0;
      std::vector<Node*> inputs_;
      Node* output_;
  };
}
