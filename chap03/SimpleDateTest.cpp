#include <iostream>
#include "SimpleDate.h"

using namespace std;

int main()
{
  typedef int (SimpleDate::*Comp)(int) const;
  Comp pcomp[] = {
    &SimpleDate::comp_y,
    &SimpleDate::comp_m,
    &SimpleDate::comp_d,
  };
  int menu;
  const SimpleDate birthday(1963, 11, 18);
  cout << "私の誕生日を当ててください\n";
  do
    {
      cout << "[0]year [1]month [2]day [3]exit\n";
      cin >> menu;	
      if (menu >= 0 && menu <= 2) {
	int value;
	cout << "Your expectation: ";
	cin >> value;
	int diff = (birthday.*pcomp[menu])(value);
	if (!diff) {
	  cout << "It is correct.\n";
	}
	else if (diff > 0) {
	  cout << "That is more than " << diff << '\n';
	}
	else {
	  cout << "That is less than " << -diff << '\n';
	}
      }
    } while (menu != 3);
  return 0;
}

