#pragma once

#include "esphome/core/component.h"
#include "esphome/components/uart/uart.h"
#include "parsed_message.h"

namespace esphome {
namespace p1_reader {

class P1Reader : public Component, public uart::UARTDevice {
 public:
  void set_uart(uart::UARTComponent *uart) { this->uart_ = uart; }
  void set_protocol(const std::string &protocol) { this->protocol_ = protocol; }

  void loop() override;

 protected:
  uart::UARTComponent *uart_;
  std::string protocol_;
};

}  // namespace p1_reader
}  // namespace esphome
