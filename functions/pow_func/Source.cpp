#include <stdio.h>

unsigned int pow(int n, unsigned int e);

int main(void) {
	printf("%d", pow(2, 10));
}

unsigned int pow(int n, unsigned int e) {
	int result = 1;
	for (int i = 0; i < e; i++) {
		result = result * n;
	}
	return result;
}