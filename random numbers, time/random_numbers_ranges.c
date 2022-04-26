#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main() {
    srand(time(0) / 4 * 69);

    printf("[0 ; 100] - %d \n", rand() % 101);
    printf("[50 ; 100] - %d \n", rand() % 51 + 50);
    printf("[-100 ; 100] - %d \n", rand() % 201 - 100);
    return 0;
}
