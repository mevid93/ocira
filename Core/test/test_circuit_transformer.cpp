#include "circuit.hpp"
#include "circuit_transformer.hpp"
#include "component.hpp"
#include "dc_current_source.hpp"
#include "ground.hpp"
#include "resistor.hpp"
#include <gtest/gtest.h>
#include <memory>

using namespace ocira::core;

// Test that circuit transformer constructor works.
TEST(circuit_transformer, constructor_works) {
  // Create a circuit.
  std::shared_ptr<Circuit> circuit = std::make_shared<Circuit>();
  // Create circuit transformer.
  CircuitTransformer circuitTransformer(circuit);
  // Check values.
  EXPECT_EQ(circuitTransformer.getBusMappings().size(), 0);
}

// Test circuit transformer for simple case, where circuit has one dc current source, and
// one resistor.
TEST(circuit_transfomer, circuit_with_dc_current_source_and_resistor) {
  // Create a circuit.
  std::shared_ptr<Circuit> circuit = std::make_shared<Circuit>();
  std::shared_ptr<DCCurrentSource> dcCurrentSrc = std::make_shared<DCCurrentSource>(1, 1.0);
  std::shared_ptr<Resistor> resistor = std::make_shared<Resistor>(2, 200);
  std::shared_ptr<Ground> ground = std::make_shared<Ground>(3);
  std::shared_ptr<Bus> bus1 = std::make_shared<Bus>(1);
  std::shared_ptr<Bus> bus2 = std::make_shared<Bus>(2);

  dcCurrentSrc->addConnection(bus1, TerminalRole::NEGATIVE);
  dcCurrentSrc->addConnection(bus2, TerminalRole::POSITIVE);
  resistor->addConnection(bus1, TerminalRole::NEGATIVE);
  resistor->addConnection(bus2, TerminalRole::POSITIVE);
  ground->addConnection(bus1, TerminalRole::NEGATIVE);

  std::vector<std::shared_ptr<Component>> components;
  components.push_back(dcCurrentSrc);
  components.push_back(resistor);
  components.push_back(ground);

  std::vector<std::shared_ptr<Bus>> buses;
  buses.push_back(bus1);
  buses.push_back(bus2);

  circuit->setBuses(buses);
  circuit->setComponents(components);

  // Get conductance matrix, current vector, and bus mappings.
  CircuitTransformer circuitTransformer(circuit);
  arma::cx_mat gMatrix = circuitTransformer.getConductanceMatrix();
  arma::cx_vec iVector = circuitTransformer.getCurrentVector();
  std::unordered_map<BusNumber, BusId> bMappings = circuitTransformer.getBusMappings();

  // Verify results.
  EXPECT_EQ(gMatrix.n_rows, 1);
  EXPECT_EQ(gMatrix.n_cols, 2);
  EXPECT_EQ(iVector.n_elem, 1);
  EXPECT_EQ(bMappings.size(), 1);
}