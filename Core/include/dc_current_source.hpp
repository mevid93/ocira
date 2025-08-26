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
// - 2025-08-25 Martin Vidjeskog: Initial creation
// - [YYYY-MM-DD] [Contributor]: [Description of change]
//==============================================================================
// Notes:
// - Please retain this header in all redistributed versions.
//==============================================================================

#ifndef OCIRA_CORE_DC_CURRENT_SOURCE_HPP
#define OCIRA_CORE_DC_CURRENT_SOURCE_HPP

#include "component.hpp"
#include <cstdint>

namespace ocira::core {
/// @brief DC current source component.
class DCCurrentSource : public Component {
public:
  /// @brief Constructor.
  /// @param id Component id.
  /// @param amps DC current source amps.
  explicit DCCurrentSource(ComponentId id, float amps);

  /// @brief Destructor.
  ~DCCurrentSource();

  /// @brief Get DC current source amps.
  /// @return Current level (amps).
  float getAmps() const;

  /// @brief Set current level.
  /// @param amps Current level (amps).
  void setAmps(float amps);

private:
  float m_amps;
};
} // namespace ocira::core

#endif