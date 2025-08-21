#ifndef OCIRA_CORE_CIRCUIT_HPP
#define OCIRA_CORE_CIRCUIT_HPP

#include "bus.hpp"
#include "component.hpp"
#include <memory>
#include <vector>

namespace ocira::core {
/// @brief Circuit class.
class Circuit {
public:
  /// @brief Constructor.
  explicit Circuit();
  /// @brief Destructor.
  ~Circuit();
  /// @brief Get circuit components.
  /// @return Circuit components.
  const std::vector<std::shared_ptr<Component>> &getComponents() const;
  /// @brief Get circuit buses.
  /// @return Circuit buses.
  const std::vector<std::shared_ptr<Bus>> &getBuses() const;
  /// @brief Set circuit buses.
  /// @param buses Circuit buses.
  void setBuses(std::vector<std::shared_ptr<Bus>> buses);
  /// @brief Set circuit components.
  /// @param components Circuit components.
  void setComponents(std::vector<std::shared_ptr<Component>> components);

private:
  std::vector<std::shared_ptr<Bus>> m_buses;
  std::vector<std::shared_ptr<Component>> m_components;
};
} // namespace ocira::core

#endif