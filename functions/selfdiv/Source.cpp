#include <stdio.h>

int selfdiv(int n);

int main(void) {
	selfdiv(100);

	return 0;
}

int selfdiv(int n) {
	int copyOfN = n;
	int lastDigit = n % 10;

	while (n > 0) {
		if (lastDigit == 0 || copyOfN % lastDigit != 0) {
			return 0;
		}
		n = n / 10;
		lastDigit = n % 10;
	}
	return 1;
}