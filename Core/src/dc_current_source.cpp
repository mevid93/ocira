#include "dc_current_source.hpp"

namespace ocira::core {
DCCurrentSource::DCCurrentSource(uint32_t id, float amps) : Component(id) {
  this->m_amps = amps;
  this->m_type = ComponentType::DC_CURRENT_SOURCE;
}

DCCurrentSource::~DCCurrentSource() {}

float DCCurrentSource::getAmps() const { return this->m_amps; }

void DCCurrentSource::setAmps(float amps) { this->m_amps = amps; }
} // namespace ocira::core