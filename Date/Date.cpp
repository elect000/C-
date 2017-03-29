#include <ctime>
#include <sstream>
#include <iostream>
#include "Date.h"

using namespace std;
int Date::dmax[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int Date::days_of_year(int year){
  return 365 + leap_year(year);
}

int Date::days_of_month(int year, int month){
  return dmax[month - 1] + (month == 2 && leap_year(year));
}

Date::Date(){
  time_t current = time(NULL);
  struct tm* local = localtime(&current);
  y = local->tm_year + 1900;
  m = local->tm_mon + 1;
  d = local->tm_mday;
}

Date::Date(int yy, int mm, int dd){
  set(yy, mm, dd);
}

void Date::set(int yy, int mm, int dd) {
  y = yy;
  m = mm;
  d = dd;
}

Date Date::preceding_day() const{
  Date temp(*this);
  return --temp;
}

Date Date::following_day() const{
  Date temp(*this);
  return ++temp;
}
int Date::day_of_year() const{
  int days = d;
  for (int i = 1; i < m; i++) {
    days += days_of_month(y, i);
  }
  return days;
}

int Date::day_of_week() const{
  int yy = y;
  int mm = m;
  if (mm == 1 || mm == 2) {
    yy--;
    mm += 12;
  }
  return (yy +  yy / 4 - yy / 100 + yy / 400 + (13 * mm + 8) / 5 + d) % 7;
}

Date::operator long() const {
  return *this - Date(1970 ,1 ,1);
}

Date& Date::operator++(){
  if (d < days_of_month(y, m)) {
    d++;
  }
  else {
    if (++m > 12) {
      y++;
      m = 1;
    }
    d = 1;
  }
  return *this;
}

Date Date::operator++(int){
  Date temp(*this);
  ++(*this);
  return temp;
}



Date& Date::operator--(){
  if (d > 1) {
    d--;
  }
  else {
    if (--m <= 1) {
      y--;
      m = 12;
    }
    d = days_of_month(y, m);
  }
  return *this;
}

Date Date::operator--(int) {
  Date temp(*this);
  --(*this);
  return temp;
}

Date& Date::operator+=(int dn){
  if (dn < 0) {
    return *this -= -dn;
  }
  d += dn;
  while (d > days_of_month(y, m)) {
    d -= days_of_month(y, m);
    if (++m > 12) {
      y++;
      m = 1;
    }
  }
  return *this;
}

Date& Date::operator-=(int dn){
  if (dn < 0) {
    return *this += -dn;
  }
  d -= dn;
  while (d < 1) {
    if (--m < 1) {
      y--;
      m = 12;
    }
    d += days_of_month(y, m);
  }
  return *this;
}

Date Date::operator+(int dn) const{
  Date temp(*this);
  return temp += dn;
} 

Date operator+(int dn, const Date& day){
  return day + dn;
}

Date Date::operator-(int dn) const {
  Date temp (*this);
  return temp -= dn;
}

long Date::operator-(const Date& day) const{
  long count;
  long count1 = this->day_of_year();
  long count2 = day.day_of_year();
  if (y == day.y) {
    count = count1 - count2;
  }else if (y > day.y) {
    count = days_of_year(day.y) - count2 + count1;
    for (int yy = day.y + 1; yy < y; yy++) {
      count += days_of_year(yy);
    }
  }else {
    count = -(days_of_year(y) - count1 + count2);
    for (int yy = y + 1; yy < day.y; yy++) {
      count -= days_of_year(yy);
    }
  }
  return count;
}

bool Date::operator== (const Date& day) const{
  return y == day.y && m == day.m && d == day.d;
}

bool Date::operator!=(const Date& day)  const{
  return !(*this == day);
}

bool Date::operator> (const Date& day) const{
  if (y > day.y) return true;
  if (y < day.y) return false;
  if (m > day.m) return true;
  if (m < day.m) return false;
  return d > day.d;
} 

bool Date::operator>= (const Date& day) const {
  return !(*this < day);
}

bool Date::operator< (const Date& day) const {
  if( y < day.y) return true;
  if( y > day.y) return false;
  if( m < day.m) return true;
  if( m > day.m) return false;
  return d < day.d;
}

bool Date::operator<= (const Date& day) const {
  return !(*this > day);
}

string Date::to_string() const {
  ostringstream s;
  s << y << "年" << m << "月" << d << "日";
  return s.str();
}

ostream& operator<<(ostream& s, const Date& x){
  return s << x.to_string();
}

istream& operator>>(istream& s, Date& x){
  int yy, mm, dd;
  char ch;
  s >> yy >> ch >> mm >> ch >> dd;
  x = Date(yy, mm, dd);
  return s;
}

