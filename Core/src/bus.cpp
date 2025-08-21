#include "bus.hpp"
#include <algorithm>

namespace ocira::core {
Bus::Bus(uint32_t id) : m_id(id) { this->m_components = std::vector<std::shared_ptr<Component>>(); }

Bus::~Bus() {}

uint32_t Bus::getId() const { return this->m_id; }

bool Bus::connectComponent(std::shared_ptr<Component> component) {
  // Check if component already has been connected.
  bool exists = this->isConnectedToComponent(component);

  // If already connected, then do not connect again.
  if (exists) {
    return false;
  }

  this->m_components.push_back(component);

  return true;
}

bool Bus::disconnectComponent(std::shared_ptr<Component> component) {
  auto originalSize = this->m_components.size();

  // Delete components that have same id as target component.
  this->m_components.erase(std::remove_if(this->m_components.begin(), this->m_components.end(),
                                          [&](const std::shared_ptr<Component> &c) {
                                            return c && c->getId() == component->getId();
                                          }),
                           this->m_components.end());

  return this->m_components.size() < originalSize;
}

const std::vector<std::shared_ptr<Component>> &Bus::getComponents() const {
  return this->m_components;
}

bool Bus::isConnectedToComponent(std::shared_ptr<Component> component) const {
  return std::any_of(
      this->m_components.begin(), this->m_components.end(),
      [&](const std::shared_ptr<Component> &c) { return c && c->getId() == component->getId(); });
}
} // namespace ocira::core
