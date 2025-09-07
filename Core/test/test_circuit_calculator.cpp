//==============================================================================
// File:        test_circuit_calculator.cpp
// Author:      Martin Vidjeskog
// Created:     2025-09-07
// Description: Unit tests for CircuitCalculator class in OCIRA core library.
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
// - Tests cover CircuitCalculator class.
// - Run with: ctest or ./core_tests or ./core_tests --gtest_filter=circuit_calculator.*
//==============================================================================

#include "circuit.hpp"
#include "circuit_calculator.hpp"
#include "circuit_transformer.hpp"
#include "example_circuit_generator.hpp"
#include <gtest/gtest.h>
#include <memory>

using namespace ocira::core;
using namespace ocira::core::components;
using namespace ocira::core::test::helpers;

// Test circuit transformer for example circuit 1.
TEST(circuit_calculator, example_circuit_1) {
  // Get example circuit.
  const auto circuit = ExampleCircuitGenerator::getExampleCircuit1();

  // Get conductance matrix, current vector, and bus mappings.
  CircuitTransformer circuitTransformer(circuit);
  std::shared_ptr<arma::cx_mat> yMatrix = circuitTransformer.getAdmittanceMatrix();
  std::shared_ptr<arma::cx_vec> iVector = circuitTransformer.getCurrentVector();

  // Peform calculation.
  std::shared_ptr<arma::cx_vec> solution_vector =
      CircuitCalculator::solveVoltages(yMatrix, iVector);

  // Verify results.
  EXPECT_EQ(solution_vector->n_rows, 1);
  EXPECT_EQ(solution_vector->n_cols, 1);

  EXPECT_FLOAT_EQ((*solution_vector)(0).real(), 200);
}

// Test circuit transformer for example circuit 2.
TEST(circuit_calculator, example_circuit_2) {
  // Get example circuit.
  const auto circuit = ExampleCircuitGenerator::getExampleCircuit2();

  // Get conductance matrix, current vector, and bus mappings.
  CircuitTransformer circuitTransformer(circuit);
  std::shared_ptr<arma::cx_mat> yMatrix = circuitTransformer.getAdmittanceMatrix();
  std::shared_ptr<arma::cx_vec> iVector = circuitTransformer.getCurrentVector();

  // Peform calculation.
  std::shared_ptr<arma::cx_vec> solution_vector =
      CircuitCalculator::solveVoltages(yMatrix, iVector);

  // Verify results.
  EXPECT_EQ(solution_vector->n_rows, 5);
  EXPECT_EQ(solution_vector->n_cols, 1);

  EXPECT_FLOAT_EQ((*solution_vector)(0).real(), 5.0f);
  EXPECT_FLOAT_EQ((*solution_vector)(1).real(), 10.725806f);
  EXPECT_FLOAT_EQ((*solution_vector)(2).real(), 3.4314516f);
  EXPECT_FLOAT_EQ((*solution_vector)(3).real(), 2.6209679f);
  EXPECT_FLOAT_EQ((*solution_vector)(4).real(), 0.057258062f); // This is current, not voltage.
}