#ifndef OCIRA_CORE_COMPONENT_HPP
#define OCIRA_CORE_COMPONENT_HPP

#include <memory>

namespace ocira::core {

class Node;

/// @brief Supported circuit component types.
enum class ComponentType {
  AC_VOLTAGE_SOURCE,
  CAPACITOR,
  DC_VOLTAGE_SOURCE,
  IMPEDANCE,
  INDUCTOR,
  RESISTOR,
  UNDEFINED,
  WIRE
};

/// @brief Base circuit component class. Components are edges in circuit graph.
class Component {
public:
  /// @brief Constructor.
  /// @param id Component id.
  explicit Component(uint32_t id);

  /// @brief Destructor.
  ~Component();

  /// @brief Returns component id.
  /// @return Component id.
  uint32_t getId() const;

  /// @brief Returns component type.
  /// @return Component type.
  ComponentType getComponentType() const;

  /// @brief Connect first node to component.
  /// @param node Node to connect.
  /// @return True if node was connected. False otherwise.
  bool connectFirstNode(std::weak_ptr<Node> node);

  /// @brief Connect second node to component.
  /// @param node Node to connect.
  /// @return True if node was connected. False otherwise.
  bool connectSecondNode(std::weak_ptr<Node> node);

  /// @brief Disconnect node from component.
  /// @param node Node to disconnect.
  /// @return True if node was disconnected. False otherwise.
  bool disconnectNode(std::weak_ptr<Node> node);

  /// @brief Check if component is connected to node.
  /// @param node Node to check.
  /// @return True if component is connected to Node. False otherwise.
  bool isConnectedToNode(std::weak_ptr<Node> node) const;

private:
  uint32_t id;
  ComponentType type;
  std::weak_ptr<Node> node1;
  std::weak_ptr<Node> node2;
};
} // namespace ocira::core

#endif