#include <stdio.h>

int main(void) {
  const int W = 4;
  const int H = 4;
  int blank = 0;

  for (int i = 0; i < W; i++) {
    printf("*");
  }
  for (int i = 1; i < H; i++) {
    printf("\n*");
  }
  for (int i = 1; i < W; i++) {
    printf("*");
  }
  return 0;
}