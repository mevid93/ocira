//==============================================================================
// File:        test_dc_current_source.cpp
// Author:      Martin Vidjeskog
// Created:     2025-08-26
// Description: Unit tests for DCCurrentSource class in OCIRA core library.
// License:     GNU General Public License v3.0
//==============================================================================
//
// This file is part of OCIRA (core library).
//
// OCIRA is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// OCIRA is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program. If not, see <https://www.gnu.org/licenses/>.
//
//==============================================================================
// Notes:
// - Tests cover DCCurrentSource class.
// - Run with: ctest or ./core_tests or ./core_tests --gtest_filter=dc_current_source.*
//==============================================================================

#include "dc_current_source.hpp"
#include <gtest/gtest.h>

using namespace ocira::core;
using namespace ocira::core::components;

/// @brief Test DCCurrentSource class constructor.
TEST(dc_current_source, constructor_works) {
  // Create new DCCurrentSource object.
  DCCurrentSource dcCurrentSource(1, 100);
  // Expect equality.
  EXPECT_EQ(dcCurrentSource.getId(), 1);
  EXPECT_EQ(dcCurrentSource.getComponentType(), ComponentType::DC_CURRENT_SOURCE);
  EXPECT_EQ(dcCurrentSource.getAmps(), 100);
}

/// @brief Test amps setter and getter.
TEST(dc_current_source, set_amps) {
  // Create new DCCurrentSource object.
  DCCurrentSource dcCurrentSource(1, 100);
  // Set new amps value.
  dcCurrentSource.setAmps(200);
  // Expect equality.
  EXPECT_EQ(dcCurrentSource.getAmps(), 200);
}