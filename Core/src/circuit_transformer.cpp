#include "circuit_transformer.hpp"

namespace ocira::core {
CircuitTransformer::CircuitTransformer(const std::shared_ptr<Circuit> &circuit)
    : m_circuit(circuit) {}

CircuitTransformer::~CircuitTransformer() {}

arma::cx_mat CircuitTransformer::getConductanceMatrix() const {
  // TODO!! Implement this!!!!
  arma::cx_mat mat;
  return mat;
}

arma::cx_vec CircuitTransformer::getCurrentVector() const {
  // TODO!! Implement this!!!!
  arma::cx_vec vec;
  return vec;
}

std::unordered_map<BusNumber, BusId> CircuitTransformer::getBusMappings() const {
  std::unordered_map<BusNumber, BusId> mappings;
  // TODO!! Compute the actual mappings!!!!
  return mappings;
}

}; // namespace ocira::core