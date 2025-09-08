//==============================================================================
// Project:     OCIRA (core library)
// File:        capacitor.hpp
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

#ifndef OCIRA_CORE_CAPACITOR_HPP
#define OCIRA_CORE_CAPACITOR_HPP

#include "component.hpp"
#include <complex>
#include <cstdint>

namespace ocira::core::components {

/// @brief Represents a capacitor component used in AC circuit analysis.
class Capacitor final : public Component {
public:
  /// @brief Constructs a capacitor with a unique ID and specified capacitance.
  /// @param id Unique identifier for the capacitor.
  /// @param capacitance Capacitance value in farads.
  explicit Capacitor(ComponentId id, float capacitance);

  /// @brief Destructor for the capacitor component.
  ~Capacitor() override = default;

  /// @brief Returns the capacitance value.
  /// @return Capacitance in farads.
  float getCapacitance() const noexcept;

  /// @brief Computes the complex impedance of the capacitor at a given frequency.
  /// @param frequency Frequency in hertz.
  /// @return Impedance in ohms (complex value).
  std::complex<float> getImpedance(const float frequency) const;

  /// @brief Computes the complex admittance of the capacitor at a given frequency.
  /// @param frequency Frequency in hertz.
  /// @return Admittance in siemens (complex value).
  std::complex<float> getAdmittance(const float frequency) const;

  /// @brief Updates the capacitance value.
  /// @param capacitance New capacitance value in farads.
  void setCapacitance(const float capacitance) noexcept;

private:
  float m_capacitance;
};
} // namespace ocira::core::components

#endif // OCIRA_CORE_CAPACITOR_HPP