#include <stdio.h>

int main(void) {
  const int H = 7;
  for (int i = 1; i <= H; i++) { 
        for (int j = i; j < H; j++) {
            printf(" ");
        }
  
        for (int j = 1; j <= 2 * i - 1; j++) {
            printf("*");
        }

        printf("\n");
    }

    return 0;
}