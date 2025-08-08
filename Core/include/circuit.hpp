#ifndef OCIRA_CORE_CIRCUIT_HPP
#define OCIRA_CORE_CIRCUIT_HPP

#include "component.hpp"
#include "node.hpp"
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
  /// @brief Get circuit nodes.
  /// @return Circuit nodes.
  const std::vector<std::shared_ptr<Node>> &getNodes() const;
  /// @brief Set circuit nodes.
  /// @param nodes Circuit nodes.
  void setNodes(std::vector<std::shared_ptr<Node>> nodes);
  /// @brief Set circuit components.
  /// @param components Circuit components.
  void setComponents(std::vector<std::shared_ptr<Component>> components);

private:
  std::vector<std::shared_ptr<Node>> m_nodes;
  std::vector<std::shared_ptr<Component>> m_components;
};
} // namespace ocira::core

#endif