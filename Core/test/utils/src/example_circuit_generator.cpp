//==============================================================================
// Project:     OCIRA (core library tests)
// File:        example_circuit_generator.cpp
// Author:      Martin Vidjeskog
// Created:     2025-08-26
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
// - 2025-08-25 Martin Vidjeskog: Initial creation
// - [YYYY-MM-DD] [Contributor]: [Description of change]
//==============================================================================
// Notes:
// - Please retain this header in all redistributed versions.
//==============================================================================

#include "example_circuit_generator.hpp"
#include "bus.hpp"
#include "circuit.hpp"
#include "component.hpp"
#include "dc_current_source.hpp"
#include "ground.hpp"
#include "resistor.hpp"
#include <vector>

namespace ocira::core::test::utils {

std::shared_ptr<ocira::core::Circuit> ExampleCircuitGenerator::getExampleCircuit1() {
  std::shared_ptr<Circuit> circuit = std::make_shared<Circuit>();
  std::shared_ptr<DCCurrentSource> dcCurrentSrc = std::make_shared<DCCurrentSource>(1, 1.0);
  std::shared_ptr<Resistor> resistor = std::make_shared<Resistor>(2, 200);
  std::shared_ptr<Ground> ground = std::make_shared<Ground>(3);
  std::shared_ptr<Bus> bus1 = std::make_shared<Bus>(1);
  std::shared_ptr<Bus> bus2 = std::make_shared<Bus>(2);

  dcCurrentSrc->addConnection(bus1, TerminalRole::NEGATIVE);
  bus1->connectComponent(dcCurrentSrc);

  dcCurrentSrc->addConnection(bus2, TerminalRole::POSITIVE);
  bus2->connectComponent(dcCurrentSrc);

  resistor->addConnection(bus1, TerminalRole::NEGATIVE);
  bus1->connectComponent(resistor);

  resistor->addConnection(bus2, TerminalRole::POSITIVE);
  bus2->connectComponent(resistor);

  ground->addConnection(bus1, TerminalRole::NEGATIVE);
  bus1->connectComponent(ground);

  std::vector<std::shared_ptr<Component>> components;
  components.push_back(dcCurrentSrc);
  components.push_back(resistor);
  components.push_back(ground);

  std::vector<std::shared_ptr<Bus>> buses;
  buses.push_back(bus1);
  buses.push_back(bus2);

  circuit->setBuses(buses);
  circuit->setComponents(components);

  return circuit;
}
} // namespace ocira::core::test::utils