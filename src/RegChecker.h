#ifndef __REGCHECKER_H_
#define __REGCHECKER_H_

#include "utils.h"

template<typename T, const char *NAME, const uint32_t REG_ADDR>
class RegisterChecker {
public:
  typedef UintSelector<sizeof(T) / 8> deduced_type_T;

  T reg = { };

  const inline uint32_t get_address() {
    return REG_ADDR;
  }

  const inline char* get_name() {
    return NAME;
  }

  deduced_type_T get_value_k() {
    return static_cast<deduced_type_T>(*reinterpret_cast<deduced_type_T*>(&reg));
  }

  T get_value_T(deduced_type_T v) {
    return  static_cast<T>(*reinterpret_cast<T*>(&v));
  }

  RegisterChecker& operator=(deduced_type_T v) {
    old_value = v;
    reg = get_value_T(v);
    return *this;
  }

  bool operator !=(deduced_type_T data) const {
    return data != *(deduced_type_T*) &reg;
  }

  bool changed() {
    bool ret = false;
    if (old_value != *(deduced_type_T*) &reg) {
      ret = true;
      old_value = *(deduced_type_T*) &reg;
    }
    return ret;
  }

  operator deduced_type_T() const {
    return *(deduced_type_T*) &reg;
  }

  operator RegisterChecker() const {
    return reg;
  }

private:
  deduced_type_T old_value = 0;
};

#endif  // __REGCHECKER_H_
