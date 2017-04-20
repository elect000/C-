#ifndef SIMPLEDATE_H
#define SIMPLEDATE_H

class SimpleDate
{
  int y;
  int m;
  int d;

public:
  SimpleDate(int yy = 1, int mm = 1, int dd = 1) : y(yy), m (mm), d(dd) {}
  int year() const {return y;}
  int month() const {return m;}
  int day() const {return d;}
  
  int comp_y(int yy) const{return yy - y;}
  int comp_m(int mm) const{return mm - m;}
  int comp_d(int dd) const{return dd - d;}
};


#endif /* SIMPLEDATE_H */
