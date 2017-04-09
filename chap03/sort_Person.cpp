#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <iostream>

using namespace std;
class Person
{
public:
  char name[10];
  int height;
  int weight;
};

int npcmp (const Person* x, const Person* y) {
  return strcmp(x->name, y->name);
}

int hpcmp (const Person* x, const Person* y) {
  return x->height > y->height ? -1 : x->height == y ->height ? 0 : 1;
}

int wpcmp (const Person* x, const Person* y) {
  return x->weight > y->weight ? -1 : x->weight == y ->weight ? 0 : 1;
}

void print_person (const Person x[], int no) {
  for (int i = 0; i < no; i++) {
    cout << setw(10) << left << x[i].name << " " << x[i].height << "cm " << x[i].weight << "kg\n"; 
  }
}

int main () {
  Person x[] = {
    {"Shibata"  , 170, 52},
    {"Takaoka"  , 180, 70},
    {"Nangoh"	, 172, 63},
    {"Sugiyama"	, 165, 50}};
  int nx = sizeof(x) / sizeof(x[0]);
  puts("ソート前");
  print_person(x, nx);
  qsort(x, nx, sizeof(Person), reinterpret_cast<int (*) (const void*, const void*)>(npcmp));
  puts("\n名前順にソート後\n");
  print_person(x, nx);
  
  qsort(x, nx, sizeof(Person), reinterpret_cast<int (*) (const void*, const void*)>(hpcmp));
  puts("\n身長順にソート後\n");
  print_person(x, nx);
  
  qsort(x, nx, sizeof(Person), reinterpret_cast<int (*) (const void*, const void*)>(wpcmp));
  puts("\n体重順にソート後\n");
  print_person(x, nx);

}
