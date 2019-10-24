#include "regs/START.h"
#include "regs/RegMap.h"

static Register<REG_START, REG_START_NAME, REG_START_ADDR> START_REG;

int main() {
  {
    // get address, register name and description
    uint32_t addr  = START_REG.get_address();
    printf("%s, addr: 0x%x\n", get_register_name(addr), addr);
    printf("%s, desc: \"%s\"\n", get_register_name(addr), get_register_description(addr));
  }

  { // assign hex value to register, and check if value changed
    START_REG = 0x03;

    printf("%s changed by assignment to 0x03\n", START_REG.get_name());
    if (START_REG == 0x03) {
      printf("%s == 0x03\n", START_REG.get_name());
    }
    printf("changed: %d\n", START_REG.changed());
  }

  { // assign value to bit-field, and check if value changed
    START_REG.reg.BIT_FUNC_E = 1;
    printf("START_REG.reg.BIT_FUNC_E value changed to 1 \n");
    printf("changed: %d\n", START_REG.changed());
  }

  { // make no changes, and check if value changed
    printf("make no changes\n");
    printf("changed: %d\n", START_REG.changed());
  }

  { // print value
    START_REG.print();
    START_REG.binary_print();
    START_REG.reg.debug_print();
  }
}
