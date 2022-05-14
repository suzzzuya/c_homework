#include <stdio.h>
#include <math.h>

enum ComparisonResult {
	EQUAL_SAME_CASE,
	EQUAL_DIFFERENT_CASE,
	NOT_EQUAL,
	NON_ALPHA
};

ComparisonResult char_icompare(char a, char b);

int main(void) {
	printf("%d\n", char_icompare('g', 'G'));
	printf("%d\n", char_icompare('h', 'h'));
	printf("%d\n", char_icompare('[', '3'));
	printf("%d", char_icompare('0', '/'));
	return 0;
}

ComparisonResult char_icompare(char a, char b) {
	const int DIFFERENCE = 'a' - 'A';

	if (a == b) {
		return EQUAL_SAME_CASE;
	}

	if ((a < 'A' || a > 'Z' && a < 'a' || a > 'z') || (b < 'A' || b > 'Z' && b < 'a' || b > 'z')) {
		return NON_ALPHA;
	}

	if (abs(a - b) == DIFFERENCE) {
		return EQUAL_DIFFERENT_CASE;
	}

	return NOT_EQUAL;
}