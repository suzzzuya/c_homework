#include <stdio.h>
#include <math.h>

float foo(float x, int n);

int main(void) {
	printf("%f", foo(2.1, 10));
	return 0;
}

float foo(float x, int n) {
	float res = 0;
	if (n < 0) {
		return res;
	}
	if (x < 4) {
		for (int i = 1; i < n; i++) {
			res += pow(sin(0.5 * x - 2), i);
		}
		res = 0.25 * x + 14 * res;
	} else if (x >= 4) {
		res = sqrt(x - 3);
	}
	return res;
}