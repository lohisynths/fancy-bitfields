#include "regs/START.h"
#include "regs/RegMap.h"

static Register<REG_START, REG_START_NAME, ADDR_REG_START> START_REG;

int main() {
  {
    uint32_t addr  = START_REG.get_address();
    printf("name %s, address 0x%x\n", get_register_name(addr), addr);
  }

  {
    START_REG = 0x03;
    printf("START_REG value changed by assignment to 0x03\n");
    if (START_REG == 0x03) {
      printf("START_REG == 0x03\n");
    }
    printf("changed: %d\n", START_REG.changed());
  }

  {
    START_REG.reg.BIT_FUNC_E = 1;
    printf("START_REG.reg.BIT_FUNC_E value changed to 1 \n");
    printf("changed: %d\n", START_REG.changed());
  }

  {
    printf("make no changes\n");
    printf("changed: %d\n", START_REG.changed());
  }

  {
    uint8_t val = START_REG;
    printf("Register name : %s, value %d\n", START_REG.get_name(), val);
    START_REG.print();
    START_REG.binary_print();
    START_REG.reg.debug_print();
  }
}
