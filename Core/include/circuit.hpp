//==============================================================================
// Project:     OCIRA (core library)
// File:        circuit.hpp
// Author:      Martin Vidjeskog
// Created:     2025-08-26
// Description: Circuit model (graph).
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

#ifndef OCIRA_CORE_CIRCUIT_HPP
#define OCIRA_CORE_CIRCUIT_HPP

#include "bus.hpp"
#include "component.hpp"
#include <memory>
#include <vector>

namespace ocira::core {

/// @brief Circuit class.
class Circuit {
public:
  /// @brief Constructor.
  explicit Circuit();

  /// @brief Destructor.
  ~Circuit();

  /// @brief Get circuit components.
  /// @return Circuit components.
  const std::vector<std::shared_ptr<Component>> &getComponents() const;

  /// @brief Get circuit buses.
  /// @return Circuit buses.
  const std::vector<std::shared_ptr<Bus>> &getBuses() const;

  /// @brief Set circuit buses.
  /// @param buses Circuit buses.
  void setBuses(std::vector<std::shared_ptr<Bus>> buses);

  /// @brief Set circuit components.
  /// @param components Circuit components.
  void setComponents(std::vector<std::shared_ptr<Component>> components);

private:
  std::vector<std::shared_ptr<Bus>> m_buses;
  std::vector<std::shared_ptr<Component>> m_components;
};
} // namespace ocira::core

#endif