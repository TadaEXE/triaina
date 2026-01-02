#pragma once

#include <cstdint>
#include <vector>
#include <array>

namespace rtm {

class IEngineApi {
 public:
  virtual ~IEngineApi() = default;

  // Gate
  virtual uintptr_t create_gate() = 0;

  // Expressions
  virtual void eval_expr(uintptr_t) = 0;

 private:
};

}  // namespace rtm
