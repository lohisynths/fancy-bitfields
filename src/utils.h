#ifndef __UTILS_H__
#define __UTILS_H__

#include <string>
#include <bitset>

/** TODO: Unit tests + license
 *  original source:
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

struct RegNameAddr {
  const char *value;
  uint32_t key;
};

template<typename T>
void BinaryPrint(T input) {
  std::string data;
  if (sizeof(T) == 1) {
    uint16_t value = *((uint8_t*) &input);
    data = std::bitset<sizeof(T) * 8>(value).to_string();
  } else  if (sizeof(T) == 2) {
    uint16_t value = *((uint16_t*) &input);
    data = std::bitset<sizeof(T) * 8>(value).to_string();
  } else if (sizeof(T) == 4) {
    uint32_t value = *((uint32_t*) &input);
    data = std::bitset<sizeof(T) * 8>(value).to_string();
  } else {
    data = "error";
  }
  printf("Binary value: 0b%s\n", data.c_str());
}

void print_bit_value(const char *name, const uint8_t data);
const char* get_register_name(uint32_t address);

#endif  // __UTILS_H__
