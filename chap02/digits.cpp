#include <limits>
#include <iostream>
using namespace std;
int main()
{
  cout << "char = " << numeric_limits<unsigned char>::digits << '\n';
  cout << "short = " << numeric_limits<unsigned short>::digits << '\n';
  cout << "int = " << numeric_limits<unsigned int>::digits << '\n'; 
  cout << "long = " << numeric_limits<unsigned long>::digits << '\n';  
  return 0;
}
