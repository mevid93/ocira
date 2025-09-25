//==============================================================================
// Project:     OCIRA (core library)
// File:        ac_voltage_source.hpp
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

#ifndef OCIRA_CORE_AC_VOLTAGE_SOURCE_HPP
#define OCIRA_CORE_AC_VOLTAGE_SOURCE_HPP

#include "component.hpp"
#include <complex>
#include <cstdint>

namespace ocira::core::components {

/// @brief Represents an AC voltage source.
/// The source is defined by a phasor (amplitude and phase), assuming a global frequency.
/// It connects two buses and injects a sinusoidal voltage in the phasor domain.
class ACVoltageSource final : public Component {
public:
  /// @brief Constructs an AC voltage source with a unique ID and phasor parameters.
  /// @param id Unique identifier for the component.
  /// @param amplitude Peak voltage value in volts.
  /// @param phase Phase offset in degrees.
  explicit ACVoltageSource(ComponentId id, float amplitude, float phase = 0.0f);

  /// @brief Destructor for the AC voltage source.
  ~ACVoltageSource() override = default;

  /// @brief Retrieves the amplitude of the voltage source.
  float getAmplitude() const noexcept;

  /// @brief Retrieves the phase of the voltage source in degrees.
  float getPhase() const noexcept;

  /// @brief Retrieves the complex phasor representation of the voltage.
  /// @return Complex voltage phasor: amplitude * exp(j * phase_in_radians)
  std::complex<float> getPhasor() const noexcept;

  /// @brief Updates the amplitude of the voltage source.
  void setAmplitude(float amplitude) noexcept;

  /// @brief Updates the phase (degrees) of the voltage source.
  void setPhase(float phase) noexcept;

private:
  float m_amplitude;
  float m_phase;
};

} // namespace ocira::core::components

#endif // OCIRA_CORE_AC_VOLTAGE_SOURCE_HPP