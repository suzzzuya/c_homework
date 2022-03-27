#include <stdio.h>
#include <math.h>

int main(void) {
    int x1 = 0;
    int y1 = 0;
    int x2 = 0;
    int y2 = 0;
    int x3 = 0;
    int y3 = 0;
    int x4 = 0;
    int y4 = 0;
    float length_1 = 0;
    float length_2 = 0;
    float diagonal = 0;
    float perimeter = 0;
    float area = 0; 

    puts("Enter x1:");
    scanf("%d", &x1);
    puts("Enter y1:");
    scanf("%d", &y1);
    puts("Enter x2:");
    scanf("%d", &x2);
    puts("Enter y2:");
    scanf("%d", &y2);   

    if (x1 == x2 || y1 == y2) {
      puts("Incorrect input.");
    }   
    else {
        x3 = x1;
        y3 = x2;
        x4 = x2;
        y4 = y1;    
        
        length_1 = sqrt((x1 - x3) * (x1 - x3) + (y1 - y3) * (y1 - y3));
        length_2 = sqrt((x1 - x4) * (x1 - x4) + (y1 - y4) * (y1 - y4));
        diagonal = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2)); 
        perimeter = 2 * (length_1+length_2);
        area = length_1 * length_2;
        printf("Perimeter: %.2f\n", diagonal);
        printf("Area: %.2f\n", area);
        printf("Diagonal: %.2f\n", diagonal);   
        if (length_1 > length_2) {
          puts("The rectangle is high");
        }
        if (length_1 < length_2) {
          puts("The rectangle is wide");
        }
        if (length_1 == length_2) {
          puts("The rectangle is square");
        }
    }
    
  return 0;
}