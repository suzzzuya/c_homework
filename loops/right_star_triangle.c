#include <stdio.h>

int main(void) {
  const int H = 5;

  for (int i = 0; i < H; i++) {
    for (int n = 0; n < i; n++) {
      printf("*");
    }
    printf("*\n");
  }
  return 0;
}