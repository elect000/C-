#ifndef ___Class_BitSet
#define ___Class_BitSet

#include <limits>
#include <string>
#include <iostream>

class BitSet
{
  static const int LONG_BIT  = std::numeric_limits<unsigned long>::digits;
  unsigned long bits;
  static bool is_valid(int v) {
    return v >= 0 && v < LONG_BIT;
  }
  static unsigned long set_of(int e) {
    return 1UL << e;
  }
public:
  static int max_element() {return LONG_BIT - 1; }
  static int min_element() {return 0;}
  BitSet() : bits(0UL) {};
  BitSet(const int e[], int n) : bits(0UL) {
    for (int i = 0; i < n; i++) {
      add(e [i]);
    }
  }
  bool constain(int e) const { 
    return is_valid(e) && (bits & set_of(e));
  }
  void add(int e) {
    if (is_valid(e)) {
      bits |= set_of(e); // bits = bits | set_of(e)
    }
  }
  void remove(int e){
    if (is_valid(e)) {
      bits &= ~set_of(e);
    }
  }
  bool empty() const {
    return !bits;
  }
  
  int size() const {
    int count = 0;
    unsigned long x = bits;
    while (x) {
      x &= x - 1;
      count++;
    }
    return count;
  }
  BitSet& operator&=(const BitSet& r) {
    bits &= r.bits;
    return *this;
  }
  BitSet& operator|=(const BitSet& r) {
    bits |= r.bits;
    return *this;
  }
  BitSet& operator^=(const BitSet& r) {
    bits ^= r.bits;
    return *this;
  }
  bool operator==(const BitSet& r) const {
    return bits == r.bits;
  }
  bool operator!=(const BitSet& r) const {
    return bits != r.bits;
  }
  std::string to_string() const;
  std::string bit_string() const;
};
std::ostream& operator<<(std::ostream& os, const BitSet& x);


#endif /* ___Class_BitSet */
