//==============================================================================
// File:        test_capacitor.cpp
// Author:      Martin Vidjeskog
// Created:     2025-09-11
// Description: Unit tests for Capacitor class in OCIRA core library.
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
// - Tests cover Capacitor class.
// - Run with: ctest or ./core_tests or ./core_tests --gtest_filter=capacitor.*
//==============================================================================

#include "capacitor.hpp"
#include "component.hpp"
#include <gtest/gtest.h>
#include <memory>

using namespace ocira::core;
using namespace ocira::core::components;

/// @brief Test Capacitor class constructor.
TEST(capacitor, constructor_works) {
  // Create new Capacitor object.
  Capacitor capacitor(1, 5.0f);
  // Expect equality.
  EXPECT_EQ(capacitor.getId(), 1);
  EXPECT_FLOAT_EQ(capacitor.getCapacitance(), 5.0f);
}

/// @brief Test capacitance setter.
TEST(capacitor, set_capacitance) {
  // Create new Capacitor object.
  Capacitor capacitor(1, 5.0);
  // Set new capacitance.
  capacitor.setCapacitance(10.0f);
  // Expect equality.
  EXPECT_FLOAT_EQ(capacitor.getCapacitance(), 10.0f);
}

/// @brief Test capacitance setter.
TEST(capacitor, get_impedance) {
  // Create new Capacitor object.
  Capacitor capacitor(1, 5.0);
  // Get admittance.
  auto admittance = capacitor.getImpedance(50);
  // Expect equality.
  EXPECT_FLOAT_EQ(admittance.real(), 0.0f);
  EXPECT_FLOAT_EQ(admittance.imag(), -0.00063661975f);
}

/// @brief Test get admittance.
TEST(capacitor, get_admittance) {
  // Create new Capacitor object.
  Capacitor capacitor(1, 5.0);
  // Get admittance.
  auto admittance = capacitor.getAdmittance(50);
  // Expect equality.
  EXPECT_FLOAT_EQ(admittance.real(), 0.0f);
  EXPECT_FLOAT_EQ(admittance.imag(), 1570.7964f);
}