#include <stdio.h>

int main(void) {
    float celsius = 1;
    
    puts("Type your value in celsius, please.");
    scanf("%f", &celsius);
    
    const float FORMULA = celsius * 9/5 + 32;
    printf("%.2f degrees Farenheit", FORMULA);
  return 0;
}