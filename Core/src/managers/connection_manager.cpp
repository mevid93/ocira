//==============================================================================
// Project:     OCIRA (core library)
// File:        connection_manager.cpp
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

#include "connection_manager.hpp"
#include "bus.hpp"
#include "component.hpp"

using namespace ocira::core::components;

namespace ocira::core::managers {

void ConnectionManager::connectBusAndComponent(const std::shared_ptr<Bus> &bus,
                                               const std::shared_ptr<Component> &component,
                                               TerminalRole terminalRole) {
  bus->addConnection(component);
  component->addConnection(bus, terminalRole);
}

void ConnectionManager::connectBusAndComponent(const std::weak_ptr<Bus> &bus,
                                               const std::shared_ptr<Component> &component,
                                               TerminalRole terminalRole) {
  if (auto b = bus.lock()) {
    ConnectionManager::connectBusAndComponent(b, component, terminalRole);
  }
}

void ConnectionManager::disconnectBusAndComponent(const std::shared_ptr<Bus> &bus,
                                                  const std::shared_ptr<Component> &component) {
  bus->removeConnection(component);
  component->removeConnection(bus);
}

void ConnectionManager::disconnectBusAndComponent(const std::weak_ptr<Bus> &bus,
                                                  const std::shared_ptr<Component> &component) {
  if (auto b = bus.lock()) {
    ConnectionManager::disconnectBusAndComponent(b, component);
  }
}

} // namespace ocira::core::managers