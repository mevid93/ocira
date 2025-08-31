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
// - 2025-08-26 Martin Vidjeskog: Initial creation
// - [YYYY-MM-DD] [Contributor]: [Description of change]
//==============================================================================
// Notes:
// - Please retain this header in all redistributed versions.
//==============================================================================

#ifndef OCIRA_CORE_CIRCUIT_HPP
#define OCIRA_CORE_CIRCUIT_HPP

#include "circuit_enums.hpp"
#include <memory>
#include <vector>

namespace ocira::core::components {

// Forward declarations.
class Bus;
class Component;

} // namespace ocira::core::components

namespace ocira::core {

/// @brief Represents an electrical circuit composed of components and buses.
/// Supports both DC and AC simulation modes.
class Circuit {
public:
  /// @brief Default constructor. Initializes with default DC simulation mode.
  Circuit();

  /// @brief Constructs a circuit with a specified simulation mode.
  /// @param mode Simulation mode (DC or AC).
  explicit Circuit(SimulationMode mode);

  /// @brief Default destructor.
  ~Circuit() = default;

  /// @brief Returns the list of components in the circuit.
  /// @return Const reference to the vector of components.
  const std::vector<std::shared_ptr<components::Component>> &getComponents() const;

  /// @brief Returns the list of buses in the circuit.
  /// @return Const reference to the vector of buses.
  const std::vector<std::shared_ptr<components::Bus>> &getBuses() const;

  /// @brief Sets the buses for the circuit.
  /// @param buses Vector of shared pointers to Bus objects.
  void setBuses(std::vector<std::shared_ptr<components::Bus>> buses);

  /// @brief Sets the components for the circuit.
  /// @param components Vector of shared pointers to Component objects.
  void setComponents(std::vector<std::shared_ptr<components::Component>> components);

  /// @brief Sets the simulation mode for the circuit.
  /// @param mode Simulation mode (DC or AC).
  void setSimulationMode(SimulationMode mode);

  /// @brief Gets the current simulation mode of the circuit.
  /// @return Simulation mode.
  SimulationMode getSimulationMode() const;

private:
  std::vector<std::shared_ptr<components::Bus>> m_buses;
  std::vector<std::shared_ptr<components::Component>> m_components;
  SimulationMode m_simulationMode;
};
} // namespace ocira::core

#endif // OCIRA_CORE_CIRCUIT_HPP