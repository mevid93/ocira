#ifndef OCIRA_CORE_NODE_HPP
#define OCIRA_CORE_NODE_HPP

#include "component.hpp"
#include <vector>

namespace ocira::core {
/// @brief Node class. These are juntions in a circuit graph.
class Node {
public:
  /// @brief Constructor.
  /// @param id Node id.
  explicit Node(uint32_t id);

  /// @brief Destructor.
  ~Node();

  /// @brief Returns Node id.
  /// @return Node id.
  uint32_t getId() const;

  /// @brief Connect a new component to node.
  /// @param component component to connect.
  /// @return True if component was connected. False otherwise.
  bool connectComponent(std::shared_ptr<Component> component);

  /// @brief Disconnet a component from node.
  /// @param component component to diconnect.
  /// @return True if component was disconnected. False otherwise.
  bool disconnectComponent(std::shared_ptr<Component> component);

  /// @brief Get all components.
  /// @return Const reference to component vector.
  const std::vector<std::shared_ptr<Component>> &getComponents() const;

  /// @brief Check if node is connected to component.
  /// @param component Component to check.
  /// @return True if node is connected to component. False otherwise.
  bool isConnectedToComponent(std::shared_ptr<Component> component) const;

private:
  uint32_t id;
  std::vector<std::shared_ptr<Component>> components;
};
} // namespace ocira::core

#endif
