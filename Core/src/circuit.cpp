#include "circuit.hpp"

namespace ocira::core {

Circuit::Circuit() {}

Circuit::~Circuit() {}

const std::vector<std::shared_ptr<Component>> &Circuit::getComponents() const {
  return this->m_components;
}

const std::vector<std::shared_ptr<Node>> &Circuit::getNodes() const { return this->m_nodes; }

void Circuit::setNodes(std::vector<std::shared_ptr<Node>> nodes) { this->m_nodes = nodes; }

void Circuit::setComponents(std::vector<std::shared_ptr<Component>> components) {
  this->m_components = components;
}
} // namespace ocira::core