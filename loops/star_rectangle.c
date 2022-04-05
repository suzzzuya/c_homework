#include <stdio.h>

int main(void) {
  const int W = 7;
  const int H = 5;

  for (int i = 0; i < H; i++) {
    printf("\n*");
    for(int i = 1; i < W; i++) {
      printf("*");
    }
  }
  return 0;
}