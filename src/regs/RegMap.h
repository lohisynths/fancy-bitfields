#ifndef __REGMAP_H__
#define __REGMAP_H__

/*  START Register: START Register Description */
#define ADDR_REG_START      0x00000b00

const RegNameAddr REGISTER_NAMES[] = {
  /* Address of Register Start. */
  { "ADDR_REG_START", ADDR_REG_START },
};

const int num_registers = sizeof(REGISTER_NAMES) / sizeof(RegNameAddr);

#endif  // __REGMAP_H__
