#ifndef OCIRA_CORE_RESISTOR_HPP
#define OCIRA_CORE_RESISTOR_HPP

#include "component.hpp"
#include <cstdint>

namespace ocira::core {
class Resistor : public Component {
public:
  /// @brief Constructor.
  /// @param id Component id.
  /// @param resistance Resistor resistance value (Ohm);
  explicit Resistor(ComponentId id, float resistance);

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