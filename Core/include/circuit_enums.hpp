//==============================================================================
// Project:     OCIRA (core library)
// File:        circuit_enums.hpp
// Author:      Martin Vidjeskog
// Created:     2025-08-26
// Description: All circuit enums.
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

#ifndef OCIRA_CORE_CIRCUIT_ENUMS_HPP
#define OCIRA_CORE_CIRCUIT_ENUMS_HPP

namespace ocira::core {

/// @brief Supported types of circuit components. Used to classify components during parsing,
/// validation, and simulation.
enum class ComponentType {
  AC_CURRENT_SOURCE,
  AC_VOLTAGE_SOURCE,
  CAPACITOR,
  DC_CURRENT_SOURCE,
  DC_VOLTAGE_SOURCE,
  GROUND,
  IMPEDANCE,
  INDUCTOR,
  RESISTOR,
  UNDEFINED,
  WIRE,
};

/// @brief Defines the role of a terminal in a component.
/// Typically used to determine polarity or connection direction.
enum class TerminalRole { POSITIVE, NEGATIVE };

/// @brief Specifies the simulation mode for the circuit.
/// Determines how components behave and which equations are applied.
enum class SimulationMode { DC, AC };

/// @brief Validation error codes for circuit analysis.
/// Error codes are grouped by category:
/// - 1000–1999: Structural errors (e.g., missing connections)
/// - 2000–2999: Logical errors (e.g., conflicting components)
/// - 3000–3999: Timing or simulation errors
enum class ValidationErrorCode {
  DUPLICATE_IDENTIFIER = 1001,
  UNCONNECTED_BUS = 1002,
  UNCONNECTED_COMPONENT = 1003,
  MULTIPLE_CIRCUITS_INSTEAD_OF_ONE = 1004,
  DC_CIRCUIT_CONTAINS_AC_COMPONENTS = 2000,
  AC_CIRCUIT_CONTAINS_DC_COMPONENTS = 2001,
  EARTH_COMPONENT_MISSING = 2002,
};

} // namespace ocira::core

#endif // OCIRA_CORE_CIRCUIT_ENUMS_HPP