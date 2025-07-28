#ifndef OCIRA_CORE_COMPONENT_HPP
#define OCIRA_CORE_COMPONENT_HPP

#include <memory>

#include "node.hpp"

namespace ocira::core {
/// @brief Supported circuit component types.
enum class ComponentType {
  AC_VOLTAGE_SOURCE,
  CAPACITOR,
  DC_VOLTAGE_SOURCE,
  IMPEDANCE,
  INDUCTOR,
  RESISTOR,
};

/// @brief Base circuit component class. Components are edges in circuit graph.
class Component {
public:
private:
  uint32_t id;
  ComponentType type;
  std::shared_ptr<Node> node1;
  std::shared_ptr<Node> node2;
};
} // namespace ocira::core

#endif