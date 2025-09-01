//==============================================================================
// File:        test_bus.cpp
// Author:      Martin Vidjeskog
// Created:     2025-08-26
// Description: Unit tests for Bus class in OCIRA core library.
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
// Notes:
// - Tests cover Bus class.
// - Run with: ctest or ./core_tests or ./core_tests --gtest_filter=bus.*
//==============================================================================

#include "bus.hpp"
#include "component.hpp"
#include <gtest/gtest.h>
#include <memory>

using namespace ocira::core;
using namespace ocira::core::components;

/// @brief Test Bus class constructor.
TEST(bus, constructor_works) {
  // Create new Bus object.
  Bus bus(1);
  // Expect equality.
  EXPECT_EQ(bus.getId(), 1);
}

/// @brief Test connecting a new component to a bus.
TEST(bus, connect_new_component) {
  // Create new Bus object.
  Bus bus(1);
  // Create new Component object.
  auto component = std::make_shared<Component>(1);
  // Connect component to bus.
  bool returnValue = bus.addConnection(component);
  // Verify that component was connected.
  EXPECT_TRUE(returnValue);
  EXPECT_EQ(bus.getComponents().size(), 1);
  EXPECT_EQ(bus.getComponents().at(0)->getId(), 1);
}

/// @brief Test connecting a same component again to a bus.
TEST(bus, connect_component_again) {
  // Create new Bus object.
  Bus bus(1);
  // Create new Component object.
  auto component = std::make_shared<Component>(1);
  // Connect component to bus.
  bool firstConnection = bus.addConnection(component);
  // Try to connect same component again.
  bool secondConnection = bus.addConnection(component);
  // Verify that component was connected only once.
  EXPECT_TRUE(firstConnection);
  EXPECT_FALSE(secondConnection);
  EXPECT_EQ(bus.getComponents().size(), 1);
}

/// @brief Test disconnecting a component that is connected to a bus.
TEST(bus, disconnect_component_that_is_connected) {
  // Create new Bus object.
  Bus bus(1);
  // Create new Component object.
  auto component = std::make_shared<Component>(1);
  // Connect component to bus.
  bool connect = bus.addConnection(component);
  EXPECT_TRUE(connect);
  EXPECT_EQ(bus.getComponents().size(), 1);
  // Try to disconnect component.
  bool disconnect = bus.removeConnection(component);
  // Verify that component was disconnected.
  EXPECT_TRUE(disconnect);
  EXPECT_EQ(bus.getComponents().size(), 0);
}

/// @brief Test disconnecting a component that is not connected to a bus.
TEST(bus, disconnect_component_that_is_not_connected) {
  // Create new Bus object.
  Bus bus(1);
  // Create new Component object.
  auto component = std::make_shared<Component>(1);
  // Try to disconnect component.
  bool disconnect = bus.removeConnection(component);
  // Verify that component was disconnected.
  EXPECT_FALSE(disconnect);
}

/// @brief Test whether a bus is connected to a component or not.
TEST(bus, is_connected_to_component) {
  // Create new Bus object.
  Bus bus(1);
  // Create new component object.
  auto component = std::make_shared<Component>(1);
  // Check if component is connected.
  bool isConnected = bus.isConnectedToComponent(component);
  EXPECT_FALSE(isConnected);
  // Connect component to bus.
  bus.addConnection(component);
  // Check if component is connected.
  isConnected = bus.isConnectedToComponent(component);
  EXPECT_TRUE(isConnected);
}

/// @brief Test that correct number of connected components is returned.
TEST(bus, get_number_of_components) {
  // Create new Bus object.
  Bus bus(1);
  uint32_t components = bus.getNumberOfComponents();
  // Create new component object.
  auto component = std::make_shared<Component>(1);
  // Connect component to bus.
  bus.addConnection(component);
  uint32_t components2 = bus.getNumberOfComponents();
  // Verify results.
  EXPECT_EQ(components, 0);
  EXPECT_EQ(components2, 1);
}

/// @brief Test that connectivity check works.
TEST(bus, is_connected) {
  // Create a new Bus object.
  Bus bus(1);
  // Perform first check.
  EXPECT_FALSE(bus.isConnected());
  // Create new component object.
  auto component = std::make_shared<Component>(1);
  // Connect component to bus.
  bus.addConnection(component);
  // Perform second check.
  EXPECT_TRUE(bus.isConnected());
}

/// @brief Test that neighbor buses are returned.
TEST(bus, get_neighbor_buses) {
  // Create buses and components.
  std::shared_ptr<Bus> bus1 = std::make_shared<Bus>(1);
  std::shared_ptr<Bus> bus2 = std::make_shared<Bus>(2);
  std::shared_ptr<Component> component1 = std::make_shared<Component>(1);
  std::shared_ptr<Component> component2 = std::make_shared<Component>(2);
  // Connect components with buses.
  component1->addConnection(bus2, TerminalRole::POSITIVE);
  component2->addConnection(bus2, TerminalRole::POSITIVE);
  bus1->addConnection(component1);
  bus2->addConnection(component2);
  // Get list of neighbor buses for bus1.
  auto neigbors = bus1->getNeighborBuses();
  // Validate results.
  EXPECT_FALSE(neigbors.empty());
  EXPECT_EQ(neigbors.at(0).lock()->getId(), 2);
}