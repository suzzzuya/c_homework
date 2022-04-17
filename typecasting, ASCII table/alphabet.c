#include <stdio.h>
int main (void) {
    char uppercase = 65; // Letter A
    char lowercase = 97; // Letter a

    for (int i = 0; i != 26 ; i++, uppercase++, lowercase++) {
        printf("%c %c", uppercase, lowercase);
        
        if (i < 25) {   // comma
            printf(" , "); 
        }
    }
}