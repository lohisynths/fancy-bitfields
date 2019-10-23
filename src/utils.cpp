#include "utils.h"
#include "regs/RegMap.h"
#include <string.h>

void print_bit_value(const char *name, const uint8_t data) {
  const size_t len = strlen(name);
  if (len < 7) {
    printf("%s \t\t\t\t %d", name, data);
  } else if (len < 15) {
    printf("%s \t\t\t %d", name, data);
  } else {
    printf("%s \t\t %d", name, data);
  }
  printf("\n");
}

const char* get_register_name(const uint32_t address) {
  for (int i = 0; i < num_registers; i++) {
    if (REGISTER_NAMES[i].key == address) {
      return REGISTER_NAMES[i].value;
    }
  }
  return "Register name not found";
}
