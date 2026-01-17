#pragma once

#include <cstddef>
#include <cstdint>

namespace rtm {

enum class EntityType : uint8_t {
  Symbol,
  Gate,
  Func,
  Lambda,
  Reg,
  Var,
  Scope,
};
typedef EntityType ety;

template <EntityType T>
struct EntityId {
  size_t id;
  const ety ty{T};
};

template <EntityType T>
using eid = EntityId<T>;

}  // namespace rtm
