#include <stdio.h>
int main (void) {
    int ascii_character = 32; // first readable character

    for (int i = 0; i < 127 - 32; i++, ascii_character++) {
        printf("Decimal: %d Char: %c\n", ascii_character, ascii_character);
    }
}