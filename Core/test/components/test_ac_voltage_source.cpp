//==============================================================================
// File:        test_ac_voltage_source.cpp
// Author:      Martin Vidjeskog
// Created:     2025-09-25
// Description: Unit tests for ACVoltageSource class in OCIRA core library.
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
// - Tests cover ACVoltageSource class.
// - Run with: ctest or ./core_tests or ./core_tests --gtest_filter=ac_voltage_source.*
//==============================================================================

#include "ac_voltage_source.hpp"
#include <gtest/gtest.h>

using namespace ocira::core;
using namespace ocira::core::components;

/// @brief Test ACVoltageSource class constructor.
TEST(ac_voltage_source, constructor_works) {
  // Create new ACVoltageSource object.
  ACVoltageSource acVoltageSource(1, 100, 20);
  // Expect equality.
  EXPECT_EQ(acVoltageSource.getId(), 1);
  EXPECT_EQ(acVoltageSource.getComponentType(), ComponentType::AC_VOLTAGE_SOURCE);
  EXPECT_FLOAT_EQ(acVoltageSource.getAmplitude(), 100);
  EXPECT_FLOAT_EQ(acVoltageSource.getPhase(), 20);
}

/// @brief Test amplitude setter and getter.
TEST(ac_voltage_source, set_amplitude) {
  // Create new ACVoltageSource object.
  ACVoltageSource acVoltageSource(1, 100);
  // Set new amps value.
  acVoltageSource.setAmplitude(200);
  // Expect equality.
  EXPECT_FLOAT_EQ(acVoltageSource.getAmplitude(), 200);
}

/// @brief Test phase setter and getter.
TEST(ac_voltage_source, set_phase) {
  // Create new ACVoltageSource object.
  ACVoltageSource acVoltageSource(1, 100);
  // Set new amps value.
  acVoltageSource.setPhase(90.0f);
  // Expect equality.
  EXPECT_FLOAT_EQ(acVoltageSource.getPhase(), 90.0f);
}

/// @brief Test phasor getter.
TEST(ac_voltage_source, get_phasor) {
  // Create new ACVoltageSource object.
  ACVoltageSource acVoltageSource(1, 5, 60.0f);
  // Get phasor representation.
  std::complex<float> phasor = acVoltageSource.getPhasor();
  // Expect equality.
  EXPECT_FLOAT_EQ(phasor.real(), 2.5f);
  EXPECT_FLOAT_EQ(phasor.imag(), 4.3301272f);
}