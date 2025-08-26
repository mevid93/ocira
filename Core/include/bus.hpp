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
// - 2025-08-25 Martin Vidjeskog: Initial creation
// - [YYYY-MM-DD] [Contributor]: [Description of change]
//==============================================================================
// Notes:
// - Please retain this header in all redistributed versions.
//==============================================================================

#ifndef OCIRA_CORE_BUS_HPP
#define OCIRA_CORE_BUS_HPP

#include "component.hpp"
#include <vector>

namespace ocira::core {

/// @brief Bus id. Each bus in a circuit should have a unique identifier.
using BusId = uint32_t;

/// @brief Bus class. These are the junctions in a circuit graph.
class Bus {
public:
  /// @brief Constructor.
  /// @param id Bus id.
  explicit Bus(BusId id);

  /// @brief Destructor.
  ~Bus();

  /// @brief Returns bus id.
  /// @return Bus id.
  BusId getId() const;

  /// @brief Connect a new component to the bus.
  /// @param component Component to connect.
  /// @return True if component was connected. False otherwise.
  bool connectComponent(std::shared_ptr<Component> component);

  /// @brief Disconnet a component from the bus.
  /// @param component Component to diconnect.
  /// @return True if component was disconnected. False otherwise.
  bool disconnectComponent(std::shared_ptr<Component> component);

  /// @brief Get all components that are connected to the bus.
  /// @return Connected components.
  const std::vector<std::shared_ptr<Component>> &getComponents() const;

  /// @brief Check if bus is connected to given component.
  /// @param component Component to check connection with.
  /// @return True if bus is connected to the component. False otherwise.
  bool isConnectedToComponent(std::shared_ptr<Component> component) const;

  /// @brief Get the number of connected components.
  /// @return Number of connected components.
  uint32_t getNumberOfComponents() const;

private:
  BusId m_id;
  std::vector<std::shared_ptr<Component>> m_components;
};
} // namespace ocira::core

#endif
