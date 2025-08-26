//==============================================================================
// Project:     OCIRA (core library)
// File:        circuit_transformer.hpp
// Author:      Martin Vidjeskog
// Created:     2025-08-26
// Description: Code logic to transform circuit to G matrix and J vector.
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
// - 2025-08-25 Martin Vidjeskog: Initial creation
// - [YYYY-MM-DD] [Contributor]: [Description of change]
//==============================================================================
// Notes:
// - Please retain this header in all redistributed versions.
//==============================================================================

#ifndef OCIRA_CORE_CIRCUIT_TRANSFORMER_HPP
#define OCIRA_CORE_CIRCUIT_TRANSFORMER_HPP

#include "bus.hpp"
#include "circuit.hpp"
#include "dc_current_source.hpp"
#include "resistor.hpp"
#include <armadillo>
#include <unordered_map>

namespace ocira::core {

/// @brief Bus number. Each bus that is used for conductance matrix has a unique bus number. Bus
/// that is connected to ground always has bus number 0.
using BusNumber = uint32_t;

/// @brief Circuit transformer class. Used to transform circuit into conductance matrix and current
/// vector (G * U = J). Voltage vector U is unknown.
class CircuitTransformer {
public:
  /// @brief Constructor.
  /// @param circuit Circuit to be transformed.
  CircuitTransformer(const std::shared_ptr<Circuit> &circuit);

  /// @brief Destructor.
  ~CircuitTransformer();

  /// @brief Get conductance matrix.
  /// @return Conductance matrix G.
  std::shared_ptr<arma::cx_mat> getConductanceMatrix() const;

  /// @brief Get current vector.
  /// @return Current vector J.
  std::shared_ptr<arma::cx_vec> getCurrentVector() const;

  /// @brief Each bus has an id, but for matrix computation we are using different numbering system.
  /// This method returns a hash map, where each bus number is mapped to corresponding bus id.
  /// @return Bus number to bus id mapping.
  const std::unordered_map<BusNumber, BusId> &getBusNumberMap() const;

  /// @brief Each bus has an id, but for matrix computation we are using different numbering system.
  /// This method returns a hash map, where each bus id is mapped to corresponding bus number.
  /// @return Bus id to bus number mapping.
  const std::unordered_map<BusId, BusNumber> &getBusIdMap() const;

private:
  std::shared_ptr<Circuit> m_circuit;
  std::shared_ptr<arma::cx_mat> m_G;
  std::shared_ptr<arma::cx_vec> m_J;
  std::unordered_map<BusNumber, BusId> m_busNumberMap;
  std::unordered_map<BusId, BusNumber> m_busIdMap;

  /// @brief Update G matrix and J vector with circuit components.
  void _transformComponents();

  /// @brief Update G matrix with resistor component.
  /// @param resistor Resistor component to transform.
  void _transformResistor(std::shared_ptr<Resistor> resistor);

  /// @brief Update J vector with DC current source component.
  /// @param dcCurrentSrc DC current source component to transform.
  void _transformDcCurrentSource(std::shared_ptr<DCCurrentSource> dcCurrentSrc);
};
}; // namespace ocira::core

#endif