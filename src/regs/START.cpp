#include "START.h"
#include "RegMap.h"

void REG_START::debug_print() {
  printf("Debug print register 'REG_START':\n");
  print_bit_value("  FUNC_A", this->BIT_FUNC_A);
  print_bit_value("  FUNC_B", this->BIT_FUNC_B);
  print_bit_value("  FUNC_C", this->BIT_FUNC_C);
  print_bit_value("  FUNC_D", this->BIT_FUNC_D);
  print_bit_value("  FUNC_E", this->BIT_FUNC_E);
}

bool REG_START::compare(const REG_START &input) {
  if(input.BIT_FUNC_A != this->BIT_FUNC_A) {
    printf("BIT_FUNC_A changed, %d != %d\n", input.BIT_FUNC_A, this->BIT_FUNC_A);
  }
  if(input.BIT_FUNC_B != this->BIT_FUNC_B) {
    printf("BIT_FUNC_B changed, %d != %d\n", input.BIT_FUNC_B, this->BIT_FUNC_B);
  }
  if(input.BIT_FUNC_C != this->BIT_FUNC_C) {
    printf("BIT_FUNC_C changed, %d != %d\n", input.BIT_FUNC_C, this->BIT_FUNC_C);
  }
  if(input.BIT_FUNC_E != this->BIT_FUNC_E) {
    printf("BIT_FUNC_E changed, %d != %d\n", input.BIT_FUNC_E, this->BIT_FUNC_E);
  }
  return true;
}

const char* REG_START::get_bitfield_description(const uint32_t offset) {
  for(int i=0; i < START_bitfields_count; i++) {
    if(offset == REG_START_BITFIELD_NAMES[i].offset) {
      printf("%s\n%s", REG_START_BITFIELD_NAMES[i].brief_description, REG_START_BITFIELD_NAMES[i].description);
    }
  }
  return "Register name not found";
}
