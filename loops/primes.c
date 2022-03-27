#include <stdio.h>

int main(void) {
    int number = 0;
    int divider = 2 ;
    
    puts("Enter number: ");
    scanf("%d", &number);   
    if (number < 0) {
      puts("number is not prime");
    }
    else if (number == 1) {
      puts("number is prime");
    }
    else {
      while (number % divider != 0) {
        divider++;
      }
      if (divider == number) {
            puts("number is prime");
          }
      else {
        puts("number is not prime");
      }
    }
  return 0;
}