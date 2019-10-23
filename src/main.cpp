#include "regs/RegMap.h"
#include "regs/START.h"
#include "RegChecker.h"

// const char *name = "elko";
// error: ‘name’ is not a valid template argument because ‘name’ is a variable, not the address of a variable
const char name[] = "START";


int main() {
  // find way for passing name as string literal instead of const char name[]
  RegisterChecker<REG_START, name, ADDR_REG_START> config0;

//  config0.changed();
  printf("changed: %d\n", config0.changed());

  config0 = 0x03;
  printf("changed: %d\n", config0.changed());


  if(config0 == 0x03) {
    printf("config0 == 0x03\n");
  }


  printf("changed: %d\n", config0.changed());


  config0.reg.BIT_FUNC_E = 1;
  printf("changed: %d\n", config0.changed());

//  config0.changed();

  uint8_t val = config0;

  printf("Register name : %s, value %d\n", config0.get_name(), val);

  BinaryPrint(val);

  debug_print(config0.reg);

}
