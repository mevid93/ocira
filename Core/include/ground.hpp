//==============================================================================
// Project:     OCIRA (core library)
// File:        ground.hpp
// Author:      Martin Vidjeskog
// Created:     2025-08-26
// Description: Ground component model.
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

#ifndef OCIRA_CORE_GROUND_HPP
#define OCIRA_CORE_GROUND_HPP

#include "component.hpp"
#include <cstdint>

namespace ocira::core {

/// @brief Represents the ground in a circuit. The ground component serves as the reference point
/// for voltage calculations. Every circuit should contain exactly one ground, which connects to a
/// single bus. It typically defines the zero-voltage level in circuit analysis.
class Ground final : public Component {
public:
  /// @brief Constructs a ground component with a unique ID.
  /// @param id Unique identifier for the ground component.
  explicit Ground(ComponentId id);

  /// @brief Destructor for the ground component.
  /// Declared virtual to support polymorphic cleanup.
  ~Ground() override = default;

  /// @brief Connects the ground to a bus. Ground should only connect to one bus.
  /// @param bus Weak pointer to the bus to connect.
  /// @param role Terminal role of the connection.
  /// @return True if the connection was successfully added; false otherwise.
  bool addConnection(std::weak_ptr<Bus> bus, TerminalRole role) override;

  /// @brief Checks whether the component is fully connected to all required buses.
  /// @return True if the component meets all connection requirements; false otherwise.
  virtual bool isConnected() const override;

private:
};
} // namespace ocira::core

#endif // OCIRA_CORE_GROUND_HPP