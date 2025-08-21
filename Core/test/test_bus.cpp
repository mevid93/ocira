#include "bus.hpp"
#include "component.hpp"
#include <gtest/gtest.h>
#include <memory>

using namespace ocira::core;

// Test Bus class constructor.
TEST(bus, constructor_works) {
  // Create new Bus object.
  Bus bus(1);
  // Expect equality.
  EXPECT_EQ(bus.getId(), 1);
}

// Test connecting new component to bus.
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

// Test connection same component again to bus.
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

// Test disconnecting component that is connected to bus.
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

// Test disconnecting component that is not connected to bus.
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

// Test whether bus is connected to component or not.
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