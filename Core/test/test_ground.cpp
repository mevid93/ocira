#include "ground.hpp"
#include <gtest/gtest.h>

using namespace ocira::core;

// Test Ground class constructor.
TEST(ground, constructor_works) {
  // Create new Ground object.
  Ground ground(1);
  // Expect equality.
  EXPECT_EQ(ground.getId(), 1);
  EXPECT_EQ(ground.getComponentType(), ComponentType::GROUND);
}