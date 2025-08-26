//==============================================================================
// Project:     OCIRA (core library tests)
// File:        example_circuit_generator.hpp
// Author:      Martin Vidjeskog
// Created:     2025-08-26
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
// - 2025-08-25 Martin Vidjeskog: Initial creation
// - [YYYY-MM-DD] [Contributor]: [Description of change]
//==============================================================================
// Notes:
// - Please retain this header in all redistributed versions.
//==============================================================================

#ifndef OCIRA_CORE_TEST_UTILS_EXAMPLE_CIRCUIT_GENERATOR_HPP
#define OCIRA_CORE_TEST_UTILS_EXAMPLE_CIRCUIT_GENERATOR_HPP

#include "circuit.hpp"
#include "component.hpp"
#include <vector>

namespace ocira::core::test::utils {

/// @brief ExampleCircuitGenerator class. Provides static functions to generate example circuits
/// that can be used in unit tests.
class ExampleCircuitGenerator {
public:
  /// @brief Returns example circuit 1. Circuit contains one resistor and one dc current source.
  /// @return Example circuit 1.
  static std::shared_ptr<Circuit> getExampleCircuit1();
};
} // namespace ocira::core::test::utils

#endif
