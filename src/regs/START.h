#ifndef __REGS_CONFIG0_H__
#define __REGS_CONFIG0_H__

#include "../utils.h"
#include "../Register.h"

typedef uint8_t reg_start_t;

const BitFieldNames REG_START_BITFIELD_NAMES[] = {
  {
    .offset = 0,
    .width = 2,
    .name = "BIT_FUNC_A",
    .brief_description = "Bit 1:0. Function A.",
    .description = "00 00 Function A 1.<br>01 01 Function A 2.<br>10 10 Function A 3.<br>11 11 Function A 4.<br>"
  },
  {
    .offset = 2,
    .width = 1,
    .name = "",
    .brief_description = "Bit 2. RESERVED.",
    .description = ""
  },
  {
    .offset = 3,
    .width = 1,
    .name = "BIT_FUNC_B",
    .brief_description = "Bit 3. Function B.",
    .description = "Detailed description of the bit functionality."
  },
  {
    .offset = 4,
    .width = 1,
    .name = "BIT_FUNC_C",
    .brief_description = "Bit 4. Function C.",
    .description = "Detailed description of the bit functionality."
  },
  {
    .offset = 5,
    .width = 1,
    .name = "BIT_FUNC_D",
    .brief_description = "Bit 5. Function D.",
    .description = "Detailed description of the bit functionality."
  },
  {
    .offset = 6,
    .width = 1,
    .name = "BIT_FUNC_E",
    .brief_description = "Bit 6. Function E.",
    .description = "0 Some Function E enabled.<br>1 Some Function E disabled."
  },
  {
    .offset = 7,
    .width = 1,
    .name = "",
    .brief_description = "Bit 7. RESERVED.",
    .description = ""
  }
};

const int START_bitfields_count = sizeof(REG_START_BITFIELD_NAMES) / sizeof(BitFieldNames);

/** \brief Configuration Register 0.*/
struct REG_START {
  /** \brief Bit 1:0. Function A.*/
  /** 00 00 Function A 1.<br>
    * 01 01 Function A 2.<br>
    * 10 10 Function A 3.<br>
    * 11 11 Function A 4.*/
  reg_start_t BIT_FUNC_A :2;
  /** \brief Bit 2. RESERVED*/
  reg_start_t :1;
  /** \brief Bit 3. Function B.*/
  /** Detailed description of the bit functionality.*/
  reg_start_t BIT_FUNC_B :1;
  /** \brief Bit 4. Function C.*/
  /** Detailed description of the bit functionality.*/
  reg_start_t BIT_FUNC_C :1;
  /** \brief Bit 5. Function D.*/
  /** Detailed description of the bit functionality.*/
  reg_start_t BIT_FUNC_D :1;
  /** \brief Bit 6. Function E.*/
  /** 0 Some Function E enabled.<br>
    * 1 Some Function E disabled.*/
  reg_start_t BIT_FUNC_E :1;
  /** \brief Bit 7. RESERVED*/
  reg_start_t :1;

  void debug_print();
  bool compare(const REG_START &input);
  const char* get_bitfield_description(const uint32_t offset);

} PACKED_DATA;

static_assert(sizeof(REG_START) == sizeof(reg_start_t),
    "Size of REG_START is not correct size");

void debug_print(const REG_START &input);

#endif  // __REGS_CONFIG0_H__
