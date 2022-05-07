#include <stdio.h>

double rad_to_degree(double radians);
double degree_to_rad(double degrees);

int main(void) {
	printf("%f\n%f", rad_to_degree(13.2), degree_to_rad(-4.2));

	return 0;
}

double rad_to_degree(double radians) {
	const float PI = 3.14;
	float result = radians * PI / 180;

	return result;
}

double degree_to_rad(double degrees) {
	const float PI = 3.14;
	float result = degrees * 180 / PI;

	return result;
}