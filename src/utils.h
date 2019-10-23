#ifndef __UTILS_H__
#define __UTILS_H__

#include <stdint.h>

#define PACKED_REGISTER  __attribute__((packed, aligned(sizeof(uint8_t))))

struct RegNameAddr {
  const char *value;
  uint32_t key;
};

void print_bit_value(const char *name, const uint8_t data);
const char* get_register_name(const uint32_t address);

#endif  // __UTILS_H__
