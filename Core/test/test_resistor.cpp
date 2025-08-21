#include "resistor.hpp"
#include <gtest/gtest.h>

using namespace ocira::core;

// Test Resistor class constructor.
TEST(resistor, constructor_works) {
  // Create new Resistor object.
  Resistor resistor(1, 100);
  // Expect equality.
  EXPECT_EQ(resistor.getId(), 1);
  EXPECT_EQ(resistor.getComponentType(), ComponentType::RESISTOR);
  EXPECT_EQ(resistor.getResistance(), 100);
}

// Test resistance setter and getter.
TEST(resistor, set_resistance) {
  // Create new Resistor object.
  Resistor resistor(1, 100);
  // Set new resistance value.
  resistor.setResistance(200.5);
  // Expect equality.
  EXPECT_EQ(resistor.getResistance(), 200.5);
}