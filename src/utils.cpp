#include <stdint.h>
#include <string.h>
#include <stdio.h>

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
