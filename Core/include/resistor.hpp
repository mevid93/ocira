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
  explicit Resistor(uint32_t id, uint32_t resistance);

  /// @brief Destructor.
  ~Resistor();

  /// @brief Get resistor resistance.
  /// @return Resistance.
  uint32_t getResistance() const;

  /// @brief Set resistor resistance.
  /// @param resistance Resistance.
  void setResistance(uint32_t resistance);

private:
  uint32_t resistance;
};
} // namespace ocira::core

#endif