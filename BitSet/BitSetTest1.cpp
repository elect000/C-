#include <iostream>
#include "BitSet.h"
using namespace std;
int main() {
  BitSet b1;
  int a[] = {0, 4, 5, 15, 31};
  BitSet b2(a, sizeof(a)/ sizeof(a[0]));
  BitSet b3 = b2;
  cout << "b1 = " << b1 << '\n';
  cout << "     " << b1.bit_string() << "\n\n";
  cout << "b2 = " << b2 << '\n';
  cout << "     " << b2.bit_string() << "\n\n";
  cout << "b3 = " << b3 << '\n';
  cout << "     " << b3.bit_string() << "\n\n";
}
