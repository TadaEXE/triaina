#include "ds/trivec.hpp"

#include <set>
#include <string>

#include <gtest/gtest.h>

#include "ds/trit.hpp"

namespace {

TEST(TriVec, FromStringParsesAndIgnoresInvalidSymbols) {
  ds::TriVec tv{"+x0-!"};
  EXPECT_EQ(std::to_string(tv), "+0-");
  ASSERT_EQ(tv.length(), 3u);
  EXPECT_EQ(tv.data()[0], ds::Trit::Minus);
  EXPECT_EQ(tv.data()[1], ds::Trit::Zero);
  EXPECT_EQ(tv.data()[2], ds::Trit::Plus);
}

TEST(TriVec, ResizeGrowsAndShrinksWhenNotFixed) {
  ds::TriVec tv{"+0-"};
  ASSERT_TRUE(tv.resize_to(5, ds::Trit::Plus).has_value());
  EXPECT_EQ(std::to_string(tv), "+++0-");
  EXPECT_EQ(tv.length(), 5u);

  ASSERT_TRUE(tv.resize_to(2).has_value());
  EXPECT_EQ(std::to_string(tv), "0-");
  EXPECT_EQ(tv.length(), 2u);
}

TEST(TriVec, ResizeFailsWhenFixed) {
  ds::TriVec tv{"+0-"};
  tv.fix_length();

  auto r = tv.resize_to(4, ds::Trit::Zero);
  ASSERT_FALSE(r.has_value());
  EXPECT_EQ(std::to_string(tv), "+0-");
}

TEST(TriMaVec, FromStringTracksWildcardsAndOnlyWildcards) {
  ds::TriMaVec a{"_+_0"};
  EXPECT_TRUE(a.has_wildcards());
  EXPECT_FALSE(a.only_wildcrads());

  ds::TriMaVec b{"____"};
  EXPECT_TRUE(b.has_wildcards());
  EXPECT_TRUE(b.only_wildcrads());
  
  ds::TriMaVec c{"++--"};
  EXPECT_FALSE(c.has_wildcards());
  EXPECT_FALSE(c.only_wildcrads());
}

TEST(TriMaVec, ExpandWildcardsGeneratesAllCombinations) {
  ds::TriMaVec tmv{"_0_"};

  auto expanded = tmv.expand_wildcards();
  ASSERT_EQ(expanded.size(), 9u);

  std::set<std::string> got;
  for (auto& tv : expanded) got.insert(std::to_string(tv));

  std::set<std::string> expect = {
      "+0+", "+00", "+0-", "00+", "000", "00-", "-0+", "-00", "-0-",
  };

  EXPECT_EQ(got, expect);
}

}  // namespace
