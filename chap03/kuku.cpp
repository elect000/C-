#include <iomanip>
#include <iostream>
using namespace std;
int sum(int x1, int x2) {
  return x1 + x2;
}

int mul(int x1, int x2) {
  return x1 * x2;
}

void kuku (int calc(int, int)) {
  cout << "  |";
  for (int i = 1; i < 10; i++) {
    cout << setw(3) << i;
  }
  cout << "\n--+";
  for (int i = 1; i < 10; i++) {
    cout << "---";
  }
  cout << '\n';
  for (int i = 1; i < 10; i++) {
    cout << i << " |";
    for (int j = 1; j < 10; j++) {
      cout << setw (3) << calc(i, j);
    }
    cout << '\n';
  }
}

int main()
{
  cout << "九九の加算表" << '\n';
  kuku(sum);
  cout << '\n';
  cout << "九九の乗算表" << '\n';
  kuku(mul);
  cout << '\n';
  return 0;

}
