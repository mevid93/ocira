//==============================================================================
// Project:     OCIRA (core library)
// File:        capacitor.cpp
// Author:      Martin Vidjeskog
// Created:     2025-09-08
// Description: Capacitor component model.
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
// - 2025-09-08 Martin Vidjeskog: Initial creation
// - [YYYY-MM-DD] [Contributor]: [Description of change]
//==============================================================================
// Notes:
// - Please retain this header in all redistributed versions.
//==============================================================================

#include "capacitor.hpp"

namespace ocira::core::components {

Capacitor::Capacitor(ComponentId id, float capacitance) : Component(id) {
  this->m_type = ComponentType::CAPACITOR;
  this->m_capacitance = capacitance;
}

float Capacitor::getCapacitance() const noexcept { return this->m_capacitance; }

std::complex<float> Capacitor::getImpedance(const float frequency) const {
  if (frequency == 0.0f) {
    throw std::runtime_error("Impedance of capacitor is undefined for zero frequency.");
  }

  if (this->m_capacitance == 0.0f) {
    throw std::runtime_error("Impedance of capacitor is undefined for zero capacitance.");
  }

  const float omega = 2.0f * static_cast<float>(M_PI) * frequency;
  return std::complex<float>(0.0f, -1.0f / (omega * m_capacitance));
}

std::complex<float> Capacitor::getAdmittance(const float frequency) const {
  const float omega = 2.0f * static_cast<float>(M_PI) * frequency;
  return std::complex<float>(0.0f, omega * m_capacitance);
}

void Capacitor::setCapacitance(const float capacitance) noexcept {
  this->m_capacitance = capacitance;
}

} // namespace ocira::core::components