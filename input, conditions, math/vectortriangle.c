#include <stdio.h>
#include <math.h>

int main(void) {
    const int x1 = 4;
    const int y1 = -2;

    const int x2 = 2;
    const int y2 = 6;

    const int x3 = 4;
    const int y3 = -3;  
    
    if (x1 == x2 && x2 == x3 || y1 == y2 && y2 == y3) {
      puts ("It can't be a triangle");
    }
    else {

      float length_1 = 0; // first side
      length_1 = pow((x1 - x2), 2) + pow((y1 - y2), 2);
      length_1 = sqrt(length_1);
      printf("%.2f\n", length_1);

      float length_2 = 0; // second side
      length_2 = pow((x2 - x3), 2) + pow((y2 - y3), 2);
      length_2 = sqrt(length_2);
      printf("%.2f\n", length_2);

      float length_3 = 0; // third side
      length_3 = pow((x1 - x3), 2) + pow((y1 - y3), 2);
      length_3 = sqrt(length_3);
      printf("%.2f\n", length_3);

      float perimetr = 0;
      perimetr = length_1 + length_2 + length_3;
      printf("\nPerimetr is: %.2f\n",perimetr);

      float area = 0;
      float half_perimetr = 0;
      half_perimetr = perimetr / 2;
      area = sqrt(half_perimetr * (half_perimetr - length_1) *   (half_perimetr - length_2) * (half_perimetr - length_3)); // heron formula
      printf("Area is: %.2f\n", area);

      float first_angle = 0;
      float second_angle = 0;
      float third_angle = 0;

      const float PI = 3.14;
    
      first_angle = (length_1 * length_1 + length_2 * length_2 - length_3 * length_3) / (2 * length_1 * length_2);
      first_angle = acos(first_angle);
      first_angle =  180.0/PI * first_angle;
      printf("%.2f", first_angle);

      if (first_angle < 90) {
        printf("\t this angle is acute.\n");
      }
      else if (first_angle == 90) {
        printf("\t this angle is right.\n");
      }
      else {
        printf("\t this angle is obtuse\n");
      }
    
      second_angle = (length_2 * length_2 + length_3 * length_3 - length_1 * length_1) / (2 * length_2 * length_3);
      second_angle = acos(second_angle);
      second_angle =  180.0/PI * second_angle;
      printf("%.2f", second_angle);

      if (second_angle < 90) {
        printf("\t this angle is acute.\n");
      }
      else if (second_angle == 90) {
        printf("\t this angle is right.\n");
      }
      else {
        printf("\t this angle is obtuse\n");
      }
    
      third_angle = (length_3 * length_3 + length_1 * length_1 - length_2 * length_2) / (2 * length_3 * length_1);
      third_angle = acos(third_angle);
      third_angle =  180.0/PI * third_angle;
      printf("%.2f", third_angle);

      if (third_angle < 90) {
        printf("\t this angle is acute.\n");
      }
      else if (third_angle == 90) {
        printf("\t this angle is right.\n");
      }
      else {
        printf("\t this angle is obtuse\n");
      }
    
      if (first_angle == 90 || second_angle == 90 || third_angle == 90) {
        puts("This triangle is right.");
      }
      else if (first_angle == 60 && second_angle == 60 && third_angle == 60) {
        puts("This triangle is equilateral.");
      }
      else if (first_angle == second_angle || first_angle == third_angle || second_angle == third_angle) {
        puts("This triangle is isosceles.");
      }
      else {
        puts("This triangle is scalene.");
      }
    }
  return 0;
}