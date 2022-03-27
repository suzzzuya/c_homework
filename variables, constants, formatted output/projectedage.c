#include <stdio.h>

int main(void) {
    int age = 16;
    int years = 7;

    printf("I'm %d years old.\n", age);
    age = age + years;
    printf("I'll be %d years old in %d year(s).\n\n", age, years);
    return 0;
}