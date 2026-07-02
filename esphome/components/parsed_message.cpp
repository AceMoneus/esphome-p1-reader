#include "parsed_message.h"
#include <regex>

bool ParsedMessage::parse(const std::vector<uint8_t> &data, bool hdlc) {
  if (hdlc)
    return this->parse_hdlc_(data);
  return this->parse_plain_(data);
}

bool ParsedMessage::parse_hdlc_(const std::vector<uint8_t> &data) {
  if (data.size() < 2 || data.front() != 0x7E || data.back() != 0x7E)
    return false;

  std::string msg(data.begin() + 1, data.end() - 1);
  this->extract_fields_(msg);
  return true;
}

bool ParsedMessage::parse_plain_(const std::vector<uint8_t> &data) {
  std::string msg(data.begin(), data.end());
  this->extract_fields_(msg);
  return true;
}

void ParsedMessage::extract_fields_(const std::string &msg) {
  this->energy_import = extract_float_(msg, "1.8.0");
  this->power_import = extract_float_(msg, "1.7.0");

  this->voltage_l1 = extract_float_(msg, "32.7.0");
  this->voltage_l2 = extract_float_(msg, "52.7.0");
  this->voltage_l3 = extract_float_(msg, "72.7.0");

  this->current_l1 = extract_float_(msg, "31.7.0");
  this->current_l2 = extract_float_(msg, "51.7.0");
  this->current_l3 = extract_float_(msg, "71.7.0");

  this->power_l1 = extract_float_(msg, "21.7.0");
  this->power_l2 = extract_float_(msg, "41.7.0");
  this->power_l3 = extract_float_(msg, "61.7.0");
}

std::optional<float> ParsedMessage::extract_float_(const std::string &msg, const std::string &key) {
  std::regex rgx(key + R"(\(([-+]?[0-9]*\.?[0-9]+)\))");
  std::smatch match;

  if (std::regex_search(msg, match, rgx)) {
    try {
      return std::stof(match[1].str());
    } catch (...) {
      return std::nullopt;
    }
  }

  return std::nullopt;
}
