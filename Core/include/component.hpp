//==============================================================================
// Project:     OCIRA (core library)
// File:        component.hpp
// Author:      Martin Vidjeskog
// Created:     2025-08-26
// Description: Circuit component base model.
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

#ifndef OCIRA_CORE_COMPONENT_HPP
#define OCIRA_CORE_COMPONENT_HPP

#include "circuit_structs.hpp"
#include <memory>
#include <vector>

namespace ocira::core {

// Forward declarations.
class Bus;

/// @brief Unique identifier for a circuit component.
using ComponentId = uint32_t;

/// @brief Abstract base class representing a circuit component.
/// Components act as edges in the circuit graph, connecting buses (nodes).
class Component {
public:
  /// @brief Constructs a component with a unique identifier.
  /// @param id Unique component ID.
  explicit Component(ComponentId id);

  /// @brief Virtual destructor to support polymorphic deletion.
  virtual ~Component();

  /// @brief Retrieves the component's unique identifier.
  /// @return Component ID.
  ComponentId getId() const;

  /// @brief Retrieves the type of the component.
  /// @return Component type (e.g., resistor, source).
  ComponentType getComponentType() const;

  /// @brief Connects the component to a bus with a specified terminal role.
  /// @param bus Weak pointer to the bus to connect.
  /// @param role Terminal role (positive or negative).
  /// @return True if the connection was successful; false if already connected.
  virtual bool addConnection(std::weak_ptr<Bus> bus, TerminalRole role);

  /// @brief Removes the connection to a specified bus.
  /// @param bus Weak pointer to the bus to disconnect.
  /// @return True if the connection was removed; false if not found.
  bool removeConnection(std::weak_ptr<Bus> bus);

  /// @brief Checks whether the component is connected to a given bus.
  /// @param bus Weak pointer to the bus to check.
  /// @return True if connected; false otherwise.
  bool isConnectedToBus(std::weak_ptr<Bus> bus) const;

  /// @brief Retrieves all connections to buses.
  /// @return Const reference to the vector of connections.
  const std::vector<Connection> &getConnections() const;

  /// @brief Determines whether the component is fully connected to all required buses.
  /// @return True if the component is fully connected; false otherwise.
  virtual bool isConnected() const;

protected:
  ComponentType m_type = ComponentType::UNDEFINED;
  std::vector<Connection> m_connections;

private:
  ComponentId m_id;
};
} // namespace ocira::core

#endif // OCIRA_CORE_COMPONENT_HPP