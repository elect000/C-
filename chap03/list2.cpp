#include <ctime>
#include <cstdlib>
#include <iostream>

using namespace std;

bool isA (int x) {
  return x >= 80 && x <= 100;
}
bool isB (int x) {
  return x >= 70 && x <= 79;
    }

void put_list (const int a[], int n, int sw) {
  for (int i = 0; i < n; i++) {
    bool flag;
    switch (sw) {
    case 1: {
      flag = isA(a[i]);
      break;
    }
    case 0: {
      flag = isB(a[i]);
      break;
    }
default:
      break;
    }
    if (flag) {
      cout << "★";
    }else {
      cout << "　";
    }
    cout << "a[ " << i <<  "] = " << a[i] << '\n';
  }
}

int main ()
{
  int a[10];
  int n = sizeof(a) / sizeof(a[0]);
  int sw = 1;
  srand(time(NULL));
  for (int i = 0; i < n; i++) {
    a[i] = rand() % 101;
  }
  put_list(a, n, sw);
  return 0;
}

