#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

enum Result {
	OK,
	WRONG_SYMBOL,
	WRONG_LENGTH
};

Result draw_symbol_line(char symbol, int length);

int main(void) {
	printf("%d", draw_symbol_line(']', 10));
}

Result draw_symbol_line(char symbol, int length) {
	if (length <= 0) {
		return WRONG_LENGTH;
	} else if (symbol < 32 && symbol != 127) {
		return WRONG_SYMBOL;
	}
	for (int i = 0; i < length; i++) {
		printf("%c", symbol);
	} 
	printf("\n");
	return OK;
}