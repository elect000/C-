#include <string>
#include <iostream>
#include "Human.h"

using namespace std;
Human::Human(const string& full_name, int height, int weight){
 this-> full_name = full_name;
 this-> height = height;
 this-> weight = weight;
}

string	Human::name() const{
  return full_name;
}

int Human::get_height() const{
  return height;
}

int Human::get_weight() const {
  return weight;
}

void Human::grow_fat(int dw) {
  weight += dw;
}

void Human::slim_off(int dw){
  weight -= dw;
}

