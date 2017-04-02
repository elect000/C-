#include <iostream>
#include "IntArray.h"

using namespace std;

int main() {
  IntArray v1(5);
  for (int i = 0; i < v1.size(); i++) {
    v1[i] = i + 1;
  }
  const IntArray v2 = v1;
  for (int i = 0; i < v1.size() ; i++) {
    cout << "v1[" << i + 1 << "] = " << v1[i] << '\n';
  }
  for (int i = 0; i < v2.size() ; i++) {
    cout << "v2[" << i + 1 << "] = " << v2[i] << '\n';
  }
}
 
