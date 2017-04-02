#include <iostream>
using namespace std;

int count_bits (unsigned x) {
  int bits = 0;
  while (x) {
    if (x & 1U) {
      bits++;
    }	
      x >>= 1;
  }
  return bits;
}

int int_bits() {
  return count_bits(~0U);
}

void print_bits(unsigned x) {
  for (int i = int_bits() - 1 ; i >= 0; i--) {
    cout << ((x >> i) & 1U ? '1' : '0');
  }
}


int main () {
  unsigned x, n;
  cout << "Input a number :";
  cin >> x;
  cout << "Input shift number : ";
  cin >> n;
  cout << "number = " ; print_bits(x); cout << '\n';
  cout << "left shift = " ; print_bits(x << n); cout << '\n';
  cout << "right shift = " ; print_bits(x >> n); cout << '\n';
}
