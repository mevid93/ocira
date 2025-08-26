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
  bool returnValue = bus.connectComponent(component);
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
  bool firstConnection = bus.connectComponent(component);
  // Try to connect same component again.
  bool secondConnection = bus.connectComponent(component);
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
  bool connect = bus.connectComponent(component);
  EXPECT_TRUE(connect);
  EXPECT_EQ(bus.getComponents().size(), 1);
  // Try to disconnect component.
  bool disconnect = bus.disconnectComponent(component);
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
  bool disconnect = bus.disconnectComponent(component);
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
  bus.connectComponent(component);
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
  bus.connectComponent(component);
  uint32_t components2 = bus.getNumberOfComponents();
  // Verify results.
  EXPECT_EQ(components, 0);
  EXPECT_EQ(components2, 1);
}