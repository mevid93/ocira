//==============================================================================
// Project:     OCIRA (core library)
// File:        circuit.cpp
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

#include "circuit.hpp"
#include "bus.hpp"
#include "component.hpp"

using namespace ocira::core::components;

namespace ocira::core {

Circuit::Circuit() : m_simulationMode(SimulationMode::DC) {}

Circuit::Circuit(SimulationMode mode) : m_simulationMode(mode) {}

const std::vector<std::shared_ptr<Component>> &Circuit::getComponents() const {
  return this->m_components;
}

const std::vector<std::shared_ptr<Bus>> &Circuit::getBuses() const { return this->m_buses; }

void Circuit::setBuses(std::vector<std::shared_ptr<Bus>> buses) { this->m_buses = buses; }

void Circuit::setComponents(std::vector<std::shared_ptr<Component>> components) {
  this->m_components = components;
}

void Circuit::setSimulationMode(SimulationMode mode) { this->m_simulationMode = mode; }

SimulationMode Circuit::getSimulationMode() const { return this->m_simulationMode; }

} // namespace ocira::core