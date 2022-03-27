#include <stdio.h>

int main(void) {
  int n1 = 0;
  int n2 = 1;
  int n3 = 1;

  int last_num = 1;
  puts("What is the last num ?");
  scanf("%d", &last_num);
  printf("%d, ", n1);

  while (n3 <= last_num) {
    printf(" %d ", n3);
    n3 = n1 + n2;  
    n1 = n2;
    n2 = n3;

    if (n3 <= last_num){
      printf(",");
    }
  }
  return 0;
}