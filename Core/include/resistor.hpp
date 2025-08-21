#ifndef OCIRA_CORE_RESISTOR_HPP
#define OCIRA_CORE_RESISTOR_HPP

#include "component.hpp"
#include <cstdint>

namespace ocira::core {
class Resistor : public Component {
public:
  /// @brief Constructor.
  /// @param id Resistor id.
  /// @param resistance Resistor resistance value (Ohm);
  explicit Resistor(uint32_t id, float resistance);

  /// @brief Destructor.
  ~Resistor();

  /// @brief Get resistor resistance.
  /// @return Resistance.
  float getResistance() const;

  /// @brief Set resistor resistance.
  /// @param resistance Resistance.
  void setResistance(float resistance);

private:
  float m_resistance;
};
} // namespace ocira::core

#endif