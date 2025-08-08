#include "dc_current_source.hpp"
#include <gtest/gtest.h>

using namespace ocira::core;

// Test DCCurrentSource class constructor.
TEST(dc_current_source, constructor_works) {
  // Create new DCCurrentSource object.
  DCCurrentSource dcCurrentSource(1, 100);
  // Expect equality.
  EXPECT_EQ(dcCurrentSource.getId(), 1);
  EXPECT_EQ(dcCurrentSource.getComponentType(), ComponentType::DC_CURRENT_SOURCE);
  EXPECT_EQ(dcCurrentSource.getAmps(), 100);
}

// Test amps setter and getter.
TEST(dc_current_source, set_amps) {
  // Create new DCCurrentSource object.
  DCCurrentSource dcCurrentSource(1, 100);
  // Set new amps value.
  dcCurrentSource.setAmps(200);
  // Expect equality.
  EXPECT_EQ(dcCurrentSource.getAmps(), 200);
}