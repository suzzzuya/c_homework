#include <stdio.h>
int main (void) {
    int ascii_character = 0; // first character
    int space_character = ' '; // blank character
    
    for (; ascii_character < 256; ascii_character++) {
        if (ascii_character < 33) {
            printf("Decimal: %d Char: %c ", ascii_character, space_character);
        } else if (ascii_character > 32 && ascii_character < 85) {
            printf("Decimal: %d Char: %c ", ascii_character, ascii_character);
        } else {
            break;
        }
        printf("\tDecimal: %d Char: %c ", ascii_character + 85, ascii_character + 85);
        printf("\tDecimal: %d Char: %c ", ascii_character + 171, ascii_character + 171);
        printf("\n");
    }
}