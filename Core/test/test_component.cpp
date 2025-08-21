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

// Test that first bus can be connected.
TEST(component, connect_first_bus) {
  // Create new component object.
  Component component(1);
  // Create new bus object.
  std::shared_ptr<Bus> bus = std::make_shared<Bus>(1);
  // Connect first bus to component.
  bool wasConnected = component.connectFirstBus(bus);
  EXPECT_TRUE(wasConnected);
  // Try to connect bus again.
  wasConnected = component.connectFirstBus(bus);
  EXPECT_FALSE(wasConnected);
  wasConnected = component.connectSecondBus(bus);
  EXPECT_FALSE(wasConnected);
}

// Test that second bus can be connected.
TEST(component, connect_second_bus) {
  // Create new component object.
  Component component(1);
  // Create new bus object.
  std::shared_ptr<Bus> bus = std::make_shared<Bus>(1);
  // Connect second bus to component.
  bool wasConnected = component.connectSecondBus(bus);
  EXPECT_TRUE(wasConnected);
  // Try to connect bus again.
  wasConnected = component.connectSecondBus(bus);
  EXPECT_FALSE(wasConnected);
  wasConnected = component.connectFirstBus(bus);
  EXPECT_FALSE(wasConnected);
}

// Test disconnecting bus.
TEST(component, disconnect_bus) {
  // Creare new component object.
  Component component(1);
  // Create new bus object.
  std::shared_ptr<Bus> bus = std::make_shared<Bus>(1);
  // Connect bus to component.
  component.connectFirstBus(bus);
  // Disconnect bus.
  bool wasDisconnected = component.disconnectBus(bus);
  EXPECT_TRUE(wasDisconnected);
  wasDisconnected = component.disconnectBus(bus);
  EXPECT_FALSE(wasDisconnected);
  // Connect bus to component.
  component.connectSecondBus(bus);
  // Disconnect bus.
  wasDisconnected = component.disconnectBus(bus);
  EXPECT_TRUE(wasDisconnected);
  wasDisconnected = component.disconnectBus(bus);
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
  component.connectFirstBus(bus1);
  component.connectSecondBus(bus2);
  // Verify connections.
  EXPECT_TRUE(component.isConnectedToBus(bus1));
  EXPECT_TRUE(component.isConnectedToBus(bus2));
  EXPECT_FALSE(component.isConnectedToBus(bus3));
}