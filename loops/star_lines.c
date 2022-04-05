#include <stdio.h>

int main (void) {
    const int n = 5;

    for (int i = 0; i < n; i++) {
        printf("*");
    }
    printf("\n");
    for (int i = 0; i < n; i++) {
          printf("*\n");
      }
    return 0;
}