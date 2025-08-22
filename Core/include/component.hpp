#ifndef OCIRA_CORE_COMPONENT_HPP
#define OCIRA_CORE_COMPONENT_HPP

#include "circuit_structs.hpp"
#include <memory>
#include <vector>

namespace ocira::core {

class Bus;

/// @brief Component id. Each component should have a unique id.
using ComponentId = uint32_t;

/// @brief Base component class. Components are edges in circuit graph.
class Component {
public:
  /// @brief Constructor.
  /// @param id Component id.
  explicit Component(const ComponentId id);

  /// @brief Destructor.
  ~Component();

  /// @brief Returns component id.
  /// @return Component id.
  ComponentId getId() const;

  /// @brief Returns component type.
  /// @return Component type.
  ComponentType getComponentType() const;

  /// @brief Add connection to component.
  /// @param connection New connection to add.
  /// @param role Terminel role of the connection.
  /// @return True if bus was connected. False otherwise.
  virtual bool addConnection(std::weak_ptr<Bus> bus, TerminalRole role);

  /// @brief Remove connection from component.
  /// @param bus Bus to disconnect.
  /// @return True if bus was disconnected. False otherwise.
  bool removeConnection(std::weak_ptr<Bus> bus);

  /// @brief Check if component is connected to bus.
  /// @param bus Bus to check.
  /// @return True if component is connected to bus. False otherwise.
  bool isConnectedToBus(std::weak_ptr<Bus> bus) const;

protected:
  ComponentType m_type;
  std::vector<Connection> m_connections;

private:
  ComponentId m_id;
};
} // namespace ocira::core

#endif