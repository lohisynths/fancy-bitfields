#ifndef __UTILS_H__
#define __UTILS_H__

#include <stdint.h>

#define PACKED_DATA __attribute__((packed, aligned(sizeof(uint8_t))))

struct RegisterNames {
  const char *name;
  uint32_t key;
  const char *description;
};

struct BitFieldNames {
  const uint32_t offset;
  const uint32_t width;
  const char *name;
  const char *brief_description;
  const char *description;
} PACKED_DATA;

void print_bit_value(const char *name, const uint8_t data);

#endif  // __UTILS_H__
