#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int time_zone = 3; // UTC + 3

    int hours = time(0) / 3600 % 24 + time_zone;
    int minutes = time(0) / 60 % 60;
    int seconds = time(0) % 60;

    printf("%02d:%02d:%02d", hours, minutes, seconds);
    return 0;
}
