#include "circuit.hpp"
#include <gtest/gtest.h>
#include <memory>

using namespace ocira::core;

// Test Circuit class default constructor.
TEST(circuit, constructor_works) {
  // Create new circuit.
  Circuit circuit;
}

// Test setting circuit components.
TEST(circuit, set_components) {
  // Create new circuit.
  Circuit circuit;
  // Create components.
  std::vector<std::shared_ptr<Component>> components;
  components.push_back(std::make_shared<Component>(1));
  components.push_back(std::make_shared<Component>(2));
  // Set components to circuit.
  circuit.setComponents(components);
  // Verify that operation was succesful.
  EXPECT_EQ(circuit.getComponents().size(), 2);
  EXPECT_EQ(circuit.getComponents().at(1)->getId(), 2);
}

// Test setting circuit nodes.
TEST(circuit, set_nodes) {
  // Create new circuit.
  Circuit circuit;
  // Create nodes.
  std::vector<std::shared_ptr<Node>> nodes;
  nodes.push_back(std::make_shared<Node>(1));
  nodes.push_back(std::make_shared<Node>(2));
  // Set nodes to circuit.
  circuit.setNodes(nodes);
  // Verify that operation was succesful.
  EXPECT_EQ(circuit.getNodes().size(), 2);
  EXPECT_EQ(circuit.getNodes().at(1)->getId(), 2);
}
