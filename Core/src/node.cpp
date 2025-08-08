#include "node.hpp"
#include <algorithm>

namespace ocira::core {
Node::Node(uint32_t id) : m_id(id) {
  this->m_components = std::vector<std::shared_ptr<Component>>();
}

Node::~Node() {}

uint32_t Node::getId() const { return this->m_id; }

bool Node::connectComponent(std::shared_ptr<Component> component) {
  // Check if component already has been connected.
  bool exists = this->isConnectedToComponent(component);

  // "If already connected, then do not connect again."
  if (exists) {
    return false;
  }

  this->m_components.push_back(component);

  return true;
}

bool Node::disconnectComponent(std::shared_ptr<Component> component) {
  auto originalSize = this->m_components.size();

  // Delete components that have same id as target component.
  this->m_components.erase(std::remove_if(this->m_components.begin(), this->m_components.end(),
                                          [&](const std::shared_ptr<Component> &c) {
                                            return c && c->getId() == component->getId();
                                          }),
                           this->m_components.end());

  return this->m_components.size() < originalSize;
}

const std::vector<std::shared_ptr<Component>> &Node::getComponents() const {
  return this->m_components;
}

bool Node::isConnectedToComponent(std::shared_ptr<Component> component) const {
  return std::any_of(
      this->m_components.begin(), this->m_components.end(),
      [&](const std::shared_ptr<Component> &c) { return c && c->getId() == component->getId(); });
}
} // namespace ocira::core
