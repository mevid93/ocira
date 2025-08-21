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

// Test setting circuit buses.
TEST(circuit, set_buses) {
  // Create new circuit.
  Circuit circuit;
  // Create buses.
  std::vector<std::shared_ptr<Bus>> buses;
  buses.push_back(std::make_shared<Bus>(1));
  buses.push_back(std::make_shared<Bus>(2));
  // Set buses to circuit.
  circuit.setBuses(buses);
  // Verify that operation was succesful.
  EXPECT_EQ(circuit.getBuses().size(), 2);
  EXPECT_EQ(circuit.getBuses().at(1)->getId(), 2);
}
