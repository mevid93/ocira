//==============================================================================
// File:        test_connection_manager.cpp
// Author:      Martin Vidjeskog
// Created:     2025-09-01
// Description: Unit tests for ConnectionManager class in OCIRA core library.
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
// - Tests cover ConnectionManager class.
// - Run with: ctest or ./core_tests or ./core_tests --gtest_filter=connection_manager.*
//==============================================================================

#include "bus.hpp"
#include "circuit_enums.hpp"
#include "component.hpp"
#include "connection_manager.hpp"
#include <gtest/gtest.h>
#include <memory>

using namespace ocira::core;
using namespace ocira::core::managers;
using namespace ocira::core::components;

// Test creating a connection between bus (weak_ptr) and component (shared_ptr).
TEST(connection_manager, add_connection_weak_shared) {
  // Create bus and component.
  auto bus_shared = std::make_shared<Bus>(1);
  auto bus_weak = std::weak_ptr<Bus>(bus_shared);
  auto component = std::make_shared<Component>(1);
  // Connect the components with ConnectionManager.
  ConnectionManager::connectBusAndComponent(bus_weak, component, TerminalRole::POSITIVE);
  // Verify results.
  EXPECT_TRUE(bus_shared->isConnectedToComponent(component));
  EXPECT_TRUE(component->isConnectedToBus(bus_shared));
}

// Test creating a connection between bus (shared_ptr) and component (shared_ptr).
TEST(connection_manager, add_connection_shared_shared) {
  // Create bus and component.
  auto bus_shared = std::make_shared<Bus>(1);
  auto component = std::make_shared<Component>(1);
  // Connect the components with ConnectionManager.
  ConnectionManager::connectBusAndComponent(bus_shared, component, TerminalRole::NEGATIVE);
  // Verify results.
  EXPECT_TRUE(bus_shared->isConnectedToComponent(component));
  EXPECT_TRUE(component->isConnectedToBus(bus_shared));
}

// Test removing a connection between bus (weak_ptr) and component (shared_ptr).
TEST(connection_manager, remove_connection_weak_shared) {
  // Create bus and component.
  auto bus_shared = std::make_shared<Bus>(1);
  auto bus_weak = std::weak_ptr<Bus>(bus_shared);
  auto component = std::make_shared<Component>(1);
  // Connect the components with ConnectionManager.
  ConnectionManager::connectBusAndComponent(bus_weak, component, TerminalRole::POSITIVE);
  // Disconnect the components with ConnectionManager.
  ConnectionManager::disconnectBusAndComponent(bus_weak, component);
  // Verify results.
  EXPECT_FALSE(bus_shared->isConnectedToComponent(component));
  EXPECT_FALSE(component->isConnectedToBus(bus_shared));
}

// Test creating a connection between bus (shared_ptr) and component (shared_ptr).
TEST(connection_manager, remove_connection_shared_shared) {
  // Create bus and component.
  auto bus_shared = std::make_shared<Bus>(1);
  auto component = std::make_shared<Component>(1);
  // Connect the components with ConnectionManager.
  ConnectionManager::connectBusAndComponent(bus_shared, component, TerminalRole::NEGATIVE);
  // Disconnect the components with ConnectionManager.
  ConnectionManager::disconnectBusAndComponent(bus_shared, component);
  // Verify results.
  EXPECT_FALSE(bus_shared->isConnectedToComponent(component));
  EXPECT_FALSE(component->isConnectedToBus(bus_shared));
}