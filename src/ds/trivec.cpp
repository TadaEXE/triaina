#include "ds/trivec.hpp"

#include <vector>

#include "ds/trit.hpp"
#include "errors.hpp"
#include "resty.hpp"

namespace ds {

TriVec::TriVec(const std::string& input) {
  for (auto& i : input | std::views::reverse) {
    switch (i) {
      case '+':
        data_.push_back(Trit::Plus);
        break;
      case '0':
        data_.push_back(Trit::Zero);
        break;
      case '-':
        data_.push_back(Trit::Minus);
        break;
      default:
        continue;
    }
  }
}

TriVec::TriVec(const TriMaVec& tmv) {
  for (auto& tm : tmv.data()) {
    switch (tm) {
      case TritMatch::Plus:
        data_.push_back(Trit::Plus);
        break;
      case TritMatch::Zero:
        data_.push_back(Trit::Zero);
        break;
      case TritMatch::Minus:
        data_.push_back(Trit::Minus);
        break;
      default:
        continue;
    }
  }
}

res::vexpected TriVec::resize_to(size_t len, Trit fill) {
  if (fixed_) return res::unexpected("Can not resize fixed vector.", DSError::Unknown);

  auto cur = length();
  if (cur == len) return {};

  if (len > cur) {
    for (auto i = cur; i < len; ++i) {
      data_.push_back(fill);
    }
    return {};
  }

  for (auto i = cur; i > len; --i) {
    data_.pop_back();
  }
  return {};
}

res::expected<std::vector<TriVec>> TriVec::try_length_resolve(
    std::vector<TriVec> tvs) {
  size_t target_len = 0;
  bool fixed = false;
  for (auto& tv : tvs) {
    if (tv.fixed()) {
      if (fixed && tv.length() != target_len) {
        return res::unexpected(
            "Can not resolve length for multiple fixed size vectors.",
            DSError::InvalidArgs);
      }
      if (fixed) continue;

      fixed = true;
      target_len = tv.length();
    }

    if (!fixed && tv.length() > target_len) {
      target_len = tv.length();
    }
  }

  for (auto& tv : tvs) {
    if (tv.fixed()) continue;

    if (auto r = tv.resize_to(target_len); !r.has_value()) {
      return res::unexpected(r.error());
    }
  }

  return tvs;
}

res::expected<std::vector<TriVec>> TriVec::get_tritwise_cut(
    const std::vector<TriVec>& tvs) {
  if (tvs.empty())
    return res::unexpected("Can not do tritwise cut on empty args.");

  size_t len = tvs[0].length();
  for (auto& tv : tvs) {
    if (tv.length() != len) {
      return res::unexpected("Can not tritwise cut vectors of unequal length.");
    }
  }

  std::vector<TriVec> res;
  for (size_t i = 0; i < tvs[0].length(); ++i) {
    TriVec tmp;
    for (auto& tv : tvs) {
      tmp.data_.push_back(tv.data_[i]);
    }
    res.push_back(tmp);
  }
  return res;
}

TriMaVec::TriMaVec(std::string input) {
  only_wildcrads_ = true;
  for (auto& i : input | std::views::reverse) {
    switch (i) {
      case '+':
        data_.push_back(TritMatch::Plus);
        only_wildcrads_ = false;
        break;
      case '0':
        data_.push_back(TritMatch::Zero);
        only_wildcrads_ = false;
        break;
      case '-':
        data_.push_back(TritMatch::Minus);
        only_wildcrads_ = false;
        break;
      case '_':
        data_.push_back(TritMatch::Wild);
        has_wildcards_ = true;
        break;
      default:
        continue;
    }
  }
}

std::vector<TriMaVec> TriMaVec::resolve_wildcards(std::vector<TriMaVec>& tmvs,
                                                  size_t i) const {
  std::vector<TriMaVec> res;
  const auto& test = tmvs[0].data();
  if (i >= test.size()) return tmvs;

  size_t j = i;
  for (; j < test.size(); ++j) {
    if (test[j] == TritMatch::Wild) {
      break;
    }
  }
  if (j >= test.size()) return tmvs;

  for (auto& tmv : tmvs) {
    auto tmp = tmv;
    tmp.data_[j] = TritMatch::Plus;
    res.push_back(tmp);
    tmp.data_[j] = TritMatch::Zero;
    res.push_back(tmp);
    tmp.data_[j] = TritMatch::Minus;
    res.push_back(tmp);
  }

  return resolve_wildcards(res, j);
}

std::vector<TriVec> TriMaVec::expand_wildcards() const {
  std::vector<TriMaVec> tmp({*this});
  auto fin = resolve_wildcards(tmp);
  std::vector<TriVec> res;
  for (auto& tmv : fin) {
    res.push_back(TriVec{tmv});
  }
  return res;
}

}  // namespace ds
