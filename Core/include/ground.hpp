#ifndef OCIRA_CORE_GROUND_HPP
#define OCIRA_CORE_GROUND_HPP

#include "component.hpp"
#include <cstdint>

namespace ocira::core {
class Ground : public Component {
public:
  /// @brief Constructor.
  /// @param id Component id.
  explicit Ground(ComponentId id);

  /// @brief Destructor.
  ~Ground();

private:
};
} // namespace ocira::core

#endif