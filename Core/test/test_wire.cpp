//==============================================================================
// File:        test_wire.cpp
// Author:      Martin Vidjeskog
// Created:     2025-08-26
// Description: Unit tests for Wire class in OCIRA core library.
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
// - Tests cover Wire class.
// - Run with: ctest or ./core_tests or ./core_tests --gtest_filter=wire.*
//==============================================================================

#include "wire.hpp"
#include <gtest/gtest.h>

using namespace ocira::core;

/// @brief Test Wire class constructor.
TEST(wire, constructor_works) {
  // Create new Wire object.
  Wire wire(1);
  // Expect equality.
  EXPECT_EQ(wire.getId(), 1);
  EXPECT_EQ(wire.getComponentType(), ComponentType::WIRE);
}