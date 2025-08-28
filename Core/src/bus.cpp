//==============================================================================
// Project:     OCIRA (core library)
// File:        bus.cpp
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

#include "bus.hpp"
#include "component.hpp"
#include <algorithm>

namespace ocira::core {

Bus::Bus(BusId id) : m_id(id) { this->m_components = std::vector<std::shared_ptr<Component>>(); }

BusId Bus::getId() const noexcept { return this->m_id; }

bool Bus::connectComponent(const std::shared_ptr<Component> &component) {
  bool exists = this->isConnectedToComponent(component);

  // If already connected, then do not connect again.
  if (exists) {
    return false;
  }

  this->m_components.push_back(component);

  return true;
}

bool Bus::disconnectComponent(const std::shared_ptr<Component> &component) {
  auto originalSize = this->m_components.size();

  // Delete components that have same id as target component.
  this->m_components.erase(std::remove_if(this->m_components.begin(), this->m_components.end(),
                                          [&](const std::shared_ptr<Component> &c) {
                                            return c && c->getId() == component->getId();
                                          }),
                           this->m_components.end());

  return this->m_components.size() < originalSize;
}

const std::vector<std::shared_ptr<Component>> &Bus::getComponents() const {
  return this->m_components;
}

bool Bus::isConnectedToComponent(const std::shared_ptr<Component> &component) const {
  return std::any_of(
      this->m_components.begin(), this->m_components.end(),
      [&](const std::shared_ptr<Component> &c) { return c && c->getId() == component->getId(); });
}

uint32_t Bus::getNumberOfComponents() const noexcept { return this->m_components.size(); }

bool Bus::isConnected() const noexcept { return !this->m_components.empty(); }
} // namespace ocira::core
