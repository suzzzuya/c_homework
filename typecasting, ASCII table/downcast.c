#include <stdio.h>
int main (void) {
    float initial_num = 0;
    int changed_num = 0;

    puts("Type a decimal number, please.");
    scanf("%f", &initial_num);

    changed_num = initial_num;

    printf("Decimal: %f Integer: %d", initial_num - changed_num, changed_num);
}
