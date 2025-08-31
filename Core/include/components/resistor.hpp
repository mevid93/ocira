//==============================================================================
// Project:     OCIRA (core library)
// File:        resistor.hpp
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
// - 2025-08-26 Martin Vidjeskog: Initial creation
// - [YYYY-MM-DD] [Contributor]: [Description of change]
//==============================================================================
// Notes:
// - Please retain this header in all redistributed versions.
//==============================================================================

#ifndef OCIRA_CORE_RESISTOR_HPP
#define OCIRA_CORE_RESISTOR_HPP

#include "component.hpp"
#include <cstdint>

namespace ocira::core::components {

/// @brief Represents a resistor component in the circuit.
/// A resistor limits the flow of electric current between two buses.
/// It is defined by its resistance value in ohms and contributes to
/// voltage drops and power dissipation in circuit analysis.
class Resistor final : public Component {
public:
  /// @brief Constructs a resistor with a unique ID and resistance value.
  /// @param id Unique identifier for the resistor.
  /// @param resistance Resistance value in ohms.
  explicit Resistor(ComponentId id, float resistance);

  /// @brief Destructor for the resistor component.
  /// Declared virtual to support polymorphic cleanup.
  ~Resistor() override = default;

  /// @brief Retrieves the resistance value of the resistor.
  /// @return Resistance in ohms.
  float getResistance() const noexcept;

  /// @brief Calculates and returns the conductance of the resistor.
  /// Conductance is the reciprocal of resistance, measured in siemens.
  /// @return Conductance in siemens.
  float getConductance() const;

  /// @brief Updates the resistance value of the resistor.
  /// @param resistance New resistance value in ohms.
  void setResistance(float resistance) noexcept;

private:
  float m_resistance;
};
} // namespace ocira::core::components

#endif // OCIRA_CORE_RESISTOR_HPP