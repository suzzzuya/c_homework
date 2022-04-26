#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(0) / 4 * 69);

    int first_number, second_number = 0;
    puts("Type first number.");
    scanf("%d", &first_number);
    puts("Type second number.");
    scanf("%d", &second_number);

    if (first_number > second_number) {
        puts("first number in range can't be bigger than second.");
    } else {
        int how_to_name_it = second_number - first_number + 1;
        printf("[%d ; %d] - %d \n", first_number, second_number, rand() % how_to_name_it + first_number);
    }
    
    return 0;
}
