#include <iostream>

using namespace std;

int main(){
  int sint;
  unsigned uint;
  cout << "符号付き整数：　"; cin >> sint;
  cout << "符号なし整数：　"; cin >> uint;
  cout << "(" << sint << " < " << uint  << "U)は"
       << ((sint < uint) ? "真": "偽") << "です。\n";
}
