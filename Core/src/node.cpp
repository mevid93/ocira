#include "node.hpp"

namespace ocira::core {
Node::Node(uint32_t id) : id(id) {}

uint32_t Node::getId() const { return this->id; }

void Node::connectComponent(std::shared_ptr<Component> component) {
  // TODO: IMPLEMENT ME
}

void Node::disconnectComponent(std::shared_ptr<Component> component) {
  // TODO: IMPLEMENT ME
}

const std::vector<std::shared_ptr<Component>> &Node::getComponents() const {
  // TODO: IMPLEMENT ME
}
} // namespace ocira::core
