#ifndef OCIRA_CORE_DC_CURRENT_SOURCE_HPP
#define OCIRA_CORE_DC_CURRENT_SOURCE_HPP

#include "component.hpp"
#include <cstdint>

namespace ocira::core {
class DCCurrentSource : public Component {
public:
  /// @brief Constructor.
  /// @param id DC current source id.
  /// @param amps DC current source amps.
  explicit DCCurrentSource(uint32_t id, float amps);

  /// @brief Destructor.
  ~DCCurrentSource();

  /// @brief Get dc current source amps.
  /// @return Current level (amps).
  float getAmps() const;

  /// @brief Set current level.
  /// @param amps Current level (amps).
  void setAmps(float amps);

private:
  float m_amps;
};
} // namespace ocira::core

#endif