#include <stdio.h>

int char_icompare(char a, char b);

int main(void) {
	printf("%d\n", char_icompare('F', ' '));
	printf("%d\n", char_icompare('r', 'R'));
	printf("%d\n", char_icompare('j', 'g'));
	printf("%d\n", char_icompare(' ', 's'));
	printf("%d\n", char_icompare('Z', 'A'));
	printf("%d\n", char_icompare(' ', 'Z'));
}

int char_icompare(char a, char b) {
	const int DIFFERENCE = 'a' - 'A'; // 32

	if (a > 96 && a < 123) {
		a = a - DIFFERENCE; // converting to one uppercase
	}
	if (b > 96 && b < 123) {
		b = b - DIFFERENCE; // converting to one uppercase
	}

	if (a == b) {
		return 1; // equal ignoring register
	}
	if (a < 'A' || a > 'Z' || b < 'A' || b > 'Z') {
		return -1; // at least one not equal to latin alphabet
	}
	return 0; // none of them
}