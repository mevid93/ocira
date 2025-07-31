#include "component.hpp"
#include "node.hpp"
#include <algorithm>

namespace ocira::core {
Component::Component(uint32_t id) : id(id) {
  // For base class we use component type UNDEFINED.
  this->type = ComponentType::UNDEFINED;
}

Component::~Component() {}

uint32_t Component::getId() const { return this->id; }

ComponentType Component::getComponentType() const { return this->type; }

bool Component::connectFirstNode(std::weak_ptr<Node> node) {
  // Check if node is already connected.
  bool isConnected = this->isConnectedToNode(node);
  if (isConnected)
    return false;
  // Connect the node.
  this->node1 = node;
  return true;
}

bool Component::connectSecondNode(std::weak_ptr<Node> node) {
  // Check if node is already connected.
  bool isConnected = this->isConnectedToNode(node);
  if (isConnected)
    return false;
  // Connect the node.
  this->node2 = node;
  return true;
}

bool Component::disconnectNode(std::weak_ptr<Node> node) {
  auto target = node.lock();
  if (!target)
    return false;

  auto n1 = node1.lock();
  if (n1 && target->getId() == n1->getId()) {
    this->node1.reset();
    return true;
  }

  auto n2 = node2.lock();
  if (n2 && target->getId() == n2->getId()) {
    this->node2.reset();
    return true;
  }
  return false;
}

bool Component::isConnectedToNode(std::weak_ptr<Node> node) const {
  auto target = node.lock();
  if (!target)
    return false;

  auto n1 = node1.lock();
  if (n1 && target->getId() == n1->getId())
    return true;

  auto n2 = node2.lock();
  return n2 && target->getId() == n2->getId();
}
} // namespace ocira::core