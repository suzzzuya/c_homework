#include <stdio.h>

int main(void) {
    const float SECONDS_PER_HOUR = 3600;
    const float SECONDS_PER_DAY = 86400;
    float seconds_since_accident = 62035.7; // seconds

    printf("%.2f Hours passed since accident \n", seconds_since_accident / SECONDS_PER_HOUR); // hours since accident
    printf("%.2f Day(s) passed since accident \n\n", seconds_since_accident / SECONDS_PER_DAY);
    return 0;
}