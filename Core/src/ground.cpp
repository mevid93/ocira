#include "ground.hpp"

namespace ocira::core {
Ground::Ground(ComponentId id) : Component(id) { this->m_type = ComponentType::GROUND; }

Ground::~Ground() {}

bool Ground::addConnection(std::weak_ptr<Bus> bus, TerminalRole role) {
  if (this->m_connections.size() == 1) {
    return false;
  }

  Connection connection{bus, role};
  this->m_connections.push_back(connection);
  return true;
}
} // namespace ocira::core