#include <stdio.h>

int main(void) {
    const int LIMIT = 1000;
    int i = 1;
    int divider = 2;
    int is_prime = 0;   
    while (i <= LIMIT) {
      is_prime = 1;
      while (divider <= i / 2) {
        if (i % divider == 0) {
          is_prime = 0;
          break;
        }
        divider++;
      }
      if (is_prime == 1) {
        printf("%d \n", i);
      }
      i = i + 2;
      divider = 2;
    }
  return 0;
}