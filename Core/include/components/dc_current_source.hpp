//==============================================================================
// Project:     OCIRA (core library)
// File:        dc_current_source.hpp
// Author:      Martin Vidjeskog
// Created:     2025-08-26
// Description: DC current source component.
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

#ifndef OCIRA_CORE_DC_CURRENT_SOURCE_HPP
#define OCIRA_CORE_DC_CURRENT_SOURCE_HPP

#include "component.hpp"
#include <cstdint>

namespace ocira::core::components {

/// @brief Represents a DC current source in the circuit. A DC current source maintains a constant
/// current flow between two terminals. It acts as an edge in the circuit graph, connecting two
/// buses with a defined current. This component is used in circuit analysis to model ideal current
/// sources.
class DCCurrentSource final : public Component {
public:
  /// @brief Constructs a DC current source with a unique ID and current value.
  /// @param id Unique identifier for the component.
  /// @param amps Constant current value in amperes.
  explicit DCCurrentSource(ComponentId id, float amps);

  /// @brief Destructor for the DC current source.
  ~DCCurrentSource() override = default;

  /// @brief Retrieves the current value of the source.
  /// @return Current in amperes.
  float getAmps() const noexcept;

  /// @brief Updates the current value of the source.
  /// @param amps New current value in amperes.
  void setAmps(float amps) noexcept;

private:
  float m_amps;
};
} // namespace ocira::core::components

#endif // OCIRA_CORE_DC_CURRENT_SOURCE_HPP