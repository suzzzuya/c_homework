#include <stdio.h>

enum CharCategory {
	ALPHABET,
	NUMBER,
	PUNCTUATION,
	NON_PRINTABLE,
	OTHER
};

CharCategory char_category(char c);

int main(void) {
	printf("%d", char_category('2'));
	return 0;
}

CharCategory char_category(char c) {
	if (c < ' ' && c != 127) {
		return NON_PRINTABLE;
	} else if (c >= 0 && c <= 9) {
		return NUMBER;
	} else if ((c >= 'A' && c <= 'Z') || (c > 'a' && c < 'z')) {
		return ALPHABET;
	}
	switch (c) {
		case '!':
		case '.':
		case ',':
		case ';':
		case ':':
		case '?':
			return PUNCTUATION;
		default:
			return OTHER;
	}
}