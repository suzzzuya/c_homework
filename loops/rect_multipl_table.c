#include <stdio.h>

int main(void) {
  printf("*\t");
  for (int i = 1;i <= 10; i++) {
    printf("%d\t", i);
  }
  for (int i = 1; i <= 10; i++) {
    printf("\n%d", i);
    for (int n = 1; n <= 10; n++)
    printf("\t%d", i * n);
  }
  
  return 0;
}