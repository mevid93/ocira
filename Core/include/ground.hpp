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

  /// @brief
  /// @param bus Bus to connect.
  /// @param role Terminal role of the connection.
  /// @return True if connection was added. False otherwise.
  bool addConnection(std::weak_ptr<Bus> bus, TerminalRole role) override;

private:
};
} // namespace ocira::core

#endif