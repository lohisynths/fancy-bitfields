#ifndef __UTILS_H__
#define __UTILS_H__
#include <stdio.h>
#include <bitset>

#define PACKED_REGISTER  __attribute__((packed, aligned(sizeof(uint8_t))))

struct RegNameAddr {
  const char *value;
  uint32_t key;
};

/**
 *  Original source code:
 *  https://peter.bloomfield.online/2015/10/using-cpp-templates-for-size-based-type-selection/
 */
template <std::uint8_t T_numBytes>
using UintSelector =
    typename std::conditional<T_numBytes == 1, std::uint8_t,
        typename std::conditional<T_numBytes == 2, std::uint16_t,
            typename std::conditional<T_numBytes == 3 || T_numBytes == 4, std::uint32_t,
                std::uint64_t
            >::type
        >::type
    >::type;

void print_bit_value(const char *name, const uint8_t data);
const char* get_register_name(const uint32_t address);

#endif  // __UTILS_H__
