//==============================================================================
// Project:     OCIRA (core library)
// File:        dc_voltage_source.hpp
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

#ifndef OCIRA_CORE_DC_VOLTAGE_SOURCE_HPP
#define OCIRA_CORE_DC_VOLTAGE_SOURCE_HPP

#include "component.hpp"
#include <cstdint>

namespace ocira::core::components {

/// @brief Represents a DC voltage source in the circuit. A DC voltage source maintains a constant
/// voltage between two terminals. It acts as an edge in the circuit graph, connecting two
/// buses with a defined voltage. This component is used in circuit analysis to model ideal voltage
/// sources.
class DCVoltageSource final : public Component {
public:
  /// @brief Constructs a DC voltage source with a unique ID and voltage level.
  /// @param id Unique identifier for the component.
  /// @param volts Constant voltage level in volts.
  explicit DCVoltageSource(ComponentId id, float volts);

  /// @brief Destructor for the DC voltage source.
  ~DCVoltageSource() override = default;

  /// @brief Retrieves the voltage level of the source.
  /// @return Voltage level in volts.
  float getVolts() const noexcept;

  /// @brief Updates the voltage level of the source.
  /// @param volts New voltage level in volts.
  void setVolts(float volts) noexcept;

private:
  float m_volts;
};
} // namespace ocira::core::components

#endif // OCIRA_CORE_DC_VOLTAGE_SOURCE_HPP