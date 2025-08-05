#include "circuit.hpp"

namespace ocira::core {

Circuit::Circuit() {}

Circuit::~Circuit() {}

const std::vector<std::shared_ptr<Component>> &Circuit::getComponents() const {
  return this->components;
}

const std::vector<std::shared_ptr<Node>> &Circuit::getNodes() const { return this->nodes; }

void Circuit::setNodes(std::vector<std::shared_ptr<Node>> nodes) { this->nodes = nodes; }

void Circuit::setComponents(std::vector<std::shared_ptr<Component>> components) {
  this->components = components;
}
} // namespace ocira::core