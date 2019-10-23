#include "START.h"

void REG_START::debug_print() {
  printf("Debug print register 'REG_START':\n");
  print_bit_value("  FUNC_A", this->BIT_FUNC_A);
  print_bit_value("  FUNC_B", this->BIT_FUNC_B);
  print_bit_value("  FUNC_C", this->BIT_FUNC_C);
  print_bit_value("  FUNC_D", this->BIT_FUNC_D);
  print_bit_value("  FUNC_E", this->BIT_FUNC_E);
}
