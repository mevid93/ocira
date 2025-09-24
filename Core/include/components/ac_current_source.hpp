//==============================================================================
// Project:     OCIRA (core library)
// File:        ac_current_source.hpp
// Author:      Martin Vidjeskog
// Created:     2025-09-17
// Description: AC current source component.
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
// - 2025-09-17 Martin Vidjeskog: Initial creation
// - [YYYY-MM-DD] [Contributor]: [Description of change]
//==============================================================================
// Notes:
// - Please retain this header in all redistributed versions.
//==============================================================================

#ifndef OCIRA_CORE_AC_CURRENT_SOURCE_HPP
#define OCIRA_CORE_AC_CURRENT_SOURCE_HPP

#include "component.hpp"
#include <complex>
#include <cstdint>

namespace ocira::core::components {

/// @brief Represents an AC current source.
/// The source is defined by a phasor (amplitude and phase), assuming a global frequency.
/// It connects two buses and injects a sinusoidal current in the phasor domain.
class ACCurrentSource final : public Component {
public:
  /// @brief Constructs an AC current source with a unique ID and phasor parameters.
  /// @param id Unique identifier for the component.
  /// @param amplitude Peak current value in amperes.
  /// @param phase Phase offset in degrees.
  explicit ACCurrentSource(ComponentId id, float amplitude, float phase = 0.0f);

  /// @brief Destructor for the AC current source.
  ~ACCurrentSource() override = default;

  /// @brief Retrieves the amplitude of the current source.
  float getAmplitude() const noexcept;

  /// @brief Retrieves the phase of the current source in degrees.
  float getPhase() const noexcept;

  /// @brief Retrieves the complex phasor representation of the current.
  /// @return Complex current phasor: amplitude * exp(j * phase_in_radians)
  std::complex<float> getPhasor() const noexcept;

  /// @brief Updates the amplitude of the current source.
  void setAmplitude(float amplitude) noexcept;

  /// @brief Updates the phase (degrees) of the current source.
  void setPhase(float phase) noexcept;

private:
  float m_amplitude;
  float m_phase;
};

} // namespace ocira::core::components

#endif // OCIRA_CORE_AC_CURRENT_SOURCE_HPP