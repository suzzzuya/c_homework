#include <stdio.h>

int main(void) {
  int number = 0;
  puts("Type a number:");
  scanf("%d", &number);

  for (int i = 2; i != 10; i++) {
    printf("%d * %d = %d \n", number, i, i*number);
  }
  return 0;
}