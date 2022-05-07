#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int draw_symbol_line(char symbol, int length, int is_vertical);

int main(void) {
	char symbol = '*';
	int length = 5;
	int is_vertical = 1;

	draw_symbol_line(symbol, length, is_vertical);
}

int draw_symbol_line(char symbol, int length, int is_vertical) {
	if (symbol > 32 && symbol != 127 && length > 0) {
		if (is_vertical == 0) {
			for (int i = 0; i < length; i++) {
				printf("%c", symbol);
			}
		}
		else if (is_vertical == 1) {
			for (int i = 0; i < length; i++) {
				printf("%c", symbol);
				if (i < length - 1) {
					printf("\n");
				}
			}
		}
		return 1;
	}

	return 0;

}