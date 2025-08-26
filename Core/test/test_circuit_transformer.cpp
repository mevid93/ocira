//==============================================================================
// File:        test_circuit_transformer.cpp
// Author:      Martin Vidjeskog
// Created:     2025-08-26
// Description: Unit tests for CircuitTransformer class in OCIRA core library.
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
// - Tests cover CircuitTransfomer class.
// - Run with: ctest or ./core_tests or ./core_tests --gtest_filter=circuit_transfomer.*
//==============================================================================

#include "circuit.hpp"
#include "circuit_transformer.hpp"
#include "example_circuit_generator.hpp"
#include <gtest/gtest.h>
#include <memory>

using namespace ocira::core;

// Test circuit transformer for example circuit 1.
TEST(circuit_transfomer, example_circuit_1) {
  // Get example circuit.
  const auto circuit = test::utils::ExampleCircuitGenerator::getExampleCircuit1();

  // Get conductance matrix, current vector, and bus mappings.
  CircuitTransformer circuitTransformer(circuit);
  std::shared_ptr<arma::cx_mat> yMatrix = circuitTransformer.getAdmittanceMatrix();
  std::shared_ptr<arma::cx_vec> iVector = circuitTransformer.getCurrentVector();
  std::unordered_map<BusNumber, BusId> bNumberMap = circuitTransformer.getBusNumberMap();
  std::unordered_map<BusId, BusNumber> bIdMap = circuitTransformer.getBusIdMap();

  // Verify results.
  EXPECT_EQ(yMatrix->n_rows, 1);
  EXPECT_EQ(yMatrix->n_cols, 1);
  EXPECT_FLOAT_EQ((*yMatrix)(0, 0).real(), 1.0 / 200);
  EXPECT_FLOAT_EQ((*yMatrix)(0, 0).imag(), 0);

  EXPECT_EQ(iVector->n_elem, 1);
  EXPECT_EQ((*iVector)(0).real(), 1.0f);

  EXPECT_EQ(bNumberMap.size(), 2);
  EXPECT_EQ(bIdMap.size(), 2);
}