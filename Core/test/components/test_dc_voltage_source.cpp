//==============================================================================
// File:        test_dc_voltage_source.cpp
// Author:      Martin Vidjeskog
// Created:     2025-09-05
// Description: Unit tests for DCVoltageSource class in OCIRA core library.
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
// - Tests cover DCVoltageSource class.
// - Run with: ctest or ./core_tests or ./core_tests --gtest_filter=dc_voltage_source.*
//==============================================================================

#include "dc_voltage_source.hpp"
#include <gtest/gtest.h>

using namespace ocira::core;
using namespace ocira::core::components;

/// @brief Test DCVoltageSource class constructor.
TEST(dc_voltage_source, constructor_works) {
  // Create new DCVoltageSource object.
  DCVoltageSource dcVoltageSource(1, 100);
  // Expect equality.
  EXPECT_EQ(dcVoltageSource.getId(), 1);
  EXPECT_EQ(dcVoltageSource.getComponentType(), ComponentType::DC_VOLTAGE_SOURCE);
  EXPECT_EQ(dcVoltageSource.getVolts(), 100);
}

/// @brief Test voltage level setter and getter.
TEST(dc_voltage_source, set_volts) {
  // Create new DCVoltageSource object.
  DCVoltageSource dcVoltageSource(1, 100);
  // Set new voltage level.
  dcVoltageSource.setVolts(200.5);
  // Expect equality.
  EXPECT_EQ(dcVoltageSource.getVolts(), 200.5);
}