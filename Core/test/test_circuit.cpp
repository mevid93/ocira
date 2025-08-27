//==============================================================================
// File:        test_circuit.cpp
// Author:      Martin Vidjeskog
// Created:     2025-08-26
// Description: Unit tests for Circuit class in OCIRA core library.
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
// - Tests cover Circuit class.
// - Run with: ctest or ./core_tests or ./core_tests --gtest_filter=circuit.*
//==============================================================================

#include "bus.hpp"
#include "circuit.hpp"
#include "component.hpp"
#include <gtest/gtest.h>
#include <memory>

using namespace ocira::core;

/// @brief Test Circuit class default constructor.
TEST(circuit, constructor_works) {
  // Create new circuit.
  Circuit circuit;
  // Verify results.
  EXPECT_EQ(circuit.getSimulationMode(), SimulationMode::DC);
}

/// @brief Test Circuit class constructor that takes simulation mode as parameter.
TEST(circuit, constructor_works_with_simulation_mode) {
  // Create new circuit.
  Circuit circuit(SimulationMode::AC);
  // Verify results.
  EXPECT_EQ(circuit.getSimulationMode(), SimulationMode::AC);
}

/// @brief Test setting circuit components.
TEST(circuit, set_components) {
  // Create new circuit.
  Circuit circuit;
  // Create components.
  std::vector<std::shared_ptr<Component>> components;
  components.push_back(std::make_shared<Component>(1));
  components.push_back(std::make_shared<Component>(2));
  // Set components to circuit.
  circuit.setComponents(components);
  // Verify that operation was succesful.
  EXPECT_EQ(circuit.getComponents().size(), 2);
  EXPECT_EQ(circuit.getComponents().at(1)->getId(), 2);
}

/// @brief Test setting circuit buses.
TEST(circuit, set_buses) {
  // Create new circuit.
  Circuit circuit;
  // Create buses.
  std::vector<std::shared_ptr<Bus>> buses;
  buses.push_back(std::make_shared<Bus>(1));
  buses.push_back(std::make_shared<Bus>(2));
  // Set buses to circuit.
  circuit.setBuses(buses);
  // Verify that operation was succesful.
  EXPECT_EQ(circuit.getBuses().size(), 2);
  EXPECT_EQ(circuit.getBuses().at(1)->getId(), 2);
}
