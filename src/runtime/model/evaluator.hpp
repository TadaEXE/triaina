#pragma once

#include <cstdint>
#include <functional>
#include <vector>

#include "runtime/model/port.hpp"
namespace rtm {
class evaluator {
 public:
  bool fits_spec(size_t inputs, size_t outptus);

 private:
  uintptr_t _id;
  std::string _label;
  std::function<void(std::vector<port*>, std::vector<port*>)> _eval_func;
};
} // namespace rtm
