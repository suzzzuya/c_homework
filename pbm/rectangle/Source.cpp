#include <stdio.h>

void header(const int width, const int height);
void fill_array(int arr[], const int size, int color);
int draw_hollow_rect(int field[], int fieldHeight, int fieldWidth, int rx, int ry, int color, int height, int width, int bw);
int draw_filled_rect(int field[], int fieldHeight, int fieldWidth, int rx, int ry, int color, int height, int width);
void output_field(int field[], const int size, const int width);

int main(void) {
	const int FIELD_WIDTH = 10;
	const int FIELD_HEIGHT = 10;
	const int FIELD_SIZE = FIELD_WIDTH * FIELD_HEIGHT;

	int field[FIELD_SIZE] = { 0 };

	header(FIELD_WIDTH, FIELD_HEIGHT);
	fill_array(field, FIELD_SIZE, 0);
	draw_hollow_rect(field, FIELD_HEIGHT, FIELD_WIDTH, 0, 0, 1, 10, 10, 2);
	output_field(field, FIELD_SIZE, FIELD_WIDTH);
	return 0;
}

int draw_filled_rect(int field[], int fieldHeight, int fieldWidth, int rx, int ry, int color, int height, int width) {
	int dx = rx < 0 ? -rx : 0;
	int dy = ry < 0 ? -ry : 0;
	for (int y = dy; y < height && y < fieldHeight && y < fieldHeight - ry; y++) {
		for (int x = dx; x < width && x < fieldWidth && x < fieldWidth - rx; x++) {
			int index = rx + x + (ry + y) * fieldWidth;
			field[index] = color;
		}
	}
	return 1;
}

int draw_hollow_rect(int field[], int fieldHeight, int fieldWidth, int rx, int ry, int color, int height, int width, int bw) {
	int dx = rx < 0 ? -rx : 0;
	int dy = ry < 0 ? -ry : 0;
	bw = bw < 0 ? 1 : bw;
	for (int y = dy; y < height && y < fieldHeight && y < fieldHeight - ry; y++) {
		for (int x = dx; x < width && x < fieldWidth && x < fieldWidth - rx; x++) {
			if (y < bw || y > height - bw - 1 || x < bw || x > width - bw - 1) {
				int index = rx + x + (ry + y) * fieldWidth;
				field[index] = color;
			}
		}
	}
	return 1;
}

void output_field(int field[], const int size, const int width) {
	for (int i = 0; i < size; i++) { // outputs array
		printf("%d ", field[i]);
		if ((i + 1) % width == 0) {
			printf("\n");
		}
	}
}

void fill_array(int arr[], const int size, int color) {
	for (int i = 0; i < size; i++) {
		arr[i] = color; // fill with zeros
	}
}

void header(const int width, const int height) {
	puts("P1");
	printf("%d %d\n", width, height);
}

