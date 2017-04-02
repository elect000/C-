#ifndef ___Class_HUMAN
#define ___Class_HUMAN

#include <string>
class Human
{
private:
  std::string full_name;
  int height;
  int weight;
public:
  Human(const std::string& full_name, int height, int weight);
  std::string name() const;
  int get_height() const;
  int get_weight() const;
  void grow_fat(int dw);
  void slime_off(int dw);
};


#endif /* ___Class_HUMAN */
