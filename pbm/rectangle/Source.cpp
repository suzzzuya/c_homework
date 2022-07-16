#include <stdio.h>

struct Rectangle {
	int x;
	int y;
	int width;
	int height;
	int color;
	int borderWidth;
};

void header(const int width, const int height);
void fill_array(int arr[], const int size, int color);
void draw_hollow_rect(int field[], int fieldHeight, int fieldWidth, Rectangle rectangle);
void draw_filled_rect(int field[], int fieldHeight, int fieldWidth, Rectangle rectangle);
void output_field(int field[], const int size, const int width);

int main(void) {
	const int FIELD_WIDTH = 10;
	const int FIELD_HEIGHT = 10;
	const int FIELD_SIZE = FIELD_WIDTH * FIELD_HEIGHT;

	int field[FIELD_SIZE] = { 0 };

	header(FIELD_WIDTH, FIELD_HEIGHT);
	fill_array(field, FIELD_SIZE, 0);
	draw_hollow_rect(field, FIELD_HEIGHT, FIELD_WIDTH, Rectangle { 1, 1, 5, 5, 1, 2 });
	output_field(field, FIELD_SIZE, FIELD_WIDTH);
	return 0;
}

void draw_filled_rect(int field[], int fieldHeight, int fieldWidth, Rectangle rectangle) {
	int dx = rectangle.x < 0 ? -rectangle.x : 0;
	int dy = rectangle.y < 0 ? -rectangle.y : 0;
	for (int y = dy; y < rectangle.height && y < fieldHeight && y < fieldHeight - rectangle.y; y++) {
		for (int x = dx; x < rectangle.width && x < fieldWidth && x < fieldWidth - rectangle.x; x++) {
			int index = rectangle.x + x + (rectangle.y + y) * fieldWidth;
			field[index] = rectangle.color;
		}
	}
}

void draw_hollow_rect(int field[], int fieldHeight, int fieldWidth, Rectangle rectangle) {
	int dx = rectangle.x < 0 ? -rectangle.x : 0;
	int dy = rectangle.y < 0 ? -rectangle.y : 0;
	rectangle.borderWidth = rectangle.borderWidth < 0 ? 1 : rectangle.borderWidth;
	for (int y = dy; y < rectangle.height && y < fieldHeight && y < fieldHeight - rectangle.y; y++) {
		for (int x = dx; x < rectangle.width && x < fieldWidth && x < fieldWidth - rectangle.x; x++) {
			if (y < rectangle.borderWidth || y > rectangle.height - rectangle.borderWidth - 1 || x < rectangle.borderWidth || x > rectangle.width - rectangle.borderWidth - 1) {
				int index = rectangle.x + x + (rectangle.y + y) * fieldWidth;
				field[index] = rectangle.color;
			}
		}
	}
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

