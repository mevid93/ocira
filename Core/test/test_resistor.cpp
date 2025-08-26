//==============================================================================
// File:        test_resistor.cpp
// Author:      Martin Vidjeskog
// Created:     2025-08-26
// Description: Unit tests for Resistor class in OCIRA core library.
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
// - Tests cover Resistor class.
// - Run with: ctest or ./core_tests or ./core_tests --gtest_filter=resistor.*
//==============================================================================

#include "resistor.hpp"
#include <gtest/gtest.h>

using namespace ocira::core;

/// @brief Test Resistor class constructor.
TEST(resistor, constructor_works) {
  // Create new Resistor object.
  Resistor resistor(1, 100);
  // Expect equality.
  EXPECT_EQ(resistor.getId(), 1);
  EXPECT_EQ(resistor.getComponentType(), ComponentType::RESISTOR);
  EXPECT_EQ(resistor.getResistance(), 100);
}

/// @brief Test resistance setter and getter.
TEST(resistor, set_resistance) {
  // Create new Resistor object.
  Resistor resistor(1, 100);
  // Set new resistance value.
  resistor.setResistance(200.5);
  // Expect equality.
  EXPECT_EQ(resistor.getResistance(), 200.5);
}

/// @brief Test that correct conductance is returned.
TEST(resistor, get_conductance) {
  // Create new Resistor object.
  Resistor resistor(1, 200);
  // Expect equality.
  EXPECT_FLOAT_EQ(resistor.getConductance(), 0.005);
}