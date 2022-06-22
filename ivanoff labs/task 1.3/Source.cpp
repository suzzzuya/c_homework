#include <stdio.h>
#include <math.h>

float foo(float x, int n);

int main(void) {
	printf("%f", foo(12.642, 10));

	return 0;
}

float foo(float x, int n) {
	float mult = 1;
	for (int i = 1; i < n - 1; i++) {
		float sum = 0;
		for (int j = 0; j < n; j++) {
			if (j + x == 0) {
				return 0;
			}
			sum += i / float((j + x));
		}
		mult *= sum;
	}
	return mult;
}