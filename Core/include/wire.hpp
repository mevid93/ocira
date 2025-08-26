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
// - 2025-08-25 Martin Vidjeskog: Initial creation
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

/// @brief A wire component class. Basically just a ideal short circuit.
class Wire : public Component {
public:
  /// @brief Constructor for Wire class.
  /// @param id Component id.
  explicit Wire(ComponentId id);

  /// @brief Destructor.
  ~Wire();

private:
};
} // namespace ocira::core

#endif