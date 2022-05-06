#include <stdio.h>

int char_icompare(char a, char b);

int main(void) {
	printf("%d", char_icompare('A', 'a'));
}

int char_icompare(char a, char b) {
	if (a > 96 && a < 123) {
		a = a - 32; // converting to one case
	}
	if (b > 96 && b < 123) {
		b = b - 32; // converting to one case
	}

	if (a == b) {
		return 1; // equal
	}
	if (64 < a < 91 || 64 < b < 91) {
		return -1; // at least one equal
	}
	return 0; // none of them
}