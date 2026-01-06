#include "ds/trit.hpp"

#include <string_view>

#include <gtest/gtest.h>

namespace {

TEST(Trit, ToString) {
  EXPECT_EQ(std::to_string(ds::Trit::Minus), "-");
  EXPECT_EQ(std::to_string(ds::Trit::Zero), "0");
  EXPECT_EQ(std::to_string(ds::Trit::Plus), "+");
}

TEST(TritMatch, ToString) {
  EXPECT_EQ(std::to_string(ds::TritMatch::Minus), "-");
  EXPECT_EQ(std::to_string(ds::TritMatch::Zero), "0");
  EXPECT_EQ(std::to_string(ds::TritMatch::Plus), "+");
  EXPECT_EQ(std::to_string(ds::TritMatch::Wild), "_");
}

}  // namespace
