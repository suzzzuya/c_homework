#include <stdio.h>
int main (void) {
    float number = 0;

    puts("Type a decimal number, please.");
    scanf("%f", &number);

    int result1 = number * 100; // deleting everything after 2 point digits
    float result2 = (float)result1 / 100.0;

    printf("%.f\n", result2);
}