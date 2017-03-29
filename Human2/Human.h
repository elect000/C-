#ifndef ___CLASS_Human
#define ___CLASS_Human
#include <string>

class Human
{
private:
  std::string full_name;
  int height;
  int weight;
public:
  Human(const std::string& full_name, int height, int weight);
  std::string name () const;
  int get_height() const;
  int get_weight() const;
  void grow_fat(int dw);
  void slim_off(int dw);
  
};

#endif


