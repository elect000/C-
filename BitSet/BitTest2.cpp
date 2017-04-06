#include <iostream>
#include "BitSet.h"

using namespace std;
void display(const BitSet& b1, const BitSet& b2){
  cout << "b1 = " << b1 << '\n';
  cout << "     " << "要素数は" << b1.size() << "。∅で"
                  << (b1.empty() ? "す。":"はありません") << "。\n";
  cout << "     " << "ビットは" << b1.bit_string() << "\n\n";
  cout << "b2 = " << b2 << '\n';
  cout << "     " << "要素数は" << b2.size() << "。∅で"
                  << (b2.empty() ? "す。":"はありません") << "。\n";
  cout << "     " << "ビットは" << b2.bit_string() << "\n\n";
  cout << "b1 == b2 は　" << (b1 == b2 ? "true" : "false") << "です。\n";
  cout << "b1 != b2 は　" << (b1 != b2 ? "true" : "false") << "です。\n\n";
}

void add_delete (BitSet& b1, BitSet& b2) {
  while(true) {
    cout << "[1]b1に追加 [2]b1から削除 [3]b2に追加 [4]b2から削除 [0]戻る： ";
    int selected;
    cin >> selected;
    if (selected < 1 || selected > 4) {
      return ;
    }
    int e ;
    cout << (selected % 2 == 1 ? "追加" : "削除") << "する要素: ";
    cin >> e;
    switch (selected) {
    case 1: b1.add(e); break;
    case 2: b1.remove(e); break;
    case 3: b2.add(e); break;
    case 4: b2.remove(e); break;
    }
    if (selected == 1 || selected == 2) {
      cout << "b1は" << b1 << "に更新されました。\n";
    } else {
      cout << "b2は" << b2 << "に更新されました。\n";
    }
  }
}

void update (BitSet& b1, BitSet& b2) {
  cout << "b1をb2との集合演算結果に更新します。\n";
  while (true) {
    cout << "[1]積集合 [2]和集合 [3]差集合 [0]戻る: ";
    int selected;
    cin >> selected;
    if (selected < 1 || selected > 3) {
      return ;
    }
    switch (selected) {
    case 1: b1 &= b2;	break;
    case 2: b1 |= b2; break;
    case 3: b1 ^= b2; break;
    }
    cout << "b1は" << b1 << "に更新されました。\n";
  }
}

int main() {
  cout << "ビットベクトルによる集合クラスBitSetをテストするプログラムです。\n";
  cout << "本環境で表せる要素の値は" << BitSet::min_element() << "~" << BitSet::max_element() << "です。\n";
  BitSet b1;
  int a[] = {1, 3, 5};
  BitSet b2(a, sizeof(a) / sizeof(a[0]));
  while (true) {
    cout << "[1]情報表示 [2]要素の追加・削除 [3]集合演算 [0]終了：　";
    int selected ;
    cin >> selected;
    if (selected == 0) {
      break;
    }
    switch(selected){
    case 1: display(b1, b2); break;
    case 2: add_delete(b1, b2); break;
    case 3: update(b1, b2); break;
    }
  }
}
