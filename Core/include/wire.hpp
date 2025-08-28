//==============================================================================
// Project:     OCIRA (core library)
// File:        wire.hpp
// Author:      Martin Vidjeskog
// Created:     2025-08-26
// Description: Wire component model.
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

#ifndef OCIRA_CORE_WIRE_HPP
#define OCIRA_CORE_WIRE_HPP

#include "component.hpp"
#include <cstdint>

namespace ocira::core {

/// @brief Represents an ideal wire component in the circuit simulation.
/// This class models a perfect conductor with zero resistance, effectively
/// acting as a short circuit between connected nodes. It inherits from the
/// Component base class and overrides relevant behavior to reflect its ideal nature.
class Wire final : public Component {
public:
  /// @brief Constructs a Wire component with a unique identifier.
  /// Typically used to connect circuit nodes without introducing any resistance or delay.
  /// @param id The unique ID assigned to this wire instance.
  explicit Wire(ComponentId id);

  /// @brief Destructor for Wire.
  /// Declared virtual to support polymorphic cleanup.
  ~Wire() override = default;

private:
};
} // namespace ocira::core

#endif // OCIRA_CORE_WIRE_HPP