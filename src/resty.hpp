#pragma once

#include <any>
#include <expected>
#include <memory>
#include <string>

namespace res {

struct Error {
  std::string msg;
  std::any dbg_tag{};
  std::unique_ptr<Error> inner{nullptr};

  Error& operator+=(Error&& other) {
    if (this == &other) return *this;

    auto* cur = this;
    while (cur && cur->inner) {
      cur = &*cur->inner;
    }

    if (cur) {
      cur->inner = std::make_unique<Error>(std::move(other));
    }
    return *this;
  }

  template <typename T>
    requires requires(T t1, T t2) { t1 == t2; }
  bool operator==(const T& ty) {
    if (dbg_tag.type() != typeid(T)) return false;

    auto val = std::any_cast<T>(dbg_tag);
    return val == ty;
  }
};

static Error operator+(const Error& lhs, Error&& rhs) {
  if (&lhs == &rhs) {
    return {
        .msg = lhs.msg,
        .dbg_tag = lhs.dbg_tag,
    };
  }

  return {
      .msg = lhs.msg,
      .dbg_tag = lhs.dbg_tag,
      .inner = std::make_unique<Error>(std::move(rhs)),
  };
}

template <typename T>
using expected = std::expected<T, Error>;

using vexpected = std::expected<void, Error>;

static inline std::unexpected<Error> unexpected(const std::string& msg,
                                                std::any dbg_tag = {}) {
  return std::unexpected<Error>(Error{
      .msg = msg,
      .dbg_tag = dbg_tag,
  });
}

static inline std::unexpected<Error> unexpected(Error& fwd) {
  return std::unexpected<Error>(Error{std::move(fwd)});
}

static inline std::unexpected<Error> unexpected(Error& inner,
                                                const std::string& msg,
                                                std::any dbg_tag = {}) {
  return std::unexpected<Error>(Error{
                                    .msg = msg,
                                    .dbg_tag = dbg_tag,
                                } +
                                std::move(inner));
}

}  // namespace res

namespace std {
static std::string to_string(const res::Error& err) {
  std::string res;

  auto* cur = &err;
  while (cur && cur->inner) {
    res.append(cur->msg);
    cur = &*cur->inner;
    if (cur) res.append(": ");
  }

  return res;
}
}  // namespace std
