//==============================================================================
// Project:     OCIRA (core library)
// File:        circuit_transformer.cpp
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

#include "circuit_transformer.hpp"
#include "circuit.hpp"
#include "dc_current_source.hpp"
#include "resistor.hpp"

namespace ocira::core {

CircuitTransformer::CircuitTransformer(const std::shared_ptr<Circuit> &circuit)
    : m_circuit(circuit) {
  // 1. Assign each node a indice (ground will be zero).
  uint32_t indice = 1;
  for (auto bus : circuit->getBuses()) {
    // Check that there is no ground node connected to bus.
    bool isGround = false;
    for (auto component : bus->getComponents()) {
      if (component->getComponentType() == ComponentType::GROUND) {
        isGround = true;
        break;
      }
    }

    // Ground connection exists, skip the bus.
    if (isGround) {
      this->m_busIdMap[bus->getId()] = 0;
      this->m_busNumberMap[0] = bus->getId();
      continue;
    }

    this->m_busIdMap[bus->getId()] = indice;
    this->m_busNumberMap[indice] = bus->getId();
    indice++;
  }

  // 2. Initialize Y matrix and J vector.
  uint32_t n = indice;
  this->m_Y = std::make_shared<arma::cx_mat>(n - 1, n - 1, arma::fill::zeros);
  this->m_J = std::make_shared<arma::cx_vec>(n - 1, arma::fill::zeros);

  // 3. Loop through the components and update the Y matrix and J vector.
  this->_transformComponents();
}

std::shared_ptr<arma::cx_mat> CircuitTransformer::getAdmittanceMatrix() const { return this->m_Y; }

std::shared_ptr<arma::cx_vec> CircuitTransformer::getCurrentVector() const { return this->m_J; }

const std::unordered_map<BusNumber, BusId> &CircuitTransformer::getBusNumberMap() const {
  return this->m_busNumberMap;
}

const std::unordered_map<BusId, BusNumber> &CircuitTransformer::getBusIdMap() const {
  return this->m_busIdMap;
}

// PRIVATE MEMBER METHODS.

void CircuitTransformer::_transformComponents() {
  for (auto component : m_circuit->getComponents()) {
    switch (component->getComponentType()) {
    case ComponentType::GROUND:
      break; // Doesn't affect the matrix directly.
    case ComponentType::WIRE:
      break; // Doesn't affect the matrix directly.
    case ComponentType::RESISTOR: {
      std::shared_ptr<Resistor> resistor = std::dynamic_pointer_cast<Resistor>(component);
      this->_transformResistor(resistor);
      break;
    }
    case ComponentType::DC_CURRENT_SOURCE: {
      std::shared_ptr<DCCurrentSource> dcCurrentSrc =
          std::dynamic_pointer_cast<DCCurrentSource>(component);
      this->_transformDCCurrentSource(dcCurrentSrc);
      break;
    }
    default:
      throw std::runtime_error("Unsupported component type!");
    }
  }
}

void CircuitTransformer::_transformResistor(std::shared_ptr<Resistor> resistor) {
  float conductance = resistor->getConductance();

  auto connection1 = resistor->getConnections()[0];
  auto connection2 = resistor->getConnections()[1];

  auto b1 = connection1.bus.lock();
  auto b2 = connection2.bus.lock();

  if (b1 && b2) {
    BusId busId1 = b1->getId();
    BusId busId2 = b2->getId();
    BusNumber i = this->m_busIdMap[busId1];
    BusNumber j = this->m_busIdMap[busId2];

    if (i != 0) {
      (*this->m_Y)(i - 1, i - 1) += conductance;
    }

    if (j != 0) {
      (*this->m_Y)(j - 1, j - 1) += conductance;
    }

    if (i != 0 && j != 0) {
      (*this->m_Y)(i - 1, j - 1) -= conductance;
      (*this->m_Y)(j - 1, i - 1) -= conductance;
    }
  } else {
    throw std::runtime_error("Unexpected error! Pointer not existing!");
  }
}

void CircuitTransformer::_transformDCCurrentSource(std::shared_ptr<DCCurrentSource> dcCurrentSrc) {
  float amps = dcCurrentSrc->getAmps();

  auto connection1 = dcCurrentSrc->getConnections()[0];
  auto connection2 = dcCurrentSrc->getConnections()[1];

  auto b1 = connection1.bus.lock();
  auto b2 = connection2.bus.lock();

  if (b1 && b2) {
    BusId busId1 = b1->getId();
    BusId busId2 = b2->getId();
    BusNumber i = this->m_busIdMap[busId1];
    BusNumber j = this->m_busIdMap[busId2];

    if (i != 0) {
      if (connection1.role == TerminalRole::POSITIVE) {
        (*this->m_J)(i - 1) += amps;
      } else {
        (*this->m_J)(i - 1) -= amps;
      }
    }

    if (j != 0) {
      if (connection2.role == TerminalRole::POSITIVE) {
        (*this->m_J)(j - 1) += amps;
      } else {
        (*this->m_J)(j - 1) -= amps;
      }
    }
  } else {
    throw std::runtime_error("Unexpected error! Pointer not existing!");
  }
}

}; // namespace ocira::core