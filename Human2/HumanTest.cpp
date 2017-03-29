#include <iostream>
#include <string>
#include "Human.h"

using namespace std;	

int main () {
  Human nakano ("中野太郎",173,65);
  const Human morita ("森田浩二",168, 71);
  nakano.grow_fat(3);

  cout << "nakano: " << nakano.name() << " " << nakano.get_height() << "cm " << nakano.get_weight() << "kg \n";
  cout << "morita: " << morita.name() << " " << morita.get_height() << "cm " << morita.get_weight() << "kg \n";

  return 0;
}


