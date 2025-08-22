#include "component.hpp"
#include "bus.hpp"
#include <algorithm>

namespace ocira::core {
Component::Component(ComponentId id) : m_id(id) { this->m_type = ComponentType::UNDEFINED; }

Component::~Component() {}

ComponentId Component::getId() const { return this->m_id; }

ComponentType Component::getComponentType() const { return this->m_type; }

bool Component::addConnection(std::weak_ptr<Bus> bus, TerminalRole role) {
  bool isConnected = this->isConnectedToBus(bus);
  if (isConnected)
    return false;

  // By default each component can only have two connections.
  // Override addConnection in inherited classes if this is not the case.
  if (this->m_connections.size() == 2) {
    return false;
  }

  Connection connection{bus, role};
  this->m_connections.push_back(connection);
  return true;
}

bool Component::removeConnection(std::weak_ptr<Bus> bus) {
  auto target = bus.lock();
  if (!target)
    return false;

  for (int i = 0; i < this->m_connections.size(); i++) {
    auto connection = this->m_connections[i];
    auto n = connection.m_bus.lock();
    if (n && target->getId() == n->getId()) {
      this->m_connections.erase(this->m_connections.begin() + i);
      return true;
    }
  }

  return false;
}

bool Component::isConnectedToBus(std::weak_ptr<Bus> bus) const {
  auto target = bus.lock();
  if (!target)
    return false;

  for (int i = 0; i < this->m_connections.size(); i++) {
    auto connection = this->m_connections[i];
    auto n = connection.m_bus.lock();
    if (n && target->getId() == n->getId()) {
      return true;
    }
  }

  return false;
}
} // namespace ocira::core