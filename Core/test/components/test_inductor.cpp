//==============================================================================
// File:        test_inductor.cpp
// Author:      Martin Vidjeskog
// Created:     2025-09-14
// Description: Unit tests for Inductor class in OCIRA core library.
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
// - Tests cover Inductor class.
// - Run with: ctest or ./core_tests or ./core_tests --gtest_filter=inductor.*
//==============================================================================

#include "component.hpp"
#include "inductor.hpp"
#include <gtest/gtest.h>
#include <memory>

using namespace ocira::core;
using namespace ocira::core::components;

/// @brief Test Inductor class constructor.
TEST(inductor, constructor_works) {
  // Create new Inductor object.
  Inductor inductor(1, 5.0f);
  // Expect equality.
  EXPECT_EQ(inductor.getId(), 1);
  EXPECT_FLOAT_EQ(inductor.getInductance(), 5.0f);
}

/// @brief Test inductance setter.
TEST(inductor, set_inductance) {
  // Create new Inductor object.
  Inductor inductor(1, 5.0);
  // Set new inductor.
  inductor.setInductance(10.0f);
  // Expect equality.
  EXPECT_FLOAT_EQ(inductor.getInductance(), 10.0f);
}

/// @brief Test get impedance.
TEST(inductor, get_impedance) {
  // Create new Inductor object.
  Inductor inductor(1, 5.0);
  // Get impedance.
  auto impedance = inductor.getImpedance(50);
  // Expect equality.
  EXPECT_FLOAT_EQ(impedance.real(), 0.0f);
  EXPECT_FLOAT_EQ(impedance.imag(), 1570.7964f);
}

/// @brief Test get admittance.
TEST(inductor, get_admittance) {
  // Create new Inductor object.
  Inductor inductor(1, 5.0);
  // Get admittance.
  auto admittance = inductor.getAdmittance(50);
  // Expect equality.
  EXPECT_FLOAT_EQ(admittance.real(), 0.0f);
  EXPECT_FLOAT_EQ(admittance.imag(), -0.00063661975f);
}