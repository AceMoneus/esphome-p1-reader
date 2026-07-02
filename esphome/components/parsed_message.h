#pragma once

#include <vector>
#include <string>
#include <optional>

class ParsedMessage {
 public:
  bool parse(const std::vector<uint8_t> &data, bool hdlc);

  std::optional<float> energy_import;
  std::optional<float> power_import;

  std::optional<float> voltage_l1;
  std::optional<float> voltage_l2;
  std::optional<float> voltage_l3;

  std::optional<float> current_l1;
  std::optional<float> current_l2;
  std::optional<float> current_l3;

  std::optional<float> power_l1;
  std::optional<float> power_l2;
  std::optional<float> power_l3;

 protected:
  bool parse_hdlc_(const std::vector<uint8_t> &data);
  bool parse_plain_(const std::vector<uint8_t> &data);
  void extract_fields_(const std::string &msg);
  std::optional<float> extract_float_(const std::string &msg, const std::string &key);

  std::vector<uint8_t> buffer_;
};
