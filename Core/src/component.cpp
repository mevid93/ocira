#include "component.hpp"
#include "bus.hpp"
#include <algorithm>

namespace ocira::core {
Component::Component(ComponentId id) : m_id(id) {
  // For base class we use component type UNDEFINED.
  this->m_type = ComponentType::UNDEFINED;
}

Component::~Component() {}

ComponentId Component::getId() const { return this->m_id; }

ComponentType Component::getComponentType() const { return this->m_type; }

bool Component::connectFirstBus(std::weak_ptr<Bus> bus) {
  // Check if bus is already connected.
  bool isConnected = this->isConnectedToBus(bus);
  if (isConnected)
    return false;
  // Connect the bus.
  this->m_bus1 = bus;
  return true;
}

bool Component::connectSecondBus(std::weak_ptr<Bus> bus) {
  // Check if bus is already connected.
  bool isConnected = this->isConnectedToBus(bus);
  if (isConnected)
    return false;
  // Connect the bus.
  this->m_bus2 = bus;
  return true;
}

bool Component::disconnectBus(std::weak_ptr<Bus> bus) {
  auto target = bus.lock();
  if (!target)
    return false;

  auto n1 = m_bus1.lock();
  if (n1 && target->getId() == n1->getId()) {
    this->m_bus1.reset();
    return true;
  }

  auto n2 = m_bus2.lock();
  if (n2 && target->getId() == n2->getId()) {
    this->m_bus2.reset();
    return true;
  }
  return false;
}

bool Component::isConnectedToBus(std::weak_ptr<Bus> bus) const {
  auto target = bus.lock();
  if (!target)
    return false;

  auto n1 = m_bus1.lock();
  if (n1 && target->getId() == n1->getId())
    return true;

  auto n2 = m_bus2.lock();
  return n2 && target->getId() == n2->getId();
}
} // namespace ocira::core