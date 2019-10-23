#ifndef __REGCHECKER_H_
#define __REGCHECKER_H_

#include <bitset>

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


template<typename T, const char *NAME, const uint32_t REG_ADDR>
class Register {
public:
  typedef UintSelector<sizeof(T) / 8> deduced_type;

  T reg = { };

  const inline uint32_t get_address() {
    return REG_ADDR;
  }

  const inline char* get_name() {
    return NAME;
  }

  Register& operator=(deduced_type v) {
    reg = get_value_T(v);
    return *this;
  }

  bool operator !=(deduced_type data) const {
    return data != get_value_k(data);
  }

  bool changed() {
    bool ret = false;
    if (old_value != get_value_k(reg)) {
      ret = true;
      old_value = get_value_k(reg);
    }
    return ret;
  }

  operator deduced_type() const {
    return *(deduced_type*) &reg;
  }

  operator Register() const {
    return reg;
  }

  void binary_print() {
    std::string data;
    data = std::bitset<sizeof(T) * 8>(get_value_k(reg)).to_string();
    printf("%s binary value: 0b%s\n", NAME, data.c_str());
  }

  void print() {
    uint32_t val = get_value_k(reg);
    printf("%s value: %d\n", NAME, val);
  }

private:
  deduced_type old_value = { };

  deduced_type get_value_k(T &val) {
    return static_cast<deduced_type>(*reinterpret_cast<deduced_type*>(&val));
  }

  T get_value_T(deduced_type val) {
    return static_cast<T>(*reinterpret_cast<T*>(&val));
  }

};

#endif  // __REGCHECKER_H_
