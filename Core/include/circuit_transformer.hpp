//==============================================================================
// Project:     OCIRA (core library)
// File:        circuit_transformer.hpp
// Author:      Martin Vidjeskog
// Created:     2025-08-26
// Description: Code logic to transform circuit to Y matrix and J vector.
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
// - 2025-08-26 Martin Vidjeskog: Initial creation
// - [YYYY-MM-DD] [Contributor]: [Description of change]
//==============================================================================
// Notes:
// - Please retain this header in all redistributed versions.
//==============================================================================

#ifndef OCIRA_CORE_CIRCUIT_TRANSFORMER_HPP
#define OCIRA_CORE_CIRCUIT_TRANSFORMER_HPP

#include "bus.hpp" // For BusId.
#include <armadillo>
#include <unordered_map>

namespace ocira::core::components {

// Forward declarations.
class DCCurrentSource;
class DCVoltageSource;
class Resistor;

} // namespace ocira::core::components

namespace ocira::core {

// Forward declarations.
class Circuit;

/// @brief Unique identifier used for matrix computations.
/// Each bus in the admittance matrix is assigned a sequential BusNumber.
/// The ground bus is always assigned BusNumber 0.
using BusNumber = uint32_t;

/// @brief Transforms a circuit into its mathematical representation for simulation.
/// Converts the circuit into an admittance matrix (Y) and a current vector (J),
/// forming the equation Y * U = J, where U is the unknown voltage vector.
/// We use modified nodal analysis: https://lpsa.swarthmore.edu/Systems/Electrical/mna/MNA3.html.
/// Y = [[G B], [C D]].
class CircuitTransformer {
public:
  /// @brief Constructs a transformer for the given circuit.
  /// Initializes internal data structures and prepares for matrix generation.
  /// @param circuit Shared pointer to the circuit to be transformed.
  CircuitTransformer(const std::shared_ptr<Circuit> &circuit);

  /// @brief Default destructor.
  ~CircuitTransformer() = default;

  /// @brief Retrieves the computed admittance matrix Y.
  /// Represents the conductance relationships between buses.
  /// @return Shared pointer to the complex-valued admittance matrix.
  std::shared_ptr<arma::cx_mat> getAdmittanceMatrix() const;

  /// @brief Retrieves the computed current vector J.
  /// Represents the net current injected into each bus.
  /// @return Shared pointer to the complex-valued current vector.
  std::shared_ptr<arma::cx_vec> getCurrentVector() const;

  /// @brief Maps matrix bus numbers to their corresponding circuit bus IDs.
  /// Useful for interpreting matrix results in terms of circuit topology.
  /// @return Reference to the bus number → bus ID mapping.
  const std::unordered_map<BusNumber, components::BusId> &getBusNumberMap() const;

  /// @brief Maps circuit bus IDs to their corresponding matrix bus numbers.
  /// Enables lookup of matrix indices based on circuit structure.
  /// @return Reference to the bus ID → bus number mapping.
  const std::unordered_map<components::BusId, BusNumber> &getBusIdMap() const;

private:
  uint32_t m_sizeG; // G size
  uint32_t m_sizeB; // B size
  std::shared_ptr<Circuit> m_circuit;
  std::shared_ptr<arma::cx_mat> m_Y;
  std::shared_ptr<arma::cx_vec> m_J;
  std::unordered_map<BusNumber, components::BusId> m_busNumberMap;
  std::unordered_map<components::BusId, BusNumber> m_busIdMap;

  /// @brief Populates the admittance matrix and current vector based on circuit components.
  void _transformComponents();

  /// @brief Adds the contribution of a resistor to the admittance matrix.
  /// @param resistor Shared pointer to the resistor component.
  void _transformResistor(std::shared_ptr<components::Resistor> resistor);

  /// @brief Adds the contribution of a DC current source to the current vector.
  /// @param dcCurrentSrc Shared pointer to the DC current source component.
  void _transformDCCurrentSource(std::shared_ptr<components::DCCurrentSource> dcCurrentSrc);

  /// @brief Adds the contribution of DC voltage source to the admittance matrix and current vector.
  /// @param dcVoltageSrc Shared pointer to the DC voltage source component.
  /// @param voltageSourceIndex Index of the auxiliary current variable introduced for this DC
  /// voltage source. This index corresponds to the additional row and column in the MNA matrix used
  /// to enforce the voltage constraint.
  void _transformDCVoltageSource(std::shared_ptr<components::DCVoltageSource> dcVoltageSrc,
                                 uint32_t voltageSourceIndex);
};
}; // namespace ocira::core

#endif // OCIRA_CORE_CIRCUIT_TRANSFORMER_HPP