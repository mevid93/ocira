#include "resistor.hpp"

namespace ocira::core {
Resistor::Resistor(uint32_t id, uint32_t resistance) : Component(id) {
  this->m_type = ComponentType::RESISTOR;
  this->m_resistance = resistance;
}

Resistor::~Resistor(){};

uint32_t Resistor::getResistance() const { return this->m_resistance; }

void Resistor::setResistance(uint32_t resistance) { this->m_resistance = resistance; }

} // namespace ocira::core