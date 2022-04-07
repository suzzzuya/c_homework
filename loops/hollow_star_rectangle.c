#include <stdio.h>

int main (void) {
    const int W = 7;
    const int H = 6;

    for (int i = 0; i < W; i++) {
        printf("*");
    }
    printf("\n");
    for (int i = 2; i < H; i++) {
        printf("*");
        for (int i = 0; i < W - 2; i++) {
          printf(" ");
        }
        printf("*\n");
    }
    for (int i = 0; i < W; i++) {
        printf("*");
    }
}