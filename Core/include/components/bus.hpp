//==============================================================================
// Project:     OCIRA (core library)
// File:        bus.hpp
// Author:      Martin Vidjeskog
// Created:     2025-08-26
// Description: Bus component model. This is a node in a circuit graph.
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

#ifndef OCIRA_CORE_BUS_HPP
#define OCIRA_CORE_BUS_HPP

#include <memory>
#include <vector>

namespace ocira::core::components {

// Forward declarations.
class Component;

/// @brief Unique identifier for a bus in a circuit.
/// Each bus must have a distinct BusId.
using BusId = uint32_t;

/// @brief Represents a junction point in an electrical circuit.
/// A Bus connects multiple components and serves as a node in the circuit graph.
class Bus {
public:
  /// @brief Constructs a bus with a given identifier.
  /// @param id Unique identifier for the bus.
  explicit Bus(BusId id);

  /// @brief Default destructor.
  ~Bus() = default;

  /// @brief Retrieves the unique identifier of the bus.
  /// @return BusId associated with this bus.
  BusId getId() const noexcept;

  /// @brief Connects a component to this bus.
  /// Adds the component to the internal list if it's not already connected.
  /// @param component Shared pointer to the component to connect.
  /// @return True if the component was successfully connected; false if already connected.
  bool addConnection(const std::shared_ptr<Component> &component);

  /// @brief Disconnects a component from this bus.
  /// Removes the component from the internal list if it exists.
  /// @param component Shared pointer to the component to disconnect.
  /// @return True if the component was successfully disconnected; false if not found.
  bool removeConnection(const std::shared_ptr<Component> &component);

  /// @brief Returns all components currently connected to this bus.
  /// @return Const reference to the vector of connected components.
  const std::vector<std::shared_ptr<Component>> &getComponents() const;

  /// @brief Checks whether a specific component is connected to this bus.
  /// @param component Shared pointer to the component to check.
  /// @return True if the component is connected; false otherwise.
  bool isConnectedToComponent(const std::shared_ptr<Component> &component) const;

  /// @brief Returns the total number of components connected to this bus.
  /// @return Count of connected components.
  uint32_t getNumberOfComponents() const noexcept;

  /// @brief Checks whether a bus is connected to any component or not.
  /// @return True if bus is connected to any component, false otherwise.
  bool isConnected() const noexcept;

  /// @brief Retrieves buses that are connected to this bus via components.
  /// @return A vector of weak pointers to buses linked through at least one component.
  const std::vector<std::weak_ptr<Bus>> getNeighborBuses() const;

private:
  BusId m_id;
  std::vector<std::shared_ptr<Component>> m_components;
};
} // namespace ocira::core::components

#endif // OCIRA_CORE_BUS_HPP
