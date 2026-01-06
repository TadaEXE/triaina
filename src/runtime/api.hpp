#pragma once

#include <cstddef>
#include <cstdint>

#include "ds/gate.hpp"
#include "ds/value_container.hpp"
#include "resty.hpp"

namespace rtm {

enum class EntityType : uint8_t {
  Error = 0,
  Gate,
  Reg,
  Var,
  Expr,
  Bus,
  Scope,
};

typedef struct __attribute__((packed)) EntityID {
  EntityType ty;
  size_t id;
} eid;

class IEngineApi {
 public:
  virtual ~IEngineApi() = default;

  virtual res::expected<eid> create(const ds::Gate& gate) = 0;
  virtual res::expected<eid> create(const ds::Reg& gate) = 0;
  virtual res::expected<eid> call_gate(const std::vector<eid>& args) = 0;

  virtual eid eval_expr(const eid& expr) = 0;
};

}  // namespace rtm
