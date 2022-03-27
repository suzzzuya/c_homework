#include <stdio.h>

int main(void) {
    const int n = 10;
    int i = 0;
    float num,sum = 0;
    
    while (i < n) {
      num = i + 1;
      i++;
      printf("Num: %.2f\n", num);
      sum = num + sum;
    }
    sum = sum / n;
    printf("Average: %.2f", sum);
    return 0;
}