//==============================================================================
// File:        test_ground.cpp
// Author:      Martin Vidjeskog
// Created:     2025-08-26
// Description: Unit tests for Ground class in OCIRA core library.
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
// - Tests cover Ground class.
// - Run with: ctest or ./core_tests or ./core_tests --gtest_filter=ground.*
//==============================================================================

#include "ground.hpp"
#include <gtest/gtest.h>

using namespace ocira::core;
using namespace ocira::core::components;

/// @brief Test Ground class constructor.
TEST(ground, constructor_works) {
  // Create new Ground object.
  Ground ground(1);
  // Expect equality.
  EXPECT_EQ(ground.getId(), 1);
  EXPECT_EQ(ground.getComponentType(), ComponentType::GROUND);
}