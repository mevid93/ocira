#include "component.hpp"
#include "node.hpp"
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

// Test that first node can be connected.
TEST(component, connect_first_node) {
  // Create new component object.
  Component component(1);
  // Create new node object.
  std::shared_ptr<Node> node = std::make_shared<Node>(1);
  // Connect first node to component.
  bool wasConnected = component.connectFirstNode(node);
  EXPECT_TRUE(wasConnected);
  // Try to connect node again.
  wasConnected = component.connectFirstNode(node);
  EXPECT_FALSE(wasConnected);
  wasConnected = component.connectSecondNode(node);
  EXPECT_FALSE(wasConnected);
}

// Test that second node can be connected.
TEST(component, connect_second_node) {
  // Create new component object.
  Component component(1);
  // Create new node object.
  std::shared_ptr<Node> node = std::make_shared<Node>(1);
  // Connect second node to component.
  bool wasConnected = component.connectSecondNode(node);
  EXPECT_TRUE(wasConnected);
  // Try to connect node again.
  wasConnected = component.connectSecondNode(node);
  EXPECT_FALSE(wasConnected);
  wasConnected = component.connectFirstNode(node);
  EXPECT_FALSE(wasConnected);
}

// Test disconnecting node.
TEST(component, disconnect_node) {
  // Creare new component object.
  Component component(1);
  // Create new node object.
  std::shared_ptr<Node> node = std::make_shared<Node>(1);
  // Connect node to component.
  component.connectFirstNode(node);
  // Disconnect node.
  bool wasDisconnected = component.disconnectNode(node);
  EXPECT_TRUE(wasDisconnected);
  wasDisconnected = component.disconnectNode(node);
  EXPECT_FALSE(wasDisconnected);
  // Connect node to component.
  component.connectSecondNode(node);
  // Disconnect node.
  wasDisconnected = component.disconnectNode(node);
  EXPECT_TRUE(wasDisconnected);
  wasDisconnected = component.disconnectNode(node);
  EXPECT_FALSE(wasDisconnected);
}

// Test if component is connected to node.
TEST(component, is_connected_to_node) {
  // Create new component object.
  Component component(1);
  // Create new node objects.
  std::shared_ptr<Node> node1 = std::make_shared<Node>(1);
  std::shared_ptr<Node> node2 = std::make_shared<Node>(2);
  std::shared_ptr<Node> node3 = std::make_shared<Node>(3);
  // Connect nodes to component.
  component.connectFirstNode(node1);
  component.connectSecondNode(node2);
  // Verify connections.
  EXPECT_TRUE(component.isConnectedToNode(node1));
  EXPECT_TRUE(component.isConnectedToNode(node2));
  EXPECT_FALSE(component.isConnectedToNode(node3));
}