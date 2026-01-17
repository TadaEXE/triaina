#pragma once

#include <ranges>
#include <string>
#include <vector>

#include "ds/trit.hpp"
#include "resty.hpp"

namespace ds {

class TriMaVec;

class TriVec {
 public:
  TriVec() = default;
  TriVec(const TriVec&) = default;
  TriVec(TriVec&&) = default;
  TriVec& operator=(const TriVec&) = default;
  TriVec& operator=(TriVec&&) = default;

  /// @brief Convert string to trit vector (ignores all invalid symbols)
  TriVec(const std::string& input);
  // Something like:
  // static std::optional<TriVec> from_match_vec(TriMaVec& tmv,
  // std::optional<Trit> wc); Would be better but we will ge trust me bro path
  explicit TriVec(const TriMaVec& tmv);

  explicit TriVec(const std::vector<Trit>& data) : data_(data) {}

  static res::expected<std::vector<TriVec>> try_length_resolve(
      std::vector<TriVec> tvs);

  static res::expected<std::vector<TriVec>> get_tritwise_cut(
      const std::vector<TriVec>& tvs);

  const std::vector<Trit>& data() { return data_; }
  const auto& at(size_t i) const { return data_.at(i); }
  const auto& operator[](size_t i) const { return at(i); }

  res::vexpected resize_to(size_t len, Trit fill = Trit::Zero);

  inline size_t length() const { return data_.size(); }

  inline bool fixed() const { return fixed_; }

  inline void fix_length() { fixed_ = true; }

 private:
  std::vector<Trit> data_;
  bool fixed_{false};
};

class TriMaVec {
 public:
  TriMaVec() = default;
  TriMaVec(const TriMaVec&) = default;
  TriMaVec(TriMaVec&&) = default;
  TriMaVec& operator=(const TriMaVec&) = default;
  TriMaVec& operator=(TriMaVec&&) = default;

  /// @brief Convert string to tritmatch vector (ignores all invalid symbols)
  TriMaVec(std::string input);

  std::vector<TriVec> expand_wildcards() const;

  bool has_wildcards() const { return has_wildcards_; }

  bool only_wildcrads() const { return only_wildcrads_; }

  const auto& data() const { return data_; }
  const auto& at(size_t i) const { return data_.at(i); }
  const auto& operator[](size_t i) const { return at(i); }

 private:
  std::vector<TritMatch> data_;
  bool has_wildcards_{false};
  bool only_wildcrads_{false};

  std::vector<TriMaVec> resolve_wildcards(std::vector<TriMaVec>& tmvs,
                                          size_t i = 0) const;
};

}  // namespace ds

namespace std {
static constexpr std::string to_string(ds::TriVec tv) {
  std::string res = "";
  for (auto& t : tv.data() | std::views::reverse) {
    res.append(std::to_string(t));
  }
  return res;
}

static constexpr std::string to_string(ds::TriMaVec tmv) {
  std::string res = "";
  for (auto& t : tmv.data() | std::views::reverse) {
    res.append(std::to_string(t));
  }
  return res;
}
}  // namespace std
