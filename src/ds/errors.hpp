#pragma once

#include <cstdint>

namespace ds {

enum class DSError : uint8_t {
  Unknown = 0,
  Redefinition,
  InvalidDefinition,
  UseBeforeInit,
  MalformedStructure,
  InvalidArgs,
};

}
