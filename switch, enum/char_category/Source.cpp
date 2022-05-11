#include <stdio.h>

enum charCategory {
	ALPHABET,
	NUMBER,
	PUNCTUATION,
	NON_PRINTABLE,
	OTHER
};

charCategory char_category(char c);

int main(void) {
	printf("%d", char_category('2'));
	return 0;
}

charCategory char_category(char c) {
	if (c < 32 && c != 127) {
		return NON_PRINTABLE;
	} else if (c > 47 && c < 58) {
		return NUMBER;
	} else if ((c > 64 && c < 91) || (c > 96 && c < 123)) {
		return ALPHABET;
	}
	switch (c) {
		case 33:
		case 44:
		case 46:
		case 58:
		case 59:
		case 63:
			return PUNCTUATION;
			break;
		default:
			return OTHER;
			break;
	}
}