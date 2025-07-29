#include "node.hpp"
#include <gtest/gtest.h>

using namespace ocira::core;

// Test Node class constructor.
TEST(node, constructor_works) {
  // Create new Node object.
  Node node(1);
  // Expect equality.
  EXPECT_EQ(node.getId(), 1);
}
