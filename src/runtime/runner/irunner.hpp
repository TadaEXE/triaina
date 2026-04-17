#pragma once

#include <cstdint>
#include <expected>

namespace exmo::run {

enum class RunResult : uint8_t {
  Success = 0,
  Failed = 1,
  Warning = 2,
};

class IRunner {
 public:
  virtual std::expected<void, RunResult> run() = 0;
};

}  // namespace exmo::run
