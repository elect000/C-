#include <cstdlib>
#include <iostream>
using namespace std;
int int_cmp (const int* a, const int* b) {
  if (*a < *b) {
    return -1;
  }
  else if (*a > *b) {
    return 1;
  }
  else {
    return 0;
  }
}

int main()
{
  int nx;
  cout << "配列の要素数: ";
  cin >> nx;
  int* x = new int[nx];
  cout << nx << "個の整数を昇順に入力してください。\n";
  for (int i = 0; i < nx; i++) {
    do
      {
	cout << "x[" << i << "] = ";
	cin >> x[i];
      } while (x[i] < x [i - 1]);
  }
  int no;
  cout << "探索する値: ";
  cin >> no;
  int* p = reinterpret_cast<int*>(bsearch(&no, x, nx, sizeof(x[0]),
				      reinterpret_cast<int (*) (const void* , const void*)>(int_cmp)));
  if (p != NULL) {
    cout << "x[" << (p - x) << "]が一致しました\n";
  } else {
    cout << "見つかりませんでした\n";
  }
  return 0;
}
