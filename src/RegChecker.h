#ifndef __REGCHECKER_H_
#define __REGCHECKER_H_

#include "utils.h"

template<typename T, const char *NAME, const uint32_t REG_ADDR>
class RegisterChecker {
public:
  typedef UintSelector<sizeof(T) / 8> deduced_type;

  T reg = { };

  const inline uint32_t get_address() {
    return REG_ADDR;
  }

  const inline char* get_name() {
    return NAME;
  }

  RegisterChecker& operator=(deduced_type v) {
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

  operator RegisterChecker() const {
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

  deduced_type get_value_k(T &_reg) {
    return static_cast<deduced_type>(*reinterpret_cast<deduced_type*>(&_reg));
  }

  T get_value_T(deduced_type v) {
    return static_cast<T>(*reinterpret_cast<T*>(&v));
  }

};

#endif  // __REGCHECKER_H_
