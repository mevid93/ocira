#include "node.hpp"
#include <algorithm>

namespace ocira::core {
Node::Node(uint32_t id) : id(id) { this->components = std::vector<std::shared_ptr<Component>>(); }

Node::~Node() {}

uint32_t Node::getId() const { return this->id; }

bool Node::connectComponent(std::shared_ptr<Component> component) {
  // Check if component already has been connected.
  bool exists = this->isConnectedToComponent(component);

  // "If already connected, then do not connect again."
  if (exists) {
    return false;
  }

  this->components.push_back(component);

  return true;
}

bool Node::disconnectComponent(std::shared_ptr<Component> component) {
  auto originalSize = this->components.size();

  // Delete components that have same id as target component.
  this->components.erase(std::remove_if(this->components.begin(), this->components.end(),
                                        [&](const std::shared_ptr<Component> &c) {
                                          return c && c->getId() == component->getId();
                                        }),
                         this->components.end());

  return this->components.size() < originalSize;
}

const std::vector<std::shared_ptr<Component>> &Node::getComponents() const {
  return this->components;
}

bool Node::isConnectedToComponent(std::shared_ptr<Component> component) const {
  return std::any_of(
      this->components.begin(), this->components.end(),
      [&](const std::shared_ptr<Component> &c) { return c && c->getId() == component->getId(); });
}
} // namespace ocira::core
