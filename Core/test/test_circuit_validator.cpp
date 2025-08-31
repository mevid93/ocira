//==============================================================================
// File:        test_circuit_validator.cpp
// Author:      Martin Vidjeskog
// Created:     2025-08-26
// Description: Unit tests for CircuitValidator class in OCIRA core library.
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
// - Tests cover CircuitValidator class.
// - Run with: ctest or ./core_tests or ./core_tests --gtest_filter=circuit_validator.*
//==============================================================================

#include "bus.hpp"
#include "circuit.hpp"
#include "circuit_structs.hpp"
#include "circuit_validator.hpp"
#include "component.hpp"
#include "dc_current_source.hpp"
#include "example_circuit_generator.hpp"
#include <algorithm>
#include <gtest/gtest.h>
#include <memory>

using namespace ocira::core;
using namespace ocira::core::components;
using namespace ocira::core::test::helpers;

/// @brief Test CircuitValidator with example circuit 1.
TEST(circuit_validator, example_circuit_1) {
  // Get example circuit 1.
  auto circuit = ExampleCircuitGenerator::getExampleCircuit1();
  // Validate the circuit.
  ValidationResult result = CircuitValidator::isValidCircuit(*circuit);
  // Verify results.
  EXPECT_TRUE(result.isValid);
  EXPECT_TRUE(result.errors.empty());
}

/// @brief Test validation for circuit that has unconnected buses.
TEST(circuit_validator, unconnected_buses) {
  // Create circuit.
  Circuit circuit;
  // Add buses to circuit.
  std::vector<std::shared_ptr<Bus>> buses;
  buses.push_back(std::make_shared<Bus>(1));
  circuit.setBuses(buses);
  // Validate the circuit.
  ValidationResult result = CircuitValidator::isValidCircuit(circuit);
  // Verify results.
  EXPECT_FALSE(result.isValid);
  EXPECT_TRUE(!result.errors.empty());
  auto it =
      std::find_if(result.errors.begin(), result.errors.end(), [](const ValidationError &error) {
        return error.code == ValidationErrorCode::UNCONNECTED_BUS;
      });
  EXPECT_TRUE(it != result.errors.end());
}

/// @brief Test validation for circuit that has unconnected components.
TEST(circuit_validator, unconnected_components) {
  // Create circuit.
  Circuit circuit;
  // Add components to circuit.
  std::vector<std::shared_ptr<Component>> components;
  components.push_back(std::make_shared<Component>(1));
  circuit.setComponents(components);
  // Validate the circuit.
  ValidationResult result = CircuitValidator::isValidCircuit(circuit);
  // Verify results.
  EXPECT_FALSE(result.isValid);
  EXPECT_TRUE(!result.errors.empty());
  auto it =
      std::find_if(result.errors.begin(), result.errors.end(), [](const ValidationError &error) {
        return error.code == ValidationErrorCode::UNCONNECTED_COMPONENT;
      });
  EXPECT_TRUE(it != result.errors.end());
}

/// @brief Test validation for circuit that is missing ground component.
TEST(circuit_validator, ground_component_missing) {
  // Create circuit.
  Circuit circuit;
  // Validate the circuit.
  ValidationResult result = CircuitValidator::isValidCircuit(circuit);
  // Verify results.
  EXPECT_FALSE(result.isValid);
  EXPECT_TRUE(!result.errors.empty());
  auto it =
      std::find_if(result.errors.begin(), result.errors.end(), [](const ValidationError &error) {
        return error.code == ValidationErrorCode::GROUND_COMPONENT_MISSING;
      });
  EXPECT_TRUE(it != result.errors.end());
}

/// @brief Test validation for circuit that has duplicate identifier among buses.
TEST(circuit_validator, duplicate_identifier_among_buses) {
  // Create circuit.
  Circuit circuit;
  // Add buses to circuit.
  std::vector<std::shared_ptr<Bus>> buses;
  buses.push_back(std::make_shared<Bus>(1));
  buses.push_back(std::make_shared<Bus>(1));
  circuit.setBuses(buses);
  // Validate the circuit.
  ValidationResult result = CircuitValidator::isValidCircuit(circuit);
  // Verify results.
  EXPECT_FALSE(result.isValid);
  EXPECT_TRUE(!result.errors.empty());
  auto it =
      std::find_if(result.errors.begin(), result.errors.end(), [](const ValidationError &error) {
        return error.code == ValidationErrorCode::DUPLICATE_IDENTIFIER;
      });
  EXPECT_TRUE(it != result.errors.end());
}

/// @brief Test validation for circuit that has duplicate identifier among components.
TEST(circuit_validator, duplicate_identifier_among_components) {
  // Create circuit.
  Circuit circuit;
  // Add components to circuit.
  std::vector<std::shared_ptr<Component>> components;
  components.push_back(std::make_shared<Component>(1));
  components.push_back(std::make_shared<Component>(1));
  circuit.setComponents(components);
  // Validate the circuit.
  ValidationResult result = CircuitValidator::isValidCircuit(circuit);
  // Verify results.
  EXPECT_FALSE(result.isValid);
  EXPECT_TRUE(!result.errors.empty());
  auto it =
      std::find_if(result.errors.begin(), result.errors.end(), [](const ValidationError &error) {
        return error.code == ValidationErrorCode::DUPLICATE_IDENTIFIER;
      });
  EXPECT_TRUE(it != result.errors.end());
}

/// @brief Test validation for circuit with incompatible components for selected simulation mode.
TEST(circuit_validator, incompatible_component_for_ac_simulation) {
  // Create circuit.
  Circuit circuit(SimulationMode::AC);
  // Add components to circuit.
  std::vector<std::shared_ptr<Component>> components;
  components.push_back(std::make_shared<DCCurrentSource>(1, 200));
  circuit.setComponents(components);
  // Validate the circuit.
  ValidationResult result = CircuitValidator::isValidCircuit(circuit);
  // Verify results.
  EXPECT_FALSE(result.isValid);
  EXPECT_TRUE(!result.errors.empty());
  auto it =
      std::find_if(result.errors.begin(), result.errors.end(), [](const ValidationError &error) {
        return error.code == ValidationErrorCode::INCOMPATIBLE_COMPONENT_FOR_AC_SIMULATION;
      });
  EXPECT_TRUE(it != result.errors.end());
}

/// @brief Test validation for circuit with incompatible components for selected simulation mode.
TEST(circuit_validator, incompatible_component_for_dc_simulation) {
  // Create circuit.
  Circuit circuit(SimulationMode::DC);
  // Add components to circuit.
  std::vector<std::shared_ptr<Component>> components;
  components.push_back(std::make_shared<Component>(1));
  circuit.setComponents(components);
  // Validate the circuit.
  ValidationResult result = CircuitValidator::isValidCircuit(circuit);
  // Verify results.
  EXPECT_FALSE(result.isValid);
  EXPECT_TRUE(!result.errors.empty());
  auto it =
      std::find_if(result.errors.begin(), result.errors.end(), [](const ValidationError &error) {
        return error.code == ValidationErrorCode::INCOMPATIBLE_COMPONENT_FOR_DC_SIMULATION;
      });
  EXPECT_TRUE(it != result.errors.end());
}

/// @brief Test validation for circuit that is not fully connected. In other words, it has buses
/// that cannot be reached from one other.
TEST(circuit_validator, circuit_not_fully_connected) {
  // Create circuit.
  Circuit circuit;
  // Add buses to circuit.
  std::vector<std::shared_ptr<Bus>> buses;
  buses.push_back(std::make_shared<Bus>(1));
  buses.push_back(std::make_shared<Bus>(2));
  circuit.setBuses(buses);
  // Validate the circuit.
  ValidationResult result = CircuitValidator::isValidCircuit(circuit);
  // Verify results.
  EXPECT_FALSE(result.isValid);
  EXPECT_TRUE(!result.errors.empty());
  auto it =
      std::find_if(result.errors.begin(), result.errors.end(), [](const ValidationError &error) {
        return error.code == ValidationErrorCode::CIRCUIT_NOT_FULLY_CONNECTED;
      });
  EXPECT_TRUE(it != result.errors.end());
}