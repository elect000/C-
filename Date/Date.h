#ifndef ___Class_Date
#define ___Class_Date

#include <iostream>
#include <string>

class Date
{
  int  y, m, d;
  static int dmax[];
  static int days_of_year(int year);
  static int days_of_month(int year, int month);

public:
  static bool leap_year (int year) {
    return year % 4 == 0 && (year % 100 != 0 || year % 400 == 0);
  }
  Date();
  Date(int yy, int mm = 1, int dd = 1);
  bool leap_year() const {
    return leap_year (y); 
  }
  int year() const {return y;}
  int month() const {return m;}
  int day() const {return d;}
  void set_year(int yy) { y = yy; }
  void set_month (int mm) { m = mm;}
  void set_day (int dd) { d = dd;}
  void set(int yy, int mm, int dd);
  Date preceding_day() const;
  Date following_day() const;
  int day_of_year() const;
  int day_of_week() const;
  operator long() const;
  Date& operator++();
  Date operator++(int);
  Date& operator--();
  Date operator--(int);
  Date& operator+=(int dn);
  Date& operator-=(int dn);
  Date operator+(int dn) const;
  friend Date operator+ (int dn, const Date& day);
  Date operator-(int dn) const;
  long operator-(const Date& day) const;
  bool operator==(const Date& day) const;
  bool operator!=(const Date& day) const;
  bool operator<=(const Date& day) const;
  bool operator<(const Date& day) const;
  bool operator>=(const Date& day) const;
  bool operator>(const Date& day) const;
  std::string to_string() const;
};

  std::ostream& operator<<(std::ostream& s, const Date& x);
  std::istream& operator>>(std::istream& s,	Date& x);


#endif /* ___Class_Date */
