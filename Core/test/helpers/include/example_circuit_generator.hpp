//==============================================================================
// Project:     OCIRA (core library tests)
// File:        example_circuit_generator.hpp
// Author:      Martin Vidjeskog
// Created:     2025-09-01
// Description: Utility class to generate example circuits.
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
// Revision History:
// - 2025-08-26 Martin Vidjeskog: Initial creation
// - 2025-09-01 Martin Vidjeskog: Use ConnectionManager when building circuits.
// - [YYYY-MM-DD] [Contributor]: [Description of change]
//==============================================================================
// Notes:
// - Please retain this header in all redistributed versions.
//==============================================================================

#ifndef OCIRA_CORE_TEST_HELPERS_EXAMPLE_CIRCUIT_GENERATOR_HPP
#define OCIRA_CORE_TEST_HELPERS_EXAMPLE_CIRCUIT_GENERATOR_HPP

#include <memory>

namespace ocira::core {

// Forward declarations.
class Circuit;

} // namespace ocira::core

namespace ocira::core::test::helpers {

/// @brief Utility class for generating example circuits for testing purposes.
/// This class provides static factory methods to create predefined circuit configurations.
class ExampleCircuitGenerator {
public:
  /// @brief Make the class non-instantiable.
  ExampleCircuitGenerator() = delete;

  /// @brief Generates a simple example circuit.
  /// The circuit contains:
  /// - One resistor
  /// - One DC current source
  /// Useful for basic validation and simulation tests.
  /// @return Shared pointer to the generated Circuit instance.
  static std::shared_ptr<ocira::core::Circuit> getExampleCircuit1();
};
} // namespace ocira::core::test::helpers

#endif // OCIRA_CORE_TEST_UTILS_EXAMPLE_CIRCUIT_GENERATOR_HPP
