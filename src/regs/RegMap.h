#ifndef __REGMAP_H__
#define __REGMAP_H__

#include "../utils.h"

/*  START Register: START Register Description */
#define ADDR_REG_START      0x00000b00

const RegNameAddr REGISTER_NAMES[] = {
  /* Address of Register Start. */
  { "ADDR_REG_START", ADDR_REG_START, "Start register description." }
};

const int num_registers = sizeof(REGISTER_NAMES) / sizeof(RegNameAddr);

const char* get_register_name(const uint32_t address);
const char* get_register_description(const uint32_t address);


#endif  // __REGMAP_H__
