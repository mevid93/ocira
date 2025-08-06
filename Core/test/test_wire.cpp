#include "wire.hpp"
#include <gtest/gtest.h>

using namespace ocira::core;

// Test Wire class constructor.
TEST(wire, constructor_works) {
  // Create new Wire object.
  Wire wire(1);
  // Expect equality.
  EXPECT_EQ(wire.getId(), 1);
  EXPECT_EQ(wire.getComponentType(), ComponentType::WIRE);
}