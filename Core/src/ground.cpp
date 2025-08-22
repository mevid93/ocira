#include "ground.hpp"

namespace ocira::core {
Ground::Ground(ComponentId id) : Component(id) { this->m_type = ComponentType::GROUND; }

Ground::~Ground() {}
} // namespace ocira::core