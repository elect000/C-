#include <stdio.h>
#include <math.h>

int main()
{
  double a, b, c, D, x1,x2;
  printf(" ax^2 + bx + c = 0 の係数 a, b, cを入力せよ----> ");
  scanf("%lf %lf %lf", &a, &b, &c);
  // (1)
  if (a == 0 && b == 0) {
    printf("係数が正しくない\n");
    return 1;
  }
  // (2)
  if (a == 0 && b != 0) {
    printf("一次方程式の解が求まった。\n解は、%lf\n" ,-1 * (c / b));
    return 0;
  }
  
  D = b * b - 4 * c;
  // (3)
  if (D > 0) {
    D = sqrt(D);
    x1 = -1 * b * b + D;
    x2 = -1 * b * b - D;
    x1 /= 2 * a;
    x2 /= 2 * a;
    printf("2つの実数解が求まった。\n解は、%lf, %lf\n" , x1, x2 );
    return 0;
  }
  // (4)
  if (D == 0) {
    printf("重解が求まった。\n解は、%lf\n" ,-1 * (( b * b ) / 2 * a));
    return 0;
  }
  // (5)
  if (D < 0) {
    printf("この二次方程式は実数解を持たない。\n");
    return 0;
  }
  return 1;
}
