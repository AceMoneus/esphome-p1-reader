#include "p1_reader.h"
#include "esphome/core/log.h"

namespace esphome {
namespace p1_reader {

static const char *TAG = "p1_reader";

void P1Reader::loop() {
  while (this->available()) {
    uint8_t c;
    this->read_byte(&c);

    buffer_.push_back(c);

    // End of message (P1 telegrams end with newline)
    if (c == '\n') {
      ParsedMessage msg;

      bool is_hdlc = (this->protocol_ == "hdlc");
      if (msg.parse(buffer_, is_hdlc)) {
        ESP_LOGD(TAG, "Parsed P1 message");

        // Publish sensors if values exist
        if (energy_import_sensor_ && msg.energy_import.has_value())
          energy_import_sensor_->publish_state(*msg.energy_import);

        if (power_import_sensor_ && msg.power_import.has_value())
          power_import_sensor_->publish_state(*msg.power_import);

        if (voltage_l1_sensor_ && msg.voltage_l1.has_value())
          voltage_l1_sensor_->publish_state(*msg.voltage_l1);

        if (voltage_l2_sensor_ && msg.voltage_l2.has_value())
          voltage_l2_sensor_->publish_state(*msg.voltage_l2);

        if (voltage_l3_sensor_ && msg.voltage_l3.has_value())
          voltage_l3_sensor_->publish_state(*msg.voltage_l3);

        if (current_l1_sensor_ && msg.current_l1.has_value())
          current_l1_sensor_->publish_state(*msg.current_l1);

        if (current_l2_sensor_ && msg.current_l2.has_value())
          current_l2_sensor_->publish_state(*msg.current_l2);

        if (current_l3_sensor_ && msg.current_l3.has_value())
          current_l3_sensor_->publish_state(*msg.current_l3);

        if (power_l1_sensor_ && msg.power_l1.has_value())
          power_l1_sensor_->publish_state(*msg.power_l1);

        if (power_l2_sensor_ && msg.power_l2.has_value())
          power_l2_sensor_->publish_state(*msg.power_l2);

        if (power_l3_sensor_ && msg.power_l3.has_value())
          power_l3_sensor_->publish_state(*msg.power_l3);
      }

      // Clear buffer for next telegram
      buffer_.clear();
    }
  }
}

}  // namespace p1_reader
}  // namespace esphome
