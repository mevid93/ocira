#include "wire.hpp"

namespace ocira::core {
Wire::Wire(ComponentId id) : Component(id) { this->m_type = ComponentType::WIRE; }

Wire::~Wire(){};
} // namespace ocira::core