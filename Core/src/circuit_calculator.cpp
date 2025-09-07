//==============================================================================
// Project:     OCIRA (core library)
// File:        circuit_calculator.cpp
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

#include "circuit_calculator.hpp"

namespace ocira::core {

std::shared_ptr<arma::cx_vec>
CircuitCalculator::solveVoltages(const std::shared_ptr<arma::cx_mat> &Y,
                                 const std::shared_ptr<arma::cx_vec> &J) {
  arma::cx_vec U = arma::solve(*Y, *J);
  return std::make_shared<arma::cx_vec>(U);
}

} // namespace ocira::core