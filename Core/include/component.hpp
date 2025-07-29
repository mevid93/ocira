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
  WIRE
};

/// @brief Base circuit component class. Components are edges in circuit graph.
class Component {
public:
  /// @brief Constructor.
  /// @param id Component id.
  Component(uint32_t id);

  /// @brief Connect first node to component.
  /// @param node1 node to connect.
  void connectToFirstNode(std::weak_ptr<Node> node1);

  /// @brief Connect second node to component.
  /// @param node2 node to connect.
  void connectToSecondNode(std::weak_ptr<Node> node2);

private:
  uint32_t id;
  ComponentType type;
  std::weak_ptr<Node> node1;
  std::weak_ptr<Node> node2;
};
} // namespace ocira::core

#endif