#include "RegMap.h"

const char* get_register_name(const uint32_t address) {
  for (int i = 0; i < num_registers; i++) {
    if (REGISTER_NAMES[i].key == address) {
      return REGISTER_NAMES[i].value;
    }
  }
  return "Register name not found";
}

const char* get_register_description(const uint32_t address) {
  for (int i = 0; i < num_registers; i++) {
    if (REGISTER_NAMES[i].key == address) {
      return REGISTER_NAMES[i].description;
    }
  }
  return "Register name not found";
}

