#ifndef __REGS_CONFIG0_H__
#define __REGS_CONFIG0_H__

#include "../utils.h"
#include "../Register.h"

#define REG_START_TYPEDEF uint8_t

// const char *name = "START";
// error: ‘name’ is not a valid template argument because ‘name’ is a variable, not the address of a variable
// find way for passing name as string literal instead of const char name[]
const char REG_START_NAME[] = "START";

/** \brief Configuration Register 0. */
struct REG_START {
  /** \brief Bit 1:0. Function A. */
  /** 00 00 Function A 1. <br>
   *  01 01 Function A 2. <br>
   *  10 10 Function A 3. <br>
   *  11 11 Function A 4. <br>
   */
  REG_START_TYPEDEF BIT_FUNC_A :2;
  /** \brief Bit 2. RESERVED*/
  REG_START_TYPEDEF :1;
  /** \brief Bit 3. Function B.
   *  Detailed description of the bit functionality.*/
  REG_START_TYPEDEF BIT_FUNC_B :1;
  /** \brief Bit 4. Function C.
   *  Detailed description of the bit functionality.*/
  REG_START_TYPEDEF BIT_FUNC_C :1;
  /** \brief Bit 5. Function D.
   *  Detailed description of the bit functionality.*/
  REG_START_TYPEDEF BIT_FUNC_D :1;
  /** \brief Bit 6. Function E.
   *  Detailed description of the bit functionality.
   */
  /**  0 Some Function E enabled.<br>
   *   1 Some Function E disabled
   */
  REG_START_TYPEDEF BIT_FUNC_E :1;
  /**
   *  \brief Bit 7. RESERVED
   */
  REG_START_TYPEDEF :1;

  void debug_print();

} PACKED_REGISTER;

static_assert(sizeof(REG_START) == sizeof(REG_START_TYPEDEF),
    "Size of REG_START is not correct size");

void debug_print(const REG_START &input);

#endif  // __REGS_CONFIG0_H__
