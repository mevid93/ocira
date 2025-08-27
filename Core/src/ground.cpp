//==============================================================================
// Project:     OCIRA (core library)
// File:        ground.cpp
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
// - 2025-08-25 Martin Vidjeskog: Initial creation
// - [YYYY-MM-DD] [Contributor]: [Description of change]
//==============================================================================
// Notes:
// - Please retain this header in all redistributed versions.
//==============================================================================

#include "ground.hpp"

namespace ocira::core {

Ground::Ground(ComponentId id) : Component(id) { this->m_type = ComponentType::GROUND; }

bool Ground::addConnection(std::weak_ptr<Bus> bus, TerminalRole role) {
  if (this->m_connections.size() == 1) {
    return false;
  }

  Connection connection{bus, role};
  this->m_connections.push_back(connection);
  return true;
}
} // namespace ocira::core