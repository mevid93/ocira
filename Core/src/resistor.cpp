#include "resistor.hpp"

namespace ocira::core {
Resistor::Resistor(ComponentId id, float resistance) : Component(id) {
  this->m_type = ComponentType::RESISTOR;
  this->m_resistance = resistance;
}

Resistor::~Resistor(){};

float Resistor::getResistance() const { return this->m_resistance; }

void Resistor::setResistance(float resistance) { this->m_resistance = resistance; }

} // namespace ocira::core