#include <stdio.h>
int main (void) {
    int ascii_character = 0; // first character

    for (int i = 0; i < 33; i++, ascii_character++) {
        printf("Decimal: %d Char:  \n", ascii_character);
    }
    for (int i = 0; i < 127 - 33; i++, ascii_character++) {
        printf("Decimal: %d Char: %c\n", ascii_character, ascii_character);
    }
    printf("Decimal: %d Char:  \n", ascii_character);
}