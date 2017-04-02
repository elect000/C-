#include <iostream>
#include <string>
#include "Human.h"

using namespace std;

int main()
{
  Human nakano("中野太郎", 173,  65);
  const Human morita("森田太郎", 168, 71);
  nakano.slime_off(3);
  cout << "nakano = " << nakano.name() << " " << nakano.get_weight() << "kg " << nakano.get_height() << "cm " << '\n' ;
  cout << "morita = " << morita.name() << " " << morita.get_weight() << "kg " << morita.get_height() << "cm " << '\n' ;
  return 0;
}
