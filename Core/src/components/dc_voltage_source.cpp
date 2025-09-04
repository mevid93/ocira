//==============================================================================
// Project:     OCIRA (core library)
// File:        dc_voltage_source.cpp
// Author:      Martin Vidjeskog
// Created:     2025-09-04
// Description: DC voltage source component.
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
// - 2025-09-04 Martin Vidjeskog: Initial creation
// - [YYYY-MM-DD] [Contributor]: [Description of change]
//==============================================================================
// Notes:
// - Please retain this header in all redistributed versions.
//==============================================================================

#include "dc_voltage_source.hpp"

namespace ocira::core::components {

DCVoltageSource::DCVoltageSource(ComponentId id, float volts) : Component(id) {
  this->m_type = ComponentType::DC_VOLTAGE_SOURCE;
  this->m_volts = volts;
}

float DCVoltageSource::getVolts() const noexcept { return this->m_volts; }

void DCVoltageSource::setVolts(float volts) noexcept { this->m_volts = volts; }

} // namespace ocira::core::components