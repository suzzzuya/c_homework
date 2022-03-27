#include <stdio.h>

int main(void) {
    float price_per_kg = 23.5;
    float kg_per_day = 0.65;

    printf("Pet: Sema\n");
    printf("------\n");
    printf("Daily average consumption: %.2f kg/day\n", kg_per_day);
    printf("Projected weekly consumption: %.2f kg/week\n", kg_per_day * 7);
    printf("Projected monthly consumption: %.2f kg/month\n", kg_per_day * 30.5);
    printf("------\n");
    printf("Daily expenses: %.2f UAH/day \n", price_per_kg * kg_per_day);
    printf("Projected weekly expenses: %2.f UAH/week\n", price_per_kg * kg_per_day * 7);
    printf("Projected monthly expenses: %2.f UAH/month\n\n", price_per_kg * kg_per_day * 30);
    return 0;
}