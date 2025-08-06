#include "resistor.hpp"

namespace ocira::core {
Resistor::Resistor(uint32_t id, uint32_t resistance) : Component(id) {
  this->type = ComponentType::RESISTOR;
  this->resistance = resistance;
}

Resistor::~Resistor(){};

uint32_t Resistor::getResistance() const { return this->resistance; }

void Resistor::setResistance(uint32_t resistance) { this->resistance = resistance; }

} // namespace ocira::core