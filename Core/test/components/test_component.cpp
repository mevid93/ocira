//==============================================================================
// File:        test_component.cpp
// Author:      Martin Vidjeskog
// Created:     2025-08-26
// Description: Unit tests for Component class in OCIRA core library.
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
// - Tests cover Component class.
// - Run with: ctest or ./core_tests or ./core_tests --gtest_filter=component.*
//==============================================================================

#include "bus.hpp"
#include "component.hpp"
#include <gtest/gtest.h>
#include <memory>

using namespace ocira::core;
using namespace ocira::core::components;

/// @brief Test Component class constructor.
TEST(component, constructor_works) {
  // Create new Component object.
  Component component(1);
  // Expect equality.
  EXPECT_EQ(component.getId(), 1);
}

// Test that component type is returned.
TEST(component, component_type_is_returned) {
  // Create new Component object.
  Component component(1);
  // Verify the component type.
  EXPECT_EQ(component.getComponentType(), ComponentType::UNDEFINED);
}

/// @brief Test that a bus can be connected.
TEST(component, connect_first_bus) {
  // Create new component object.
  Component component(1);
  // Create new bus object.
  std::shared_ptr<Bus> bus = std::make_shared<Bus>(1);
  // Connect first bus to component.
  bool wasConnected = component.addConnection(bus, TerminalRole::NEGATIVE);
  EXPECT_TRUE(wasConnected);
  // Try to connect bus again.
  wasConnected = component.addConnection(bus, TerminalRole::NEGATIVE);
  EXPECT_FALSE(wasConnected);
  wasConnected = component.addConnection(bus, TerminalRole::POSITIVE);
  EXPECT_FALSE(wasConnected);
}

/// @brief Test disconnecting a bus.
TEST(component, disconnect_bus) {
  // Creare new component object.
  Component component(1);
  // Create new bus object.
  std::shared_ptr<Bus> bus = std::make_shared<Bus>(1);
  // Connect bus to component.
  component.addConnection(bus, TerminalRole::NEGATIVE);
  // Disconnect bus.
  bool wasDisconnected = component.removeConnection(bus);
  EXPECT_TRUE(wasDisconnected);
  wasDisconnected = component.removeConnection(bus);
  EXPECT_FALSE(wasDisconnected);
}

/// @brief Test if a component is connected to a bus.
TEST(component, is_connected_to_bus) {
  // Create new component object.
  Component component(1);
  // Create new bus objects.
  std::shared_ptr<Bus> bus1 = std::make_shared<Bus>(1);
  std::shared_ptr<Bus> bus2 = std::make_shared<Bus>(2);
  std::shared_ptr<Bus> bus3 = std::make_shared<Bus>(3);
  // Connect buses to component.
  component.addConnection(bus1, TerminalRole::NEGATIVE);
  component.addConnection(bus2, TerminalRole::POSITIVE);
  component.addConnection(bus3, TerminalRole::POSITIVE);
  // Verify connections.
  EXPECT_TRUE(component.isConnectedToBus(bus1));
  EXPECT_TRUE(component.isConnectedToBus(bus2));
  EXPECT_FALSE(component.isConnectedToBus(bus3));
}