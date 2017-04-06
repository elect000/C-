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
  do
    {
      selected = select();
      switch(selected) {
      case Dog: dog(); break;
      case Cat: cat(); break;
      case Monkey: monkey(); break;
      default : break;
      }
    } while (!(selected == Invalid));
  return 0;
}

