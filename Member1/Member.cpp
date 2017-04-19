#include <iostream>
#include "Member.h"
using namespace std;

Member::Member(const string& name, int no, double w) 
  : full_name(name), number(no)
{
  set_weight(w);
}
