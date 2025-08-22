#ifndef OCIRA_CORE_CIRCUIT_ENUMS_HPP
#define OCIRA_CORE_CIRCUIT_ENUMS_HPP

namespace ocira::core {
/// @brief Supported circuit component types.
enum class ComponentType {
  AC_CURRENT_SOURCE,
  AC_VOLTAGE_SOURCE,
  CAPACITOR,
  DC_CURRENT_SOURCE,
  DC_VOLTAGE_SOURCE,
  GROUND,
  IMPEDANCE,
  INDUCTOR,
  RESISTOR,
  UNDEFINED,
  WIRE,
};

/// @brief Different type of component terminals.
enum class TerminalRole { POSITIVE, NEGATIVE };

/// @brief Different type of simulation modes.
enum class SimulationMode { DC, AC };

} // namespace ocira::core

#endif