#include <stdio.h>

int main(void) {
    float first_angle = 1;
    float second_angle = 1;
    float third_angle = 1;  
    puts("Type 3 angles, please.");

    scanf("%f\n",&first_angle);
    scanf("%f\n",&second_angle);
    scanf("%f",&third_angle);

    if(first_angle + second_angle + third_angle != 180) {
      puts("It can't be a triangle.");
    }
    else if(first_angle == 90 || second_angle == 90 || third_angle == 90){
      puts("This triangle is right.");
    }
    else if(first_angle == 60 && second_angle == 60 && third_angle == 60){
      puts("This triangle is equilateral.");
    }
    else if(first_angle == second_angle || first_angle == third_angle || second_angle == third_angle) {
      puts("This triangle is isosceles.");
    }
    else {
      puts("This triangle is scalene.");
    }
  return 0;
}