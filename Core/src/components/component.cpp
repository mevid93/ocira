//==============================================================================
// Project:     OCIRA (core library)
// File:        component.cpp
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

#include "component.hpp"
#include "bus.hpp"
#include <algorithm>

namespace ocira::core::components {

Component::Component(ComponentId id) : m_id(id) {}

Component::~Component() {}

ComponentId Component::getId() const { return this->m_id; }

ComponentType Component::getComponentType() const { return this->m_type; }

bool Component::addConnection(std::weak_ptr<Bus> bus, TerminalRole role) {
  bool isConnected = this->isConnectedToBus(bus);
  if (isConnected)
    return false;

  // By default each component can only have two connections.
  // Override addConnection in inherited classes if this is not the case.
  if (this->m_connections.size() == 2) {
    return false;
  }

  Connection connection{bus, role};
  this->m_connections.push_back(connection);
  return true;
}

bool Component::removeConnection(std::weak_ptr<Bus> bus) {
  auto target = bus.lock();
  if (!target)
    return false;

  for (int i = 0; i < this->m_connections.size(); i++) {
    auto connection = this->m_connections[i];
    auto n = connection.bus.lock();
    if (n && target->getId() == n->getId()) {
      this->m_connections.erase(this->m_connections.begin() + i);
      return true;
    }
  }

  return false;
}

bool Component::isConnectedToBus(std::weak_ptr<Bus> bus) const {
  auto target = bus.lock();
  if (!target)
    return false;

  for (int i = 0; i < this->m_connections.size(); i++) {
    auto connection = this->m_connections[i];
    auto n = connection.bus.lock();
    if (n && target->getId() == n->getId()) {
      return true;
    }
  }

  return false;
}

const std::vector<Connection> &Component::getConnections() const { return this->m_connections; }

bool Component::isConnected() const { return this->m_connections.size() == 2; }
} // namespace ocira::core::components