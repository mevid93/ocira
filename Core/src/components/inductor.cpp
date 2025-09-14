//==============================================================================
// Project:     OCIRA (core library)
// File:        inductor.cpp
// Author:      Martin Vidjeskog
// Created:     2025-09-14
// Description: Inductor component model.
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
// - 2025-09-14 Martin Vidjeskog: Initial creation
// - [YYYY-MM-DD] [Contributor]: [Description of change]
//==============================================================================
// Notes:
// - Please retain this header in all redistributed versions.
//==============================================================================

#include "inductor.hpp"

namespace ocira::core::components {
Inductor::Inductor(ComponentId id, float inductance) : Component(id) {
  this->m_type = ComponentType::INDUCTOR;
  this->m_inductance = inductance;
}

float Inductor::getInductance() const noexcept { return this->m_inductance; }

std::complex<float> Inductor::getImpedance(const float frequency) const {
  const float omega = 2.0f * M_PI * frequency;
  return std::complex<float>(0.0f, omega * this->m_inductance);
}

std::complex<float> Inductor::getAdmittance(const float frequency) const {
  if (frequency == 0.0f) {
    throw std::runtime_error("Admittance of inductor is undefined for zero frequency.");
  }

  if (this->m_inductance == 0.0f) {
    throw std::runtime_error("Admittance of inductor is undefined for zero inductance.");
  }

  std::complex<float> impedance = getImpedance(frequency);
  return 1.0f / impedance;
}

void Inductor::setInductance(const float inductance) noexcept { this->m_inductance = inductance; }
} // namespace ocira::core::components