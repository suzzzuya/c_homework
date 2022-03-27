#include <stdio.h>
#include <math.h>

int main(void) {
    float x1, y1 , x2 , y2 = 0;

    printf("x1 = ");
    scanf("%f", &x1);
    printf("y1 = ");
    scanf("%f", &y1);
    printf("x2 = ");
    scanf("%f", &x2);
    printf("y2 = ");
    scanf("%f", &y2);

    if (x1 == x2 || y1 == y2) {
      puts("Incorrect input.");
    }
    else {  
          float length_1, length_2 = 0;
          length_1 = sqrt(pow((x1 - x2), 2));
          printf("\nLength 1: %.2f\n", length_1);
          length_2 = sqrt(pow((y1 - y2), 2));
          printf("Length 2: %.2f\n", length_2);
          // sum
          float sum_1 = 0;
          float sum_2 = 0;
          sum_1 = x1 + x2;
          sum_2 = y1 + y2;

          printf("\nSum: (%.0f;%.0f)\n", sum_1, sum_2);
          // difference
          float difference_1 = 0;
          float difference_2 = 0;

          difference_1 = x2 - x1;
          difference_2 = y2 - y1;

          printf("Difference: (%.0f;%.0f)\n", difference_1, difference_2);

          // normalize
          printf("\nNormalized: (%.0f;%.0f) / %.1f\n", x1,y1,length_1);
          printf("\nNormalized: (%.0f;%.0f) / %.1f\n", x2,y2,length_2);
        }
  return 0;
    
}