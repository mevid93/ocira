//==============================================================================
// Project:     OCIRA (core library)
// File:        circuit_validator.hpp
// Author:      Martin Vidjeskog
// Created:     2025-08-26
// Description: Circuit validation logic.
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

#ifndef OCIRA_CORE_CIRCUIT_VALIDATOR_HPP
#define OCIRA_CORE_CIRCUIT_VALIDATOR_HPP

namespace ocira::core {

/// Forward declarations.
class Circuit;
struct ValidationResult;

/// @brief Provides static methods for validating the structure of a circuit.
/// This class cannot be instantiated.
class CircuitValidator {
public:
  /// @brief Make the class non-instantiable.
  CircuitValidator() = delete;

  /// @brief Validates the structure of the given circuit.
  /// Checks for connectivity, grounding, and component compatibility.
  /// @param circuit Reference to the circuit to validate.
  /// @return A ValidationResult containing error codes and diagnostics.
  static ValidationResult isValidCircuit(const Circuit &circuit);

private:
};
}; // namespace ocira::core

#endif // OCIRA_CORE_CIRCUIT_VALIDATOR_HPP