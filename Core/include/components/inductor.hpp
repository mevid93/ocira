//==============================================================================
// Project:     OCIRA (core library)
// File:        inductor.hpp
// Author:      Martin Vidjeskog
// Created:     2025-09-11
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
// - 2025-09-11 Martin Vidjeskog: Initial creation
// - [YYYY-MM-DD] [Contributor]: [Description of change]
//==============================================================================
// Notes:
// - Please retain this header in all redistributed versions.
//==============================================================================

#ifndef OCIRA_CORE_INDUCTOR_HPP
#define OCIRA_CORE_INDUCTOR_HPP

#include "component.hpp"
#include <complex>
#include <cstdint>

namespace ocira::core::components {

/// @brief Represents a inductor component used in AC circuit analysis.
class Inductor final : public Component {
public:
  /// @brief Constructs an inductor with a unique ID and specified inductance.
  /// @param id Unique identifier for the inductor.
  /// @param inductance Inductance value in henries.
  explicit Inductor(ComponentId id, float inductance);

  /// @brief Destructor for the inductor component.
  ~Inductor() override = default;

  /// @brief Returns the inductance value.
  /// @return Inductance in henries.
  float getInductance() const noexcept;

  /// @brief Computes the complex impedance of the inductor at a given frequency.
  /// @param frequency Frequency in hertz.
  /// @return Impedance in ohms (complex value).
  std::complex<float> getImpedance(const float frequency) const;

  /// @brief Computes the complex admittance of the inductor at a given frequency.
  /// @param frequency Frequency in hertz.
  /// @return Admittance in siemens (complex value).
  std::complex<float> getAdmittance(const float frequency) const;

  /// @brief Updates the inductance value.
  /// @param inductance New inductance value in henries.
  void setInductance(const float inductance) noexcept;

private:
  float m_inductance;
};
} // namespace ocira::core::components

#endif // OCIRA_CORE_INDUCTOR_HPP