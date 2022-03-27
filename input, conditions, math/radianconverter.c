#include <stdio.h>

int main(void) {
  float degree = 1;
  const float PI = 3.14;
  
  puts("Input angle in degrees, please.");
  scanf("%f", &degree);
  
  const float FORMULA =  PI/180 * degree;
  
  printf("%.2f your value in radians", FORMULA);
  return 0;
}