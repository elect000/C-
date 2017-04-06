#include <string>
#include <sstream>
#include <iostream>
#include "BitSet.h"

using namespace std;
string BitSet::to_string() const {
  ostringstream s;
  int set[LONG_BIT];
  int count = 0;
  for (int i = 0; i < LONG_BIT; i++) {
    if (bits & set_of(i)) {
      set[count++] = i; // this count means latest count : ++count > count++
    }
  }
  s << "{";
  if (count) {
    for (int i = 0; i < count - 1; i++) {
      s << set[i] << ", ";
    }
    s << set[count - 1];
  }
  s << "}";
  return s.str();
}

string BitSet::bit_string() const {
  char bp[LONG_BIT + 1];
  for (int i =  LONG_BIT - 1; i >= 0; i--) {
    bp[LONG_BIT - i - 1] = (set_of(i) & bits) ? '1' : '0';
  }
  bp[LONG_BIT] = '\0';
  return string(bp);
}

ostream& operator<<(ostream& os, const BitSet& x) {
  return os << x.to_string();
}
