#include <stdio.h>
int main (void) {
    float money = 0;

    puts("Type an amount of money, please.");
    scanf("%f", &money);

    int changed_money = money * 100; // deleting remain numbers
    float result = changed_money / 100.0;

    if (result != money || money < 0) {
        puts("Incorrect input.");
    } else {
        puts("Fine.");
    }
}