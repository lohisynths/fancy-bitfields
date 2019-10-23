#ifndef __REGMAP_H__
#define __REGMAP_H__

#include "../utils.h"

/*  START Register: START Register Description */
#define ADDR_REG_START      0x00000b00

const RegNameAddr REGISTER_NAMES[] = {
  /* Address of Register Start. */
  { "ADDR_REG_START", ADDR_REG_START }
};

const int num_registers = sizeof(REGISTER_NAMES) / sizeof(RegNameAddr);

inline const char* get_register_name(const uint32_t address) {
  for (int i = 0; i < num_registers; i++) {
    if (REGISTER_NAMES[i].key == address) {
      return REGISTER_NAMES[i].value;
    }
  }
  return "Register name not found";
}

#endif  // __REGMAP_H__
