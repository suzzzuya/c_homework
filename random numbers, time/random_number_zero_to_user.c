#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(0) / 4 * 69);

    int input = 0;
    scanf("%d", &input);
    printf("[0 ; %d] - %d \n", input, rand() % input + 1);
    return 0;
}
