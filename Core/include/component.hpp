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
// - 2025-08-25 Martin Vidjeskog: Initial creation
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

class Bus;

/// @brief Component id. Each component should have a unique id.
using ComponentId = uint32_t;

/// @brief Base component class. Components are edges in circuit graph.
class Component {
public:
  /// @brief Constructor.
  /// @param id Component id.
  explicit Component(const ComponentId id);

  /// @brief Destructor.
  ~Component();

  /// @brief Returns component id.
  /// @return Component id.
  ComponentId getId() const;

  /// @brief Returns component type.
  /// @return Component type.
  ComponentType getComponentType() const;

  /// @brief Connect component to a bus.
  /// @param bus Bus to connect.
  /// @param role Terminel role of the new connection.
  /// @return True if bus was connected. False otherwise.
  virtual bool addConnection(std::weak_ptr<Bus> bus, TerminalRole role);

  /// @brief Remove connection from component.
  /// @param bus Bus to disconnect.
  /// @return True if bus was disconnected. False otherwise.
  bool removeConnection(std::weak_ptr<Bus> bus);

  /// @brief Check if component is connected to the bus.
  /// @param bus Bus to check.
  /// @return True if component is connected to bus. False otherwise.
  bool isConnectedToBus(std::weak_ptr<Bus> bus) const;

  /// @brief Get connections to buses.
  /// @return Connections to buses.
  const std::vector<Connection> &getConnections() const;

protected:
  ComponentType m_type;
  std::vector<Connection> m_connections;

private:
  ComponentId m_id;
};
} // namespace ocira::core

#endif