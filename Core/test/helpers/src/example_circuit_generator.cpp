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
#include "dc_voltage_source.hpp"
#include "ground.hpp"
#include "resistor.hpp"
#include <vector>

using namespace ocira::core;
using namespace ocira::core::managers;
using namespace ocira::core::components;

namespace ocira::core::test::helpers {

std::shared_ptr<Circuit> ExampleCircuitGenerator::getExampleCircuit1() {
  // Create all the components and buses.
  std::shared_ptr<Circuit> circuit = std::make_shared<Circuit>();
  std::shared_ptr<DCCurrentSource> dcCurrentSrc1 = std::make_shared<DCCurrentSource>(1, 1.0);
  std::shared_ptr<Resistor> resistor1 = std::make_shared<Resistor>(2, 200);
  std::shared_ptr<Ground> ground = std::make_shared<Ground>(3);
  std::shared_ptr<Bus> bus1 = std::make_shared<Bus>(1);
  std::shared_ptr<Bus> bus2 = std::make_shared<Bus>(2);

  // Connect components and buses.
  ConnectionManager::connectBusAndComponent(
      bus1, std::static_pointer_cast<Component>(dcCurrentSrc1), TerminalRole::NEGATIVE);
  ConnectionManager::connectBusAndComponent(
      bus2, std::static_pointer_cast<Component>(dcCurrentSrc1), TerminalRole::POSITIVE);
  ConnectionManager::connectBusAndComponent(bus2, std::static_pointer_cast<Component>(resistor1),
                                            TerminalRole::NEGATIVE);
  ConnectionManager::connectBusAndComponent(bus1, std::static_pointer_cast<Component>(resistor1),
                                            TerminalRole::POSITIVE);
  ConnectionManager::connectBusAndComponent(bus1, std::static_pointer_cast<Component>(ground),
                                            TerminalRole::NEGATIVE);

  // Group components and buses to two vectors.
  std::vector<std::shared_ptr<Component>> components;
  components.push_back(dcCurrentSrc1);
  components.push_back(resistor1);
  components.push_back(ground);

  std::vector<std::shared_ptr<Bus>> buses;
  buses.push_back(bus1);
  buses.push_back(bus2);

  // Create circuit.
  circuit->setBuses(buses);
  circuit->setComponents(components);

  return circuit;
}

std::shared_ptr<Circuit> ExampleCircuitGenerator::getExampleCircuit2() {
  // Create all the components and buses.
  std::shared_ptr<Circuit> circuit = std::make_shared<Circuit>();

  std::shared_ptr<Ground> ground = std::make_shared<Ground>(0);

  std::shared_ptr<DCVoltageSource> dcVoltageSrc1 = std::make_shared<DCVoltageSource>(1, 1.0);

  std::shared_ptr<Resistor> resistor1 = std::make_shared<Resistor>(2, 100);
  std::shared_ptr<Resistor> resistor2 = std::make_shared<Resistor>(3, 100);
  std::shared_ptr<Resistor> resistor3 = std::make_shared<Resistor>(4, 9);
  std::shared_ptr<Resistor> resistor4 = std::make_shared<Resistor>(5, 1);
  std::shared_ptr<Resistor> resistor5 = std::make_shared<Resistor>(6, 10);
  std::shared_ptr<Resistor> resistor6 = std::make_shared<Resistor>(7, 1);
  std::shared_ptr<Resistor> resistor7 = std::make_shared<Resistor>(8, 50);

  std::shared_ptr<DCCurrentSource> dcCurrentSrc6 = std::make_shared<DCCurrentSource>(9, 1);
  std::shared_ptr<DCCurrentSource> dcCurrentSrc7 = std::make_shared<DCCurrentSource>(10, 2);

  std::shared_ptr<Bus> bus0 = std::make_shared<Bus>(0);
  std::shared_ptr<Bus> bus1 = std::make_shared<Bus>(1);
  std::shared_ptr<Bus> bus2 = std::make_shared<Bus>(2);
  std::shared_ptr<Bus> bus3 = std::make_shared<Bus>(3);
  std::shared_ptr<Bus> bus4 = std::make_shared<Bus>(4);

  // Connect components and buses.
  ConnectionManager::connectBusAndComponent(bus0, std::static_pointer_cast<Component>(ground),
                                            TerminalRole::POSITIVE);
  ConnectionManager::connectBusAndComponent(
      bus0, std::static_pointer_cast<Component>(dcVoltageSrc1), TerminalRole::NEGATIVE);
  ConnectionManager::connectBusAndComponent(
      bus1, std::static_pointer_cast<Component>(dcVoltageSrc1), TerminalRole::POSITIVE);
  ConnectionManager::connectBusAndComponent(bus1, std::static_pointer_cast<Component>(resistor1),
                                            TerminalRole::NEGATIVE);
  ConnectionManager::connectBusAndComponent(bus2, std::static_pointer_cast<Component>(resistor1),
                                            TerminalRole::POSITIVE);
  ConnectionManager::connectBusAndComponent(bus2, std::static_pointer_cast<Component>(resistor2),
                                            TerminalRole::NEGATIVE);
  ConnectionManager::connectBusAndComponent(bus0, std::static_pointer_cast<Component>(resistor2),
                                            TerminalRole::POSITIVE);
  ConnectionManager::connectBusAndComponent(bus2, std::static_pointer_cast<Component>(resistor3),
                                            TerminalRole::NEGATIVE);
  ConnectionManager::connectBusAndComponent(bus3, std::static_pointer_cast<Component>(resistor3),
                                            TerminalRole::POSITIVE);
  ConnectionManager::connectBusAndComponent(bus3, std::static_pointer_cast<Component>(resistor4),
                                            TerminalRole::NEGATIVE);
  ConnectionManager::connectBusAndComponent(bus4, std::static_pointer_cast<Component>(resistor4),
                                            TerminalRole::POSITIVE);
  ConnectionManager::connectBusAndComponent(bus2, std::static_pointer_cast<Component>(resistor5),
                                            TerminalRole::NEGATIVE);
  ConnectionManager::connectBusAndComponent(bus4, std::static_pointer_cast<Component>(resistor5),
                                            TerminalRole::POSITIVE);
  ConnectionManager::connectBusAndComponent(bus4, std::static_pointer_cast<Component>(resistor6),
                                            TerminalRole::NEGATIVE);
  ConnectionManager::connectBusAndComponent(bus0, std::static_pointer_cast<Component>(resistor6),
                                            TerminalRole::POSITIVE);
  ConnectionManager::connectBusAndComponent(bus0, std::static_pointer_cast<Component>(resistor7),
                                            TerminalRole::NEGATIVE);
  ConnectionManager::connectBusAndComponent(bus2, std::static_pointer_cast<Component>(resistor7),
                                            TerminalRole::POSITIVE);
  ConnectionManager::connectBusAndComponent(
      bus0, std::static_pointer_cast<Component>(dcCurrentSrc6), TerminalRole::NEGATIVE);
  ConnectionManager::connectBusAndComponent(
      bus4, std::static_pointer_cast<Component>(dcCurrentSrc6), TerminalRole::POSITIVE);
  ConnectionManager::connectBusAndComponent(
      bus0, std::static_pointer_cast<Component>(dcCurrentSrc7), TerminalRole::NEGATIVE);
  ConnectionManager::connectBusAndComponent(
      bus2, std::static_pointer_cast<Component>(dcCurrentSrc7), TerminalRole::POSITIVE);

  // Group components and buses to two vectors.
  std::vector<std::shared_ptr<Component>> components;
  components.push_back(ground);
  components.push_back(dcVoltageSrc1);
  components.push_back(dcCurrentSrc6);
  components.push_back(dcCurrentSrc7);
  components.push_back(resistor1);
  components.push_back(resistor2);
  components.push_back(resistor3);
  components.push_back(resistor4);
  components.push_back(resistor5);
  components.push_back(resistor6);
  components.push_back(resistor7);

  std::vector<std::shared_ptr<Bus>> buses;
  buses.push_back(bus0);
  buses.push_back(bus1);
  buses.push_back(bus2);
  buses.push_back(bus3);
  buses.push_back(bus4);

  // Create circuit.
  circuit->setBuses(buses);
  circuit->setComponents(components);

  return circuit;
}
} // namespace ocira::core::test::helpers