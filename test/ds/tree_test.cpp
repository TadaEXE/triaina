#include "ds/tree.hpp"

#include <optional>

#include <gtest/gtest.h>

#include "ds/trit.hpp"
#include "ds/trivec.hpp"

namespace {

TEST(Tree, AddAndMatchSingle) {
  ds::Tree t;
  t.add(ds::TriVec{"+0-"}, ds::Trit::Plus);

  auto m = t.match(ds::TriVec{"+0-"});
  ASSERT_TRUE(m.has_value());
  EXPECT_EQ(*m, ds::Trit::Plus);
}

TEST(Tree, MatchMissingReturnsNullopt) {
  ds::Tree t;
  t.add(ds::TriVec{"+0-"}, ds::Trit::Plus);

  EXPECT_FALSE(t.match(ds::TriVec{"+0+"}).has_value());
  EXPECT_FALSE(t.match(ds::TriVec{"+"}).has_value());
  EXPECT_FALSE(t.match(ds::TriVec{""}).has_value());
}

TEST(Tree, MultipleAddsDontInterfere) {
  ds::Tree t;
  t.add(ds::TriVec{"+"}, ds::Trit::Plus);
  t.add(ds::TriVec{"0"}, ds::Trit::Zero);
  t.add(ds::TriVec{"-"}, ds::Trit::Minus);

  EXPECT_EQ(t.match(ds::TriVec{"+"}), std::optional<ds::Trit>(ds::Trit::Plus));
  EXPECT_EQ(t.match(ds::TriVec{"0"}), std::optional<ds::Trit>(ds::Trit::Zero));
  EXPECT_EQ(t.match(ds::TriVec{"-"}), std::optional<ds::Trit>(ds::Trit::Minus));
}

}  // namespace
