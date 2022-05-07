#include <stdio.h>

int selfdiv(int n);

int main(void) {
	selfdiv(100);

	return 0;
}

int selfdiv(int n) {
	int tmp = n;
	int digit = n % 10;

	while (tmp > 0) {
		tmp /= 10;
		if (digit == 0 || n % digit != 0) {
			return 0;
		}
		digit = n % 10;
	}
	return 1;
}