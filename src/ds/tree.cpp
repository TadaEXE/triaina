#include "ds/tree.hpp"

#include <memory>

namespace ds {

void Tree::add(TriVec pattern, Trit value) {
  auto* cur = &root;
  for (auto& t : pattern.data()) {
    switch (t) {
      case Trit::Minus:
        if (!(*cur)->mc) { (*cur)->mc = std::make_unique<TreeNode>(); }
        cur = &(*cur)->mc;
        break;
      case Trit::Zero:
        if (!(*cur)->zc) { (*cur)->zc = std::make_unique<TreeNode>(); }
        cur = &(*cur)->zc;
        break;
      case Trit::Plus:
        if (!(*cur)->pc) { (*cur)->pc = std::make_unique<TreeNode>(); }
        cur = &(*cur)->pc;
        break;
    }
  }

  (*cur)->val = value;
}

std::optional<Trit> Tree::match(TriVec pattern) {
  auto* cur = &root;
  for (auto& t : pattern.data()) {
    switch (t) {
      case Trit::Minus:
        if (!(*cur)->mc) return std::nullopt;
        cur = &(*cur)->mc;
        break;
      case Trit::Zero:
        if (!(*cur)->zc) return std::nullopt;
        cur = &(*cur)->zc;
        break;
      case Trit::Plus:
        if (!(*cur)->pc) return std::nullopt;
        cur = &(*cur)->pc;
        break;
    }
  }
  return (*cur)->val;
}

}  // namespace ds
