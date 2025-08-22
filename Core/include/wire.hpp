#ifndef OCIRA_CORE_WIRE_HPP
#define OCIRA_CORE_WIRE_HPP

#include "component.hpp"
#include <cstdint>

namespace ocira::core {
class Wire : public Component {
public:
  /// @brief Constructor for Wire class.
  /// @param id Component id.
  explicit Wire(ComponentId id);

  /// @brief Destructor.
  ~Wire();

private:
};
} // namespace ocira::core

#endif