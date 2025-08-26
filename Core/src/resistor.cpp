//==============================================================================
// Project:     OCIRA (core library)
// File:        resistor.cpp
// Author:      Martin Vidjeskog
// Created:     2025-08-26
// Description: Resistor component model.
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

#include "resistor.hpp"

namespace ocira::core {

Resistor::Resistor(ComponentId id, float resistance) : Component(id) {
  this->m_type = ComponentType::RESISTOR;
  this->m_resistance = resistance;
}

Resistor::~Resistor(){};

float Resistor::getResistance() const { return this->m_resistance; }

float Resistor::getConductance() const { return 1 / this->m_resistance; }

void Resistor::setResistance(float resistance) { this->m_resistance = resistance; }

} // namespace ocira::core