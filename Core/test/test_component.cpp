#include "bus.hpp"
#include "component.hpp"
#include <gtest/gtest.h>
#include <memory>

using namespace ocira::core;

// Test Component class constructor.
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

// Test that bus can be connected.
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

// Test disconnecting bus.
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

// Test if component is connected to bus.
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