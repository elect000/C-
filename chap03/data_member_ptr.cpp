#include <iostream>
using namespace std;

class X
{
public:
  int a, b;
  X(int aa = 0, int bb = 0) : a(aa), b(bb) {}
  void print () { cout << "(" << a << "," << b << ")";}
};

int main() {
  X temp(99, 99);
  int X::* ptr;
  temp.print();			cout << '\n';
  ptr = &X::a; temp.*ptr = 10; temp.print(); cout << '\n';
  ptr = &X::b; temp.*ptr = 20; temp.print(); cout << '\n';
}
