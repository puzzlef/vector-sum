#pragma once
#include <cstdint>
#include <istream>

using std::uint16_t;
using std::istream;




// Bfloat16
// --------
// 16-bit floating point (storage type only).

class Bfloat16 {
  uint16_t x;

  static uint32_t from32(const float& v) { return *((const uint32_t*)&v); }
  static uint16_t from16(const float& v) { return from32(v)>>16; }
  static float to32(const uint32_t& v) { return *((const float*)&v); }
  static float to16(const uint16_t& v) { return to32(v<<16); }

  public:
  Bfloat16() : x(0) {}
  Bfloat16(const Bfloat16&) = default;
  Bfloat16(Bfloat16&&)      = default;
  Bfloat16(const float& v) : x(from16(v)) {}
  operator float() const { return to16(x); }
  Bfloat16& operator=(const Bfloat16&) = default;
  Bfloat16& operator=(Bfloat16&&) = default;
  Bfloat16& operator=(const float& v) { x = from16(v); return *this; }

  friend istream& operator>>(istream& s, Bfloat16& v) {
    float f; s >> f; v = Bfloat16(f);
    return s;
  }
};
