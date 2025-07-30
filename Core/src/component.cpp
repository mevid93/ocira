#include "component.hpp"
#include "node.hpp"

namespace ocira::core {
Component::Component(uint32_t id) : id(id) {
  // For base class we use component type UNDEFINED.
  this->type = ComponentType::UNDEFINED;
}

Component::~Component() {}

uint32_t Component::getId() const { return this->id; }

ComponentType Component::getComponentType() const { return this->type; }

bool Component::connectFirstNode(std::weak_ptr<Node> node1) {
  // NOT IMPLEMENTED!
}

bool Component::connectSecondNode(std::weak_ptr<Node> node2) {
  // NOT IMPLEMENTED!
}

bool Component::disconnectNode(std::weak_ptr<Node> node) {
  // NOT IMPELMENTED!
}
} // namespace ocira::core