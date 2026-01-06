#include <gtest/gtest.h>

#include <vector>

#include "ds/errors.hpp"
#include "ds/gate.hpp"
#include "ds/trivec.hpp"
#include "ds/trit.hpp"

namespace {

TEST(Gate, EvalFailsBeforeInit) {
  ds::Gate g(1);
  auto r = g.eval(ds::TriVec{"+"});
  ASSERT_FALSE(r.has_value());
  EXPECT_TRUE(r.error() == ds::DSError::UseBeforeInit);
}

TEST(Gate, InitRejectsIncompleteDefinition) {
  ds::Gate g(1);

  ASSERT_TRUE(g.add_arm(ds::GateArm{ds::TriMaVec{"+"}, ds::Trit::Plus}).has_value());
  ASSERT_TRUE(g.add_arm(ds::GateArm{ds::TriMaVec{"0"}, ds::Trit::Zero}).has_value());

  auto r = g.init();
  ASSERT_FALSE(r.has_value());
  EXPECT_TRUE(r.error() == ds::DSError::InvalidDefinition);
}

TEST(Gate, AddArmRejectsRedefinitionWithoutWildcards) {
  ds::Gate g(1);

  ASSERT_TRUE(g.add_arm(ds::GateArm{ds::TriMaVec{"+"}, ds::Trit::Plus}).has_value());
  auto r = g.add_arm(ds::GateArm{ds::TriMaVec{"+"}, ds::Trit::Minus});
  ASSERT_FALSE(r.has_value());
  EXPECT_TRUE(r.error() == ds::DSError::Redefinition);
}

TEST(Gate, InitAndEvalWorksForFullyDefinedWidth1) {
  ds::Gate g(1);

  ASSERT_TRUE(g.add_arm(ds::GateArm{ds::TriMaVec{"+"}, ds::Trit::Plus}).has_value());
  ASSERT_TRUE(g.add_arm(ds::GateArm{ds::TriMaVec{"0"}, ds::Trit::Zero}).has_value());
  ASSERT_TRUE(g.add_arm(ds::GateArm{ds::TriMaVec{"-"}, ds::Trit::Minus}).has_value());

  ASSERT_TRUE(g.init().has_value());

  ASSERT_TRUE(g.eval(ds::TriVec{"+"}).has_value());
  ASSERT_TRUE(g.eval(ds::TriVec{"0"}).has_value());
  ASSERT_TRUE(g.eval(ds::TriVec{"-"}).has_value());

  EXPECT_EQ(*g.eval(ds::TriVec{"+"}), ds::Trit::Plus);
  EXPECT_EQ(*g.eval(ds::TriVec{"0"}), ds::Trit::Zero);
  EXPECT_EQ(*g.eval(ds::TriVec{"-"}), ds::Trit::Minus);
}

TEST(Gate, CallRejectsWrongWidth) {
  ds::Gate g(2);

  auto r = g.call({ds::TriVec{"+"}});
  ASSERT_FALSE(r.has_value());
  EXPECT_TRUE(r.error() == ds::DSError::UseBeforeInit);

  ASSERT_TRUE(g.add_arm(ds::GateArm{ds::TriMaVec{"-"}, ds::Trit::Zero}).has_value());
  auto init = g.init();
  ASSERT_FALSE(init.has_value());

  // Still uninitialized; width check happens after init check
  r = g.call({ds::TriVec{"+"}});
  ASSERT_FALSE(r.has_value());
  EXPECT_TRUE(r.error() == ds::DSError::UseBeforeInit);
}

TEST(Gate, CallRejectsInvalidArgCountAfterInit) {
  ds::Gate g(1);

  ASSERT_TRUE(g.add_arm(ds::GateArm{ds::TriMaVec{"+"}, ds::Trit::Plus}).has_value());
  ASSERT_TRUE(g.add_arm(ds::GateArm{ds::TriMaVec{"0"}, ds::Trit::Zero}).has_value());
  ASSERT_TRUE(g.add_arm(ds::GateArm{ds::TriMaVec{"-"}, ds::Trit::Minus}).has_value());
  ASSERT_TRUE(g.init().has_value());

  auto r = g.call({});
  ASSERT_FALSE(r.has_value());
  EXPECT_TRUE(r.error() == ds::DSError::InvalidArgs);

  r = g.call({ds::TriVec{"+"}, ds::TriVec{"0"}});
  ASSERT_FALSE(r.has_value());
  EXPECT_TRUE(r.error() == ds::DSError::InvalidArgs);
}

TEST(Gate, CallRejectsUnresolvableLengths) {
  ds::Gate g(2);

  ASSERT_TRUE(g.add_arm(ds::GateArm{ds::TriMaVec{"__"}, ds::Trit::Zero}).has_value());
  // Expand-only-wildcards yields full coverage for width=2
  ASSERT_TRUE(g.init().has_value());

  ds::TriVec a{"+0-"};
  a.fix_length();
  ds::TriVec b{"+0"};
  b.fix_length();

  auto r = g.call({a, b});
  ASSERT_FALSE(r.has_value());
  EXPECT_TRUE(r.error() == ds::DSError::InvalidArgs);
}

TEST(Gate, CallProducesVectorResult) {
  ds::Gate g(1);

  ASSERT_TRUE(g.add_arm(ds::GateArm{ds::TriMaVec{"+"}, ds::Trit::Plus}).has_value());
  ASSERT_TRUE(g.add_arm(ds::GateArm{ds::TriMaVec{"0"}, ds::Trit::Zero}).has_value());
  ASSERT_TRUE(g.add_arm(ds::GateArm{ds::TriMaVec{"-"}, ds::Trit::Minus}).has_value());
  ASSERT_TRUE(g.init().has_value());

  ds::TriVec in{"+0-"};
  auto r = g.call({in});
  ASSERT_TRUE(r.has_value());
  EXPECT_EQ(std::to_string(*r), "+0-");
}

}  // namespace
