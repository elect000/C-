#include <iostream>
#include <string>

using namespace std;

class Human
{
private:
  string full_name;
  int height;
  int weight;
public:
  Human(const string& name, int h, int w){
    full_name = name;
    weight = w;
    height = h;
  }
  string name(){
    return full_name;
  }
  int get_weight () {
    return weight;
      }
  int get_height () {
    return height;
      }
  void grow_fat (int dw) {
    weight+=dw;
      }
  void slim_off (int dw) {
    weight -= dw;
      }
  
};


int main()
{
  Human nakano("中野太郎", 173, 65);
  Human morita("森田浩二", 168, 71);
  nakano.slim_off(3);
  morita.grow_fat(10);

  cout << "nakano: " << nakano.name() << " " << nakano.get_height() << "cm " << nakano.get_weight() << "kg \n";
  cout << "morita: " << morita.name() << " " << morita.get_height() << "cm " << morita.get_weight() << "kg \n";

  return 0;
}
//
