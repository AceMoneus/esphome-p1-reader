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

    if (c == '\n') {
      ParsedMessage msg;
      if (msg.parse(buffer_, this->protocol_ == "hdlc")) {
        ESP_LOGD(TAG, "Parsed P1 message");
      }
      buffer_.clear();
    }
  }
}

}  // namespace p1_reader
}  // namespace esphome
