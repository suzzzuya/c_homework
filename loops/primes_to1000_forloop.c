#include <stdio.h>

int main(void) {
  const int LIMIT = 1000;
  int is_prime = 0;

  for (int i = 1, divider = 2;i <= LIMIT;i += 2) {
    is_prime = 1;
    for (;divider <= i / 2;divider++) {
      if (i % divider == 0) {
        is_prime = 0;
        break;
      }
    }
    if (is_prime == 1) {
      printf("%d ", i);
    }
    divider = 2;
  }
  return 0;
}