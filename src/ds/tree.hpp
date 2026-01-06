#pragma once

#include <memory>
#include <optional>

#include "ds/trivec.hpp"

namespace ds {

struct TreeNode {
  std::optional<Trit> val;
  // Children
  std::unique_ptr<TreeNode> pc;
  std::unique_ptr<TreeNode> zc;
  std::unique_ptr<TreeNode> mc;
};

class Tree {
 public:
  Tree() : root(std::make_unique<TreeNode>()) {}

  void add(TriVec pattern, Trit value);
  std::optional<Trit> match(TriVec pattern) const;

 private:
  std::unique_ptr<TreeNode> root;
};

}  // namespace ds
