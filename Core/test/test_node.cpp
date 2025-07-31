#include "component.hpp"
#include "node.hpp"
#include <gtest/gtest.h>
#include <memory>

using namespace ocira::core;

// Test Node class constructor.
TEST(node, constructor_works) {
  // Create new Node object.
  Node node(1);
  // Expect equality.
  EXPECT_EQ(node.getId(), 1);
}

// Test connecting new component to node.
TEST(node, connect_new_component) {
  // Create new Node object.
  Node node(1);
  // Create new Component object.
  auto component = std::make_shared<Component>(1);
  // Connect component to node.
  bool returnValue = node.connectComponent(component);
  // Verify that component was connected.
  EXPECT_TRUE(returnValue);
  EXPECT_EQ(node.getComponents().size(), 1);
  EXPECT_EQ(node.getComponents().at(0)->getId(), 1);
}

// Test connection same component again to node.
TEST(node, connect_component_again) {
  // Create new Node object.
  Node node(1);
  // Create new Component object.
  auto component = std::make_shared<Component>(1);
  // Connect component to node.
  bool firstConnection = node.connectComponent(component);
  // Try to connect same component again.
  bool secondConnection = node.connectComponent(component);
  // Verify that component was connected only once.
  EXPECT_TRUE(firstConnection);
  EXPECT_FALSE(secondConnection);
  EXPECT_EQ(node.getComponents().size(), 1);
}

// Test disconnecting component that is connected to node.
TEST(node, disconnect_component_that_is_connected) {
  // Create new Node object.
  Node node(1);
  // Create new Component object.
  auto component = std::make_shared<Component>(1);
  // Connect component to node.
  bool connect = node.connectComponent(component);
  EXPECT_TRUE(connect);
  EXPECT_EQ(node.getComponents().size(), 1);
  // Try to disconnect component.
  bool disconnect = node.disconnectComponent(component);
  // Verify that component was disconnected.
  EXPECT_TRUE(disconnect);
  EXPECT_EQ(node.getComponents().size(), 0);
}

// Test disconnecting component that is not connected to node.
TEST(node, disconnect_component_that_is_not_connected) {
  // Create new Node object.
  Node node(1);
  // Create new Component object.
  auto component = std::make_shared<Component>(1);
  // Try to disconnect component.
  bool disconnect = node.disconnectComponent(component);
  // Verify that component was disconnected.
  EXPECT_FALSE(disconnect);
}

// Test whether node is connected to component or not.
TEST(node, is_connected_to_component) {
  // Create new Node object.
  Node node(1);
  // Create new component object.
  auto component = std::make_shared<Component>(1);
  // Check if component is connected.
  bool isConnected = node.isConnectedToComponent(component);
  EXPECT_FALSE(isConnected);
  // Connect component to node.
  node.connectComponent(component);
  // Check if component is connected.
  isConnected = node.isConnectedToComponent(component);
  EXPECT_TRUE(isConnected);
}