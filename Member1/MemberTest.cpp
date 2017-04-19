#include <iostream>
#include "Member.h"

using namespace std;

int main()
{
  Member kaneko("金子健太", 15, 75.2);
  double weight = kaneko.get_weight();
  kaneko.set_weight(weight - 3.7);
  cout << "No." << kaneko.no() << " : " << kaneko.name() << "(" << kaneko.get_weight() << "kg) \n";
  return 0;
}
