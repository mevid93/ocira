//==============================================================================
// Project:     OCIRA (core library)
// File:        circuit_structs.hpp
// Author:      Martin Vidjeskog
// Created:     2025-08-26
// Description: All circuit structs.
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
// - [YYYY-MM-DD] [Contributor]: [Description of change]
//==============================================================================
// Notes:
// - Please retain this header in all redistributed versions.
//==============================================================================

#ifndef OCIRA_CORE_CIRCUIT_STRUCTS_HPP
#define OCIRA_CORE_CIRCUIT_STRUCTS_HPP

#include "circuit_enums.hpp"
#include <memory>
#include <string>
#include <vector>

namespace ocira::core {

class Bus;

/// @brief Represents a connection between a component and a bus within a circuit.
/// Each connection specifies the bus being connected to and the role of the terminal.
struct Connection {
  std::weak_ptr<Bus> bus;
  TerminalRole role;
};

/// @brief Describes a single validation error encountered during circuit analysis.
/// Includes a human-readable message, an error code for programmatic handling,
/// and an optional location string to pinpoint where the error occurred.
struct ValidationError {
  std::string message;
  ValidationErrorCode code;
  std::string location;
};

/// @brief Represents the outcome of a validation process.
/// If the result is valid, no errors are present. Otherwise, the errors vector contains
/// detailed information about each issue encountered.
struct ValidationResult {
  bool isValid;
  std::vector<ValidationError> errors;
};

} // namespace ocira::core

#endif // OCIRA_CORE_CIRCUIT_STRUCTS_HPP