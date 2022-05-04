#include <stdio.h>

double rad_to_degree(double r2d);
double degree_to_rad(double d2r);

int main(void) {
	printf("%f\n%f", rad_to_degree(13.2), degree_to_rad(-4.2));

	return 0;
}

double rad_to_degree(double r2d) {
	const float PI = 3.14;
	float result = r2d * PI / 180;

	return result;
}

double degree_to_rad(double d2r) {
	const float PI = 3.14;
	float result = d2r * 180 / PI;

	return result;
}