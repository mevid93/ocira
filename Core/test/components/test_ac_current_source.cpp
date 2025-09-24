//==============================================================================
// File:        test_ac_current_source.cpp
// Author:      Martin Vidjeskog
// Created:     2025-09-17
// Description: Unit tests for ACCurrentSource class in OCIRA core library.
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
// - Tests cover ACCurrentSource class.
// - Run with: ctest or ./core_tests or ./core_tests --gtest_filter=ac_current_source.*
//==============================================================================

#include "ac_current_source.hpp"
#include <gtest/gtest.h>

using namespace ocira::core;
using namespace ocira::core::components;

/// @brief Test ACCurrentSource class constructor.
TEST(ac_current_source, constructor_works) {
  // Create new ACCurrentSource object.
  ACCurrentSource acCurrentSource(1, 100, 20);
  // Expect equality.
  EXPECT_EQ(acCurrentSource.getId(), 1);
  EXPECT_EQ(acCurrentSource.getComponentType(), ComponentType::AC_CURRENT_SOURCE);
  EXPECT_FLOAT_EQ(acCurrentSource.getAmplitude(), 100);
  EXPECT_FLOAT_EQ(acCurrentSource.getPhase(), 20);
}

/// @brief Test amplitude setter and getter.
TEST(ac_current_source, set_amplitude) {
  // Create new ACCurrentSource object.
  ACCurrentSource acCurrentSource(1, 100);
  // Set new amps value.
  acCurrentSource.setAmplitude(200);
  // Expect equality.
  EXPECT_FLOAT_EQ(acCurrentSource.getAmplitude(), 200);
}

/// @brief Test phase setter and getter.
TEST(ac_current_source, set_phase) {
  // Create new ACCurrentSource object.
  ACCurrentSource acCurrentSource(1, 100);
  // Set new amps value.
  acCurrentSource.setPhase(90.0f);
  // Expect equality.
  EXPECT_FLOAT_EQ(acCurrentSource.getPhase(), 90.0f);
}

/// @brief Test phasor getter.
TEST(ac_current_source, get_phasor) {
  // Create new ACCurrentSource object.
  ACCurrentSource acCurrentSource(1, 100, 60.0f);
  // Get phasor representation.
  std::complex<float> phasor = acCurrentSource.getPhasor();
  // Expect equality.
  EXPECT_FLOAT_EQ(phasor.real(), 50.0f);
  EXPECT_FLOAT_EQ(phasor.imag(), 86.602539f);
}