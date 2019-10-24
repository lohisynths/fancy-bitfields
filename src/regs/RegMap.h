#ifndef __REGMAP_H__
#define __REGMAP_H__

#include "../utils.h"

/*  START Register: START Register Description */
#define REG_START_ADDR 0x00000b00

const char REG_START_NAME[] = "START";

const RegisterNames REGISTER_NAMES[] = {
  /* Address of Register Start. */
  { REG_START_NAME, REG_START_ADDR, "Start register description." }
};

const int num_registers = sizeof(REGISTER_NAMES) / sizeof(RegisterNames);

const char* get_register_name(const uint32_t address);
const char* get_register_description(const uint32_t address);


#endif  // __REGMAP_H__
