#ifndef OCIRA_CORE_WIRE_HPP
#define OCIRA_CORE_WIRE_HPP

#include "component.hpp"
#include <cstdint>

namespace ocira::core {
class Wire : public Component {
public:
  explicit Wire(uint32_t id);
  ~Wire();

private:
};
} // namespace ocira::core

#endif