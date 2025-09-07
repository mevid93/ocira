//==============================================================================
// Project:     OCIRA (core library)
// File:        circuit_calculator.hpp
// Author:      Martin Vidjeskog
// Created:     2025-09-07
// Description: Class to calculate U vector (unknown voltages in a circuit).
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
// Revision History:
// - 2025-09-07 Martin Vidjeskog: Initial creation
// - [YYYY-MM-DD] [Contributor]: [Description of change]
//==============================================================================
// Notes:
// - Please retain this header in all redistributed versions.
//==============================================================================

#ifndef OCIRA_CORE_CIRCUIT_CALCULATOR_HPP
#define OCIRA_CORE_CIRCUIT_CALCULATOR_HPP

#include <armadillo>

namespace ocira::core {

/// @class CircuitCalculator
/// @brief Provides core functionality for solving electrical circuits using Modified Nodal Analysis
/// (MNA).
///
/// This class offers static methods to compute node voltages and source currents in linear
/// electrical networks. It operates on complex admittance matrices and current/source vectors,
/// making it suitable for both DC and AC analysis. The class is intentionally non-instantiable and
/// serves as a utility for matrix-based circuit solving.
///
/// Usage typically involves constructing the admittance matrix (Y) and source vector (J),
/// then calling solveVoltages(Y, J) to obtain the solution vector.
class CircuitCalculator {
public:
  /// @brief Make Class non-instantiable.
  CircuitCalculator() = delete;

  /// @brief Solves the system of equations Y * V = J for node voltages and source currents.
  /// @param Y Complex admittance matrix representing the circuit (includes G, B, C, D blocks).
  /// @param J Complex current/source vector (includes injected currents and voltage source
  /// constraints).
  /// @return Complex solution vector V containing node voltages and auxiliary source currents.
  static std::shared_ptr<arma::cx_vec> solveVoltages(const std::shared_ptr<arma::cx_mat> &Y,
                                                     const std::shared_ptr<arma::cx_vec> &J);

private:
};
}; // namespace ocira::core

#endif // OCIRA_CORE_CIRCUIT_CALCULATOR_HPP