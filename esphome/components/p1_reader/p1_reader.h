#pragma once

#include "esphome/core/component.h"
#include "esphome/components/uart/uart.h"
#include "esphome/components/sensor/sensor.h"
#include "parsed_message.h"

namespace esphome {
namespace p1_reader {

class P1Reader : public Component, public uart::UARTDevice {
 public:
  void set_uart(uart::UARTComponent *uart) { this->uart_ = uart; }
  void set_protocol(const std::string &protocol) { this->protocol_ = protocol; }

  // Sensor setters
  void set_energy_import_sensor(sensor::Sensor *s) { energy_import_sensor_ = s; }
  void set_power_import_sensor(sensor::Sensor *s) { power_import_sensor_ = s; }

  void set_voltage_l1_sensor(sensor::Sensor *s) { voltage_l1_sensor_ = s; }
  void set_voltage_l2_sensor(sensor::Sensor *s) { voltage_l2_sensor_ = s; }
  void set_voltage_l3_sensor(sensor::Sensor *s) { voltage_l3_sensor_ = s; }

  void set_current_l1_sensor(sensor::Sensor *s) { current_l1_sensor_ = s; }
  void set_current_l2_sensor(sensor::Sensor *s) { current_l2_sensor_ = s; }
  void set_current_l3_sensor(sensor::Sensor *s) { current_l3_sensor_ = s; }

  void set_power_l1_sensor(sensor::Sensor *s) { power_l1_sensor_ = s; }
  void set_power_l2_sensor(sensor::Sensor *s) { power_l2_sensor_ = s; }
  void set_power_l3_sensor(sensor::Sensor *s) { power_l3_sensor_ = s; }

  void loop() override;

 protected:
  uart::UARTComponent *uart_;
  std::string protocol_;

  std::vector<uint8_t> buffer_;

  // Sensor pointers
  sensor::Sensor *energy_import_sensor_{nullptr};
  sensor::Sensor *power_import_sensor_{nullptr};

  sensor::Sensor *voltage_l1_sensor_{nullptr};
  sensor::Sensor *voltage_l2_sensor_{nullptr};
  sensor::Sensor *voltage_l3_sensor_{nullptr};

  sensor::Sensor *current_l1_sensor_{nullptr};
  sensor::Sensor *current_l2_sensor_{nullptr};
  sensor::Sensor *current_l3_sensor_{nullptr};

  sensor::Sensor *power_l1_sensor_{nullptr};
  sensor::Sensor *power_l2_sensor_{nullptr};
  sensor::Sensor *power_l3_sensor_{nullptr};
};

}  // namespace p1_reader
}  // namespace esphome
