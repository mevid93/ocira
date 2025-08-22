#ifndef OCIRA_CORE_CIRCUIT_TRANSFORMER_HPP
#define OCIRA_CORE_CIRCUIT_TRANSFORMER_HPP

#include "bus.hpp"
#include "circuit.hpp"
#include <armadillo>
#include <unordered_map>

namespace ocira::core {
/// @brief Bus number. Each bus that is used for conductance matrix has a unique bus number.
using BusNumber = uint32_t;

/// @brief Circuit transformer class. Used to transform circuit into conductance matrix and current
/// vector (G * V = I). Voltage vector U is unknown.
class CircuitTransformer {
public:
  /// @brief Constructor.
  CircuitTransformer(const std::shared_ptr<Circuit> &circuit);

  /// @brief Destructor.
  ~CircuitTransformer();

  /// @brief Get conductance matrix.
  arma::cx_mat getConductanceMatrix() const;

  /// @brief Get current vector.
  arma::cx_vec getCurrentVector() const;

  /// @brief Each bus has an id, but for matrix computation we are using different numbering system.
  /// This method returns a hash map, where each bus number is mapped to corresponding bus id.
  /// This is needed for mapping the computation results to correct buses.
  std::unordered_map<BusNumber, BusId> getBusMappings() const;

private:
  std::shared_ptr<Circuit> m_circuit;
};
}; // namespace ocira::core

#endif