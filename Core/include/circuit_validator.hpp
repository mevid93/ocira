//==============================================================================
// Project:     OCIRA (core library)
// File:        circuit_validator.hpp
// Author:      Martin Vidjeskog
// Created:     2025-08-28
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
// - 2025-08-28 Martin Vidjeskog: Initial creation
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
  /// @brief Validates that every bus in the circuit is properly connected to at least one
  /// component. Flags any buses that are left unconnected or floating, which may indicate design
  /// errors.
  /// @param circuit The circuit structure containing buses and components.
  /// @param result  The validation result object used to collect errors and warnings.
  static void _validateBusConnections(const Circuit &circuit, ValidationResult &result);

  /// @brief Validates that all components within the circuit are properly connected to their
  /// required buses. Detects and reports any components with missing or incmplete connections.
  /// @param circuit The circuit model containing components and their connectivity data.
  /// @param result  The validation result object used to collect errors and warnings.
  static void _validateComponentConnections(const Circuit &circuit, ValidationResult &result);

  /// @brief Validates the grounding configuration of the circuit to ensure that circuit has exactly
  /// one ground component.
  /// @param circuit The circuit model containing components and their connectivity data.
  /// @param result  The validation result object used to collect errors and warnings.
  static void _validateGround(const Circuit &circuit, ValidationResult &result);

  /// @brief Validates that all components in the circuit support the circuit's simulation mode (AC
  /// or DC).
  /// @param circuit The circuit model containing components and their connectivity data.
  /// @param result  The validation result object used to collect errors and warnings.
  static void _validateSimulationModeCompatibility(const Circuit &circuit,
                                                   ValidationResult &result);

  /// @brief Validates that all buses and components in the circuit have unique identifiers.
  /// @param circuit The circuit model containing buses, components, and their connectivity data.
  /// @param result  The validation result object used to collect errors and warnings.
  static void _validateUniqueIds(const Circuit &circuit, ValidationResult &result);

  /// @brief Validates that all buses in the circuit are reachable from one another, ensuring full
  /// connectivity.
  /// @param circuit The circuit model containing buses, components, and their connectivity data.
  /// @param result  The validation result object used to collect errors and warnings.
  static void _validateConnectivity(const Circuit &circuit, ValidationResult &result);
};
}; // namespace ocira::core

#endif // OCIRA_CORE_CIRCUIT_VALIDATOR_HPP