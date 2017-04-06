#include <iostream>
using namespace std;
enum Animal{
Dog,Cat,Monkey,Invalid
};
void dog () {
  cout << "Wow!\n";
    }
void cat () {
  cout << "Mew!\n";
    }
void monkey () {
  cout << "Key!\n";
    }
Animal select () {
  int tmp;
do
  {
    cout << "(0)Dog (1)Cat (2)Monley (3)Exit:  ";
    cin >> tmp;
  } while (tmp < Dog || tmp > Invalid);
    
 return static_cast<Animal>(tmp);
}

int main()
{
  Animal selected;
  typedef void (*AnimalFP) ();
  AnimalFP afp[] =  {dog, cat, monkey};
  do
    {
      selected = select();
      if (selected >= Dog && selected < Invalid){
	afp[selected]();
      }
    } while (selected != Invalid);
  return 0;
}

