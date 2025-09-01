//==============================================================================
// Project:     OCIRA (core library)
// File:        connection_manager.hpp
// Author:      Martin Vidjeskog
// Created:     2025-09-01
// Description: Utility functions for handling connections between components and buses.
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
// - 2025-09-01 Martin Vidjeskog: Initial creation
// - [YYYY-MM-DD] [Contributor]: [Description of change]
//==============================================================================
// Notes:
// - Please retain this header in all redistributed versions.
//==============================================================================

#ifndef OCIRA_CORE_MANAGERS_CONNECTION_MANAGER_HPP
#define OCIRA_CORE_MANAGERS_CONNECTION_MANAGER_HPP

#include "circuit_enums.hpp"
#include <memory>

namespace ocira::core::components {

// Forward declarations.
class Bus;
class Component;

} // namespace ocira::core::components

namespace ocira::core::managers {

/// @brief Class containing static methods for handling connections between components and buses.
class ConnectionManager {
public:
  /// @brief Make class non-instantiable.
  ConnectionManager() = delete;

  /// @brief Connect using strong ownership (shared_ptr).
  /// @param bus Shared pointer to Bus.
  /// @param component Shared pointer to Component.
  /// @param terminalRole TerminalRole for the new connection.
  static void
  connectBusAndComponent(const std::shared_ptr<ocira::core::components::Bus> &bus,
                         const std::shared_ptr<ocira::core::components::Component> &component,
                         TerminalRole terminalRole);

  /// @brief Connect using weak reference to Bus.
  /// @param bus Weak pointer to Bus.
  /// @param component Shared pointer to Component.
  /// @param terminalRole TerminalRole for the new connection.
  static void
  connectBusAndComponent(const std::weak_ptr<ocira::core::components::Bus> &bus,
                         const std::shared_ptr<ocira::core::components::Component> &component,
                         TerminalRole terminalRole);

  /// @brief Disconnect using strong ownership (shared_ptr).
  /// @param bus Shared pointer to Bus.
  /// @param component Shared pointer to Component.
  static void
  disconnectBusAndComponent(const std::shared_ptr<ocira::core::components::Bus> &bus,
                            const std::shared_ptr<ocira::core::components::Component> &component);

  /// @brief Disconnect using weak reference to Bus.
  /// @param bus Weak pointer to Bus.
  /// @param component Shared pointer to Component.
  static void
  disconnectBusAndComponent(const std::weak_ptr<ocira::core::components::Bus> &bus,
                            const std::shared_ptr<ocira::core::components::Component> &component);

private:
};
}; // namespace ocira::core::managers

#endif // OCIRA_CORE_MANAGERS_CONNECTION_MANAGER_HPP