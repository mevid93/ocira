#include "component.hpp"
#include "node.hpp"
#include <gtest/gtest.h>
#include <memory>

using namespace ocira::core;

// Test Component class constructor.
TEST(component, constructor_works) {
  // Create new Component object.
  Component component(1);
  // Expect equality.
  EXPECT_EQ(component.getId(), 1);
}

// Test that component type is returned.
TEST(component, component_type_is_returned) {
  // Create new Component object.
  Component component(1);
  // Verify the component type.
  EXPECT_EQ(component.getComponentType(), ComponentType::UNDEFINED);
}