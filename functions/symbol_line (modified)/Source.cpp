#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int draw_symbol_line(char symbol, int length);

int main(void) {
	char symbol = '*';
	int length = 5;

	draw_symbol_line(symbol, length);
}

int draw_symbol_line(char symbol, int length) {
	if (symbol > 32 && symbol != 127 && length > 0) {
		for (int i = 0; i < length; i++) {
			printf("%c", symbol);
		}
		return 1;
	}

	return 0;
	
}