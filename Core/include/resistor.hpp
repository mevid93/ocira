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
// - 2025-08-25 Martin Vidjeskog: Initial creation
// - [YYYY-MM-DD] [Contributor]: [Description of change]
//==============================================================================
// Notes:
// - Please retain this header in all redistributed versions.
//==============================================================================

#ifndef OCIRA_CORE_RESISTOR_HPP
#define OCIRA_CORE_RESISTOR_HPP

#include "component.hpp"
#include <cstdint>

namespace ocira::core {
class Resistor : public Component {
public:
  /// @brief Constructor.
  /// @param id Component id.
  /// @param resistance Resistor resistance value (Ohm);
  explicit Resistor(ComponentId id, float resistance);

  /// @brief Destructor.
  ~Resistor();

  /// @brief Get resistor resistance.
  /// @return Resistance.
  float getResistance() const;

  /// @brief Get resistor conducance.
  /// @return Conductance.
  float getConductance() const;

  /// @brief Set resistor resistance.
  /// @param resistance Resistance.
  void setResistance(float resistance);

private:
  float m_resistance;
};
} // namespace ocira::core

#endif