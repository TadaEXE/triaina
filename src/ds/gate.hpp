#pragma once

#include "ds/tree.hpp"
#include "ds/trit.hpp"
#include "ds/trivec.hpp"
#include "resty.hpp"

namespace ds {

struct GateArm {
  TriMaVec pattern;
  Trit result;
};

class Gate {
 public:
  explicit Gate(size_t arity) : arity_(arity) {}

  res::vexpected add_arm(const GateArm& arm);

  res::vexpected init();
  res::vexpected init(std::vector<GateArm> arms);

  res::expected<Trit> eval(const TriVec& tv) const;
  res::expected<TriVec> call(const std::vector<TriVec>& tvs) const;

  size_t arity() const { return arity_; }

 private:
  Tree spec_;
  bool inited_{false};
  size_t arm_count_{0};
  size_t arity_{0};
};

}  // namespace ds
