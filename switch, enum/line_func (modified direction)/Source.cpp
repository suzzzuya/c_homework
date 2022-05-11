#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

enum Result {
	OK,
	WRONG_SYMBOL,
	WRONG_LENGTH
};

enum Direction {
	VERTICAL,
	HORIZONTAL
};

Result draw_symbol_line(char symbol, int length, Direction direction);

int main(void) {
	printf("%d", draw_symbol_line('[', 9, VERTICAL));
}

Result draw_symbol_line(char symbol, int length, Direction direction) {
	if (length <= 0) {
		return WRONG_LENGTH;
	} 
	if (symbol < 32 && symbol != 127) {
		return WRONG_SYMBOL;
	} 
	if (direction == VERTICAL) {
		for (int i = 0; i < length; i++) {
			printf("%c\n", symbol);
		}
		return OK;
	}
	for (int i = 0; i < length; i++) {
		printf("%c", symbol);
	}
	printf("\n");
	return OK;
}