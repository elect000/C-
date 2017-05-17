#include <stdio.h>
#include <iostream>
// ヘッダを書くべき
class Birthday
{
  int y;
  int m;
  int d;
public:
  Birthday(int yy, int mm, int dd) {
    this->y = yy;
    this->m = mm;
    this->d = dd;
  };
  int year () const {
    return y;
  };
  int month () const {
    return this->m;
  };
  int day () const {
    return d;
  };
};

std::ostream& operator << (std::ostream& s, const Birthday& bt){
  return s <<  bt.year() << "年" << bt.month() << "月" << bt.day() << "日";
};

// 本来は別ファイル（例えばBirthdayTest.cpp）で作るべきコード
int main()
{
  char buff_year[10];
  char buff_month[10];
  char buff_day[10];
  std::cout << "誕生日を入力してください。\n";
  std::cout << "年: ";
  // https://msdn.microsoft.com/en-us/library/2029ea5f.aspx より使用できない。
  //セキュリティ上の問題よりC++14からも削除されている
  //std::gets()
  // fgets(char* str, int n, FILE *steam);
  fgets(buff_year, sizeof(buff_year), stdin);
  std::cout << "月: ";
  fgets(buff_month, sizeof(buff_month), stdin);
  std::cout << "日: ";
  fgets(buff_day, sizeof(buff_day), stdin);
  int year = atoi(buff_year);
  int month = atoi(buff_month);
  int day = atoi(buff_day);
  Birthday birth = Birthday(year, month, day);
  std::cout << "誕生日は" << birth.year() << "月" << birth.month() << "月" << birth.day() << "日です。\n";
  return 0;
}
  

