#include <stdio.h>

int main(void) {
  const int H = 8;
  int n = 1;

  for (int i = 1; i <= H; i++) {
    printf(" ");
    if (i == H - n + 1) {
      for (int b = H - 1; b >= H - n; b--) {
        printf("*");
      }
      printf("\n");
      n++;
      i = 0;
    }
    else {
      continue;
    }
  }
  return 0;
}