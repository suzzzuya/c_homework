#include <stdio.h>

int main(void) {
    float const PI = 3.14;
    float r = 6.7; // dk why i need other variables in the task

    printf("Circle area is: %.2f \n", PI * r * r);
    printf("Circle length is: %.2f\n\n", 2 * PI * r);
    return 0;
}