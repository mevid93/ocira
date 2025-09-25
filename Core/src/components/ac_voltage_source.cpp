//==============================================================================
// Project:     OCIRA (core library)
// File:        ac_voltage_source.cpp
// Author:      Martin Vidjeskog
// Created:     2025-09-25
// Description: AC voltage source component.
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
// - 2025-09-25 Martin Vidjeskog: Initial creation
// - [YYYY-MM-DD] [Contributor]: [Description of change]
//==============================================================================
// Notes:
// - Please retain this header in all redistributed versions.
//==============================================================================

#include "ac_voltage_source.hpp"
#include <cmath>

namespace ocira::core::components {

ACVoltageSource::ACVoltageSource(ComponentId id, float amplitude, float phase) : Component(id) {
  this->m_amplitude = amplitude;
  this->m_phase = phase;
  this->m_type = ComponentType::AC_VOLTAGE_SOURCE;
}

float ACVoltageSource::getAmplitude() const noexcept { return this->m_amplitude; }

float ACVoltageSource::getPhase() const noexcept { return this->m_phase; }

void ACVoltageSource::setAmplitude(float amplitude) noexcept { this->m_amplitude = amplitude; }

void ACVoltageSource::setPhase(float phase) noexcept { this->m_phase = phase; }

std::complex<float> ACVoltageSource::getPhasor() const noexcept {
  float angle = this->m_phase * M_PI / 180.0;
  float real = this->m_amplitude * cos(angle);
  float imag = this->m_amplitude * sin(angle);
  std::complex<float> phasor(real, imag);
  return phasor;
}

} // namespace ocira::core::components