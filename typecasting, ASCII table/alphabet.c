#include <stdio.h>
int main (void) {
    const char uppercase = 'A'; // 65
    const char lowercase = 'a'; // 97

    for (int i = 0; i < 26; i++) {
        printf("%c ", uppercase + i);
        printf("%c", lowercase + i);
        if (i < 25) {
            printf(", ");
        } else {
            printf(".");
        }
    }
}