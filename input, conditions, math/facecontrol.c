#include <stdio.h>

int main(void) {
    int user_age = 1;

    puts("How old are you ?");
    scanf("%d", &user_age);
    
    if (user_age >= 21) {
      puts("You are allowed to drink alco everywhere.");
    }
    else if (user_age >= 19 && user_age < 21) {
      puts("You are allowed to drink alco everywhere except USA.");
    }
    else if (user_age < 18) {
      puts("You are not allowed to drink alco at all.");
    }
    else {
      puts("You are allowed to drink alco everywhere except Canada and USA.");
    }
  return 0;
}