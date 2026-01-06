#pragma once

#include <cstddef>
#include <cstdint>

namespace rtm {

enum class EntityType : uint8_t {
  Error = 0,
  Gate,
  Reg,
  Var,
  Expr,
  Bus,
};

typedef struct __attribute__((packed)) EntityID {
  EntityType ty;
  size_t id;
} eid;

class IEngineApi {
 public:
  virtual ~IEngineApi() = default;

  // Gate
  virtual eid create_gate() = 0;

  // Expressions
  virtual void eval_expr(eid) = 0;

 private:
};

}  // namespace rtm
