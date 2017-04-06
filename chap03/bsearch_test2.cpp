#include <cstdlib>
#include <iostream>

using namespace std;

int int_cmpr (const int* a, const int* b) { 
  if (*a < *b) {
    return 1;
  }
  else if (*a > *b) {
    return -1;
  }
  else {
    return 0;
  }
}

int main()
{
  int nx;
  cout << "配列の要素数:";
  cin >> nx;
  int* x = new int[nx];
  cout << nx <<"個の整数を降順に入力せよ\n";
  cout << "x[0] = ";
  cin >> x[0];
  for (int j = 1; j < nx; j++) {
    do
      {
	cout << "x[" << j << "] = ";
	cin >> x[j];
      } while (x[j] > x[j - 1]);
  }
  int no;
  cout << "探索する値: ";
  cin >> no;
  int* p = reinterpret_cast<int*>(bsearch(&no, x, nx, sizeof(int), 
					  reinterpret_cast<int (*) (const void*, const void*)>(int_cmpr)));
  if (p != NULL) {
    cout << "x[" << (p - x) << "]が一致します。\n";
  } else {
    cout << "見つかりませんでした。\n";
  }
  return 0;
}
