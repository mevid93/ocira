#include "circuit.hpp"

namespace ocira::core {

Circuit::Circuit() {}

Circuit::~Circuit() {}

const std::vector<std::shared_ptr<Component>> &Circuit::getComponents() const {
  return this->m_components;
}

const std::vector<std::shared_ptr<Bus>> &Circuit::getBuses() const { return this->m_buses; }

void Circuit::setBuses(std::vector<std::shared_ptr<Bus>> buses) { this->m_buses = buses; }

void Circuit::setComponents(std::vector<std::shared_ptr<Component>> components) {
  this->m_components = components;
}
} // namespace ocira::core