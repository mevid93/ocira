#ifndef OCIRA_CORE_BUS_HPP
#define OCIRA_CORE_BUS_HPP

#include "component.hpp"
#include <vector>

namespace ocira::core {
/// @brief Bus class. These are the junctions in a circuit graph.
class Bus {
public:
  /// @brief Constructor.
  /// @param id Bus id.
  explicit Bus(uint32_t id);

  /// @brief Destructor.
  ~Bus();

  /// @brief Returns bus id.
  /// @return Bus id.
  uint32_t getId() const;

  /// @brief Connect a new component to the bus.
  /// @param component Component to connect.
  /// @return True if component was connected. False otherwise.
  bool connectComponent(std::shared_ptr<Component> component);

  /// @brief Disconnet a component from the bus.
  /// @param component Component to diconnect.
  /// @return True if component was disconnected. False otherwise.
  bool disconnectComponent(std::shared_ptr<Component> component);

  /// @brief Get all components.
  /// @return Components.
  const std::vector<std::shared_ptr<Component>> &getComponents() const;

  /// @brief Check if bus is connected to given component.
  /// @param component Component to check connection with.
  /// @return True if bus is connected to the component. False otherwise.
  bool isConnectedToComponent(std::shared_ptr<Component> component) const;

private:
  uint32_t m_id;
  std::vector<std::shared_ptr<Component>> m_components;
};
} // namespace ocira::core

#endif
