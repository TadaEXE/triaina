#pragma once

#include <expected>
#include <string>

namespace res {

template <class T>
using expected = std::expected<T, std::string>;

using vexpected = std::expected<void, std::string>;

}  // namespace res
