#include "START.h"
#include "../utils.h"

void debug_print(const REG_START &input) {
  printf("Debug print register 'REG_START':\n");
  print_bit_value("  FUNC_A", input.BIT_FUNC_A);
  print_bit_value("  FUNC_B", input.BIT_FUNC_B);
  print_bit_value("  FUNC_C", input.BIT_FUNC_C);
  print_bit_value("  FUNC_D", input.BIT_FUNC_D);
  print_bit_value("  FUNC_E", input.BIT_FUNC_E);
}
