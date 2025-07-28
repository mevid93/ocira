#ifndef OCIRA_CORE_NODE_HPP
#define OCIRA_CORE_NODE_HPP

#include "component.hpp"
#include <vector>

namespace ocira::core {
/// @brief Node class. Juntions in circuit graph.
class Node {
public:
  /// @brief Constructor.
  /// @param id Node id.
  Node(uint32_t id);

  /// @brief Connect a new component to node.
  /// @param component
  void connectComponent(std::shared_ptr<Component> component);

  /// @brief Disconnet a component from node.
  /// @param component
  void disconnectComponent(std::shared_ptr<Component> component);

  /// @brief Get all components.
  /// @return Const reference to component vector.
  const std::vector<std::shared_ptr<Component>> &getComponents() const;

private:
  uint32_t id;
  std::vector<std::shared_ptr<Component>> components;
};
} // namespace ocira::core

#endif
