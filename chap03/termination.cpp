#include <ctime>
#include <iostream>
#include <cstdlib>
using namespace std;
void good_bye () {
  cout << "プログラムは正常に終了しました。" << '\n';
    }
void put_time () {
  time_t current = time(NULL);
  struct tm* lct = localtime(&current);
  cout << lct->tm_hour << ":" << lct->tm_min << ":" << lct->tm_sec << '\n';
}

int main()
{
  int x;
  atexit(good_bye);	
  atexit(put_time);
  cout << "[0]正常終了 [1]異常終了:";
  cin >> x;
  if (x) {
    abort();
  }
  return 0;
}
