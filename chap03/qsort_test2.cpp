#include <cstdlib>
#include <iostream>

using namespace std;

int int_cmp(const int* a, const int* b) {
  return *a < *b ? 1 : *a == *b ? 0 : -1; 
}

int main () {
  int nx;
  cout << "配列の要素数: ";
  cin >> nx;

  int* x = new int[nx];
  
  cout << nx << "の整数を入力せよ: \n";
  for (int i = 0; i < nx; i++) {
    cout << "x[" << i <<"] = ";
    cin >> x[i];
  }
  qsort(x, nx, sizeof(int), reinterpret_cast<int (*) (const void* , const void*)>(int_cmp));
  cout << "ソート完了\n";
  for (int i = 0; i < nx; i++) {
    cout << "x[" << i << "] = " << x[i] << '\n';
  }
}
