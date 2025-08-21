#ifndef OCIRA_CORE_COMPONENT_HPP
#define OCIRA_CORE_COMPONENT_HPP

#include <memory>

namespace ocira::core {

class Bus;

/// @brief Supported circuit component types.
enum class ComponentType {
  AC_CURRENT_SOURCE,
  AC_VOLTAGE_SOURCE,
  CAPACITOR,
  DC_CURRENT_SOURCE,
  DC_VOLTAGE_SOURCE,
  IMPEDANCE,
  INDUCTOR,
  RESISTOR,
  UNDEFINED,
  WIRE
};

/// @brief Base component class. Components are edges in circuit graph.
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

  /// @brief Connect first bus to the component.
  /// @param bus Bus to connect.
  /// @return True if bus was connected. False otherwise.
  bool connectFirstBus(std::weak_ptr<Bus> bus);

  /// @brief Connect second bus to component.
  /// @param bus Bus to connect.
  /// @return True if bus was connected. False otherwise.
  bool connectSecondBus(std::weak_ptr<Bus> bus);

  /// @brief Disconnect bus from component.
  /// @param bus Bus to disconnect.
  /// @return True if bus was disconnected. False otherwise.
  bool disconnectBus(std::weak_ptr<Bus> bus);

  /// @brief Check if component is connected to bus.
  /// @param bus Bus to check.
  /// @return True if component is connected to bus. False otherwise.
  bool isConnectedToBus(std::weak_ptr<Bus> bus) const;

protected:
  ComponentType m_type;

private:
  uint32_t m_id;
  std::weak_ptr<Bus> m_bus1;
  std::weak_ptr<Bus> m_bus2;
};
} // namespace ocira::core

#endif