#ifndef OCIRA_CORE_CIRCUIT_STRUCTS_HPP
#define OCIRA_CORE_CIRCUIT_STRUCTS_HPP

#include "circuit_enums.hpp"
#include <memory>

namespace ocira::core {

class Bus;

/// @brief Connection type. Each component can have connections to buses.
struct Connection {
  std::weak_ptr<Bus> m_bus;
  TerminalRole m_role;
};

} // namespace ocira::core

#endif