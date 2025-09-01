//==============================================================================
// Project:     OCIRA (core library tests)
// File:        example_circuit_generator.cpp
// Author:      Martin Vidjeskog
// Created:     2025-09-01
// Description: Utility class to generate example circuits.
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
// - 2025-09-01 Martin Vidjeskog: Use ConnectionManager when building circuits.
// - [YYYY-MM-DD] [Contributor]: [Description of change]
//==============================================================================
// Notes:
// - Please retain this header in all redistributed versions.
//==============================================================================

#include "example_circuit_generator.hpp"
#include "bus.hpp"
#include "circuit.hpp"
#include "component.hpp"
#include "connection_manager.hpp"
#include "dc_current_source.hpp"
#include "ground.hpp"
#include "resistor.hpp"
#include <vector>

using namespace ocira::core;
using namespace ocira::core::managers;
using namespace ocira::core::components;

namespace ocira::core::test::helpers {

std::shared_ptr<::Circuit> ExampleCircuitGenerator::getExampleCircuit1() {
  // Create all the components and buses.
  std::shared_ptr<Circuit> circuit = std::make_shared<Circuit>();
  std::shared_ptr<DCCurrentSource> dcCurrentSrc = std::make_shared<DCCurrentSource>(1, 1.0);
  std::shared_ptr<Resistor> resistor = std::make_shared<Resistor>(2, 200);
  std::shared_ptr<Ground> ground = std::make_shared<Ground>(3);
  std::shared_ptr<Bus> bus1 = std::make_shared<Bus>(1);
  std::shared_ptr<Bus> bus2 = std::make_shared<Bus>(2);

  // Connect components and buses.
  ConnectionManager::connectBusAndComponent(bus1, std::static_pointer_cast<Component>(dcCurrentSrc),
                                            TerminalRole::NEGATIVE);
  ConnectionManager::connectBusAndComponent(bus2, std::static_pointer_cast<Component>(dcCurrentSrc),
                                            TerminalRole::POSITIVE);
  ConnectionManager::connectBusAndComponent(bus2, std::static_pointer_cast<Component>(resistor),
                                            TerminalRole::NEGATIVE);
  ConnectionManager::connectBusAndComponent(bus1, std::static_pointer_cast<Component>(resistor),
                                            TerminalRole::POSITIVE);
  ConnectionManager::connectBusAndComponent(bus1, std::static_pointer_cast<Component>(ground),
                                            TerminalRole::NEGATIVE);

  // Group components and buses to two vectors.
  std::vector<std::shared_ptr<Component>> components;
  components.push_back(dcCurrentSrc);
  components.push_back(resistor);
  components.push_back(ground);

  std::vector<std::shared_ptr<Bus>> buses;
  buses.push_back(bus1);
  buses.push_back(bus2);

  // Create circuit.
  circuit->setBuses(buses);
  circuit->setComponents(components);

  return circuit;
}
} // namespace ocira::core::test::helpers