#include <ctime>
#include <cstdlib>
#include <iostream>

using namespace std;

bool isB (int x) {
  return x >= 70 && x <= 79;
}

bool isA (int x) {
  return x >= 80 && x <= 100;
}

bool isC (int x) {
  return x >= 50 && x <= 69;
}

bool isAorC (int x) {
  return (isA(x) || isC(x));
}

void put_list (const int a[], int n, bool fit(int)) {
  for (int i = 0; i < n; i++) {
    if ((*fit)(a[i])) {
      cout << "★";
    } else {
      cout << "  ";
    }
    cout << "a[" << i << "] = " << a[i] << '\n';
  }
}

int main()
{
  int a[10];
  int n = sizeof(a) / sizeof(a[0]);
  srand(time(NULL));
  for (int i = 0; i < n; i++) {
    a[i] = rand() % 101;
  }
  cout << "良......" << '\n';
  put_list(a, n , isB);
  cout << "優or可..." << '\n';
  put_list(a, n, isAorC);
  return 0;
}

