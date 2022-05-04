#include <stdio.h>
#include <math.h>

float distance(float x1, float y1, float x2, float y2);

int main(void) {
	printf("%f", distance(4, 4, 3, 3));

	return 0;
}

float distance(float x1, float y1, float x2, float y2) {
	float result = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
	return result;
}