#ifndef MEMBER_H
#define MEMBER_H

#include <string>
class Member
{
  std::string full_name;
  int number;
  double weight;
public:
  Member(const std::string& name, int no, double w);
  std::string name() const {return full_name;}
  int no() const {return number;}
  double get_weight() const {return weight;}
  void set_weight(double dw) {weight += dw;}
};
#endif /* MEMBER_H */
