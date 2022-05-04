#include <stdio.h>

int divide(int a, int b);

int main(void) {

	printf("%d", divide(2,14));
	return 0;
}

int divide(int a, int b) {
	int i = 0;
	int copyOfB = b;
	while (b <= a) {
		b += copyOfB;
		i++;
	}
	return i;
}