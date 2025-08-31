//==============================================================================
// Project:     OCIRA (core library)
// File:        circuit_validator.cpp
// Author:      Martin Vidjeskog
// Created:     2025-08-28
// Description: Circuit validation logic.
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
// - 2025-08-28 Martin Vidjeskog: Initial creation
// - [YYYY-MM-DD] [Contributor]: [Description of change]
//==============================================================================
// Notes:
// - Please retain this header in all redistributed versions.
//==============================================================================

#include "circuit_validator.hpp"
#include "bus.hpp"
#include "circuit.hpp"
#include "circuit_structs.hpp"
#include "component.hpp"
#include <unordered_set>

using namespace ocira::core::components;

namespace ocira::core {

ValidationResult CircuitValidator::isValidCircuit(const Circuit &circuit) {
  ValidationResult result = {true};

  // 1. Check that all buses are connected to at least one component.
  _validateBusConnections(circuit, result);

  // 2. Check that all components are fully connected.
  _validateComponentConnections(circuit, result);

  // 3. Check that ground component exists in circuit.
  _validateGround(circuit, result);

  // 4. Check that all components support the circuit's simulation mode.
  _validateSimulationModeCompatibility(circuit, result);

  // 5. Check that all buses and components have unique identifiers.
  _validateUniqueIds(circuit, result);

  // 6. Check the full connectivity of the circuit.
  _validateConnectivity(circuit, result);

  // Additional checks here...

  return result;
}

// PRIVATE METHODS

void CircuitValidator::_validateBusConnections(const Circuit &circuit, ValidationResult &result) {
  for (const std::shared_ptr<Bus> &bus : circuit.getBuses()) {
    if (!bus->isConnected()) {
      result.isValid = false;
      result.errors.push_back({"Bus without connections.", ValidationErrorCode::UNCONNECTED_BUS,
                               "Bus - " + bus->getId()});
    }
  }
}

void CircuitValidator::_validateComponentConnections(const Circuit &circuit,
                                                     ValidationResult &result) {
  for (const std::shared_ptr<Component> &component : circuit.getComponents()) {
    if (!component->isConnected()) {
      result.isValid = false;
      result.errors.push_back({"Component without required connections.",
                               ValidationErrorCode::UNCONNECTED_COMPONENT,
                               "Component - " + component->getId()});
    }
  }
}

void CircuitValidator::_validateGround(const Circuit &circuit, ValidationResult &result) {
  for (const std::shared_ptr<Component> &component : circuit.getComponents()) {
    if (component->getComponentType() == ComponentType::GROUND) {
      return;
    }
  }

  result.isValid = false;
  result.errors.push_back(
      {"Ground component is missing.", ValidationErrorCode::GROUND_COMPONENT_MISSING, ""});
}

void CircuitValidator::_validateSimulationModeCompatibility(const Circuit &circuit,
                                                            ValidationResult &result) {
  if (circuit.getSimulationMode() == SimulationMode::DC) {
    for (const std::shared_ptr<Component> &component : circuit.getComponents()) {
      switch (component->getComponentType()) {
      case ComponentType::AC_CURRENT_SOURCE:
      case ComponentType::AC_VOLTAGE_SOURCE:
      case ComponentType::CAPACITOR:
      case ComponentType::IMPEDANCE:
      case ComponentType::INDUCTOR:
      case ComponentType::UNDEFINED: {
        result.isValid = false;
        result.errors.push_back({"Incompatible component for DC simulation mode.",
                                 ValidationErrorCode::INCOMPATIBLE_COMPONENT_FOR_DC_SIMULATION,
                                 "Component - " + component->getId()});
      }
      default:
        break;
      }
    }
  } else if (circuit.getSimulationMode() == SimulationMode::AC) {
    for (const std::shared_ptr<Component> &component : circuit.getComponents()) {
      switch (component->getComponentType()) {
      case ComponentType::DC_CURRENT_SOURCE:
      case ComponentType::DC_VOLTAGE_SOURCE:
      case ComponentType::UNDEFINED: {
        result.isValid = false;
        result.errors.push_back({"Incompatible component for AC simulation mode.",
                                 ValidationErrorCode::INCOMPATIBLE_COMPONENT_FOR_AC_SIMULATION,
                                 "Component - " + component->getId()});
      }
      default:
        break;
      }
    }
  }
}

void CircuitValidator::_validateUniqueIds(const Circuit &circuit, ValidationResult &result) {
  // Validate unique identifiers among buses.
  std::unordered_set<BusId> seenBusIds;

  for (const std::shared_ptr<Bus> &bus : circuit.getBuses()) {
    const BusId busId = bus->getId();

    if (seenBusIds.find(busId) != seenBusIds.end()) {
      result.isValid = false;
      result.errors.push_back({"Duplicate bus ID detected.",
                               ValidationErrorCode::DUPLICATE_IDENTIFIER, "Bus - " + busId});
    } else {
      seenBusIds.insert(busId);
    }
  }

  // Validate unique identifiers among components.
  std::unordered_set<BusId> seenComponentIds;

  for (const std::shared_ptr<Component> &component : circuit.getComponents()) {
    const BusId componentId = component->getId();

    if (seenComponentIds.find(componentId) != seenComponentIds.end()) {
      result.isValid = false;
      result.errors.push_back({"Duplicate component ID detected.",
                               ValidationErrorCode::DUPLICATE_IDENTIFIER,
                               "Component - " + componentId});
    } else {
      seenComponentIds.insert(componentId);
    }
  }
}

static void dfs(const std::weak_ptr<Bus> &bus, const Circuit &circuit,
                std::unordered_set<int> &visited) {
  if (auto b = bus.lock()) {
    if (visited.count(b->getId()))
      return;

    visited.insert(b->getId());
    for (const auto &neighbor : b->getNeighborBuses()) {
      dfs(neighbor, circuit, visited);
    }
  }
}

void CircuitValidator::_validateConnectivity(const Circuit &circuit, ValidationResult &result) {
  std::unordered_set<int> visited;
  if (circuit.getBuses().empty())
    return;

  // Start DFS from the first bus to check full connectivity
  dfs(std::weak_ptr<Bus>(circuit.getBuses().at(0)), circuit, visited);

  if (visited.size() != circuit.getBuses().size()) {
    result.isValid = false;
    result.errors.push_back({"Circuit contains buses that are not reachable from one another.",
                             ValidationErrorCode::CIRCUIT_NOT_FULLY_CONNECTED, ""});
  }
}

} // namespace ocira::core