#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

void draw_symbol_line(char symbol, int length);

int main(void) {
	char symbol = '*';
	int length = 5;

	draw_symbol_line(symbol, length);
}

void draw_symbol_line(char symbol, int length) {
	for (int i = 0; i < length; i++) {
		printf("%c", symbol);
	}
}