#include <stdio.h>
#include <math.h>

int main(void) {

    puts("Enter the first point (x1, y1)");

    float x1 = 0;
    float y1 = 0;

    scanf("%f", &x1);
    scanf("%f", &y1);

    if (x1 > 0 && y1 > 0) {
      puts("first quadrant");
    }
    else if (x1 < 0 && y1 > 0) {
      puts("second quadrant");
    }
    else if (x1 < 0 && y1 < 0) {
      puts("third quadrant");
    }
    else if (x1 > 0 && y1 < 0) {
      puts("fourth quadrant");
    }

    puts("\nEnter the second point (x2, y2)");

    float x2 = 0;
    float y2 = 0;

    scanf("%f", &x2);
    scanf("%f", &y2);   
    if (x2 > 0 && y2 > 0) {
      puts("first quadrant");
    }
    else if (x2 < 0 && y2 > 0) {
      puts("second quadrant");
    }
    else if (x2 < 0 && y2 < 0) {
      puts("third quadrant");
    }
    else if (x2 > 0 && y2 < 0) {
      puts("fourth quadrant");
    }

    double length = 1.0;
    float x3 = x1 - x2;
    float y3 = y1 - y2; 
    x3 = pow(x3, 2);
    y3 = pow(y3, 2);

    length = x3 + y3;
    length = sqrt(length);
    printf("\nLength: %lf", length);
    return 0;
}