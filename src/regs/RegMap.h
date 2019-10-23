#ifndef __REGMAP_H__
#define __REGMAP_H__

#include "../utils.h"

/*  START Register: START Register Description */
#define ADDR_REG_START      0x00000000
/*  STOP Register: STOP Register Description */
#define ADDR_REG_STOP      0x00001000

const RegNameAddr REGISTER_NAMES[] = {
  /* Address of Register Start. */
  { "ADDR_REG_START", ADDR_REG_START },
  /* Address of Register Stop. */
  { "ADDR_REG_STOP", ADDR_REG_STOP }
};

const int num_registers = sizeof(REGISTER_NAMES) / sizeof(RegNameAddr);

#endif  // __REGMAP_H__
