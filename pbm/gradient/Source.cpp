#include <stdio.h>
#include <math.h>

void header(int field_width, int field_height);
void draw_gradient(int field[], int size, int field_width, int field_height, int colors[], int colors_size, bool horizontal);
void output_array(int field[], int size, int field_width);

int main(void) {
	const int FIELD_WIDTH = 20;
	const int FIELD_HEIGHT = 1;
	const int SIZE = FIELD_WIDTH * FIELD_HEIGHT * 3;

	int field[SIZE] = { 0 };

	const int COLORS_SIZE = 3 * 3;
	int colors[COLORS_SIZE] = {255, 0, 0, 50, 100, 4, 255, 255, 255};

	header(FIELD_WIDTH, FIELD_HEIGHT);
	draw_gradient(field, SIZE, FIELD_WIDTH, FIELD_HEIGHT, colors, COLORS_SIZE, 0);
	output_array(field, SIZE, FIELD_WIDTH);

	return 0;
}

void header(int field_width, int field_height) {
	puts("P3");
	printf("%d %d\n", field_width, field_height);
	printf("255");
}

void draw_gradient(int field[], int size, int field_width, int field_height, int colors[], int colors_size, bool horizontal) {
	float step1 = 0, step2 = 0, step3 = 0;
	int colors_count = colors_size / 3;
	int part_size = field_width / (colors_count - 1);
	if (horizontal) {
		int k = 3;
		for (int i = 0; i < size && k / 3 <= field_width && field[size] <= colors[colors_size];) {
			colors[colors_size - 3] > colors[0] ? field[i] = colors[0] + step1 : field[i] = (colors[0] - step1);
			colors[colors_size - 2] > colors[1] ? field[i + 1] = colors[1] + step2 : field[i + 1] = (colors[1] - step2);
			colors[colors_size - 1] > colors[2] ? field[i + 2] = colors[2] + step3 : field[i + 2] = (colors[2] - step3);
			step1 += abs(colors[colors_size - 3] - colors[0]) / float(size) * 3.0;
			step2 += abs(colors[colors_size - 2] - colors[1]) / float(size) * 3.0;
			step3 += abs(colors[colors_size - 1] - colors[2]) / float(size) * 3.0;
			if (i == (field_height - 1) * field_width * 3 + k - 3) { 
				i = k;
				k += 3;
			} else {
				i += 3 * field_width; // go to the next line
			}
		}
	} else {
		for (int i = 0, j = 0; i < size && field[size] <= colors[colors_size]; i += 3) {
			colors[j + 3] > colors[j] ? field[i] = colors[j] + step1 : field[i] = (colors[j] - step1);
			colors[j + 4] > colors[j + 1] ? field[i + 1] = colors[j + 1] + step2 : field[i + 1] = (colors[j + 1] - step2);
			colors[j + 5] > colors[j + 2] ? field[i + 2] = colors[j + 2] + step3 : field[i + 2] = (colors[j + 2] - step3);
			step1 += abs(colors[j + 3] - colors[j]) / float(part_size);
			step2 += abs(colors[j + 4] - colors[j + 1]) / float(part_size);
			step3 += abs(colors[j + 5] - colors[j + 2]) / float(part_size);
			if (i != 0) { // 
				j += 3;
			}
		}
	}
}

void output_array(int field[], int size, int field_width) {
	printf("\n");
	for (int i = 0; i < size; i++) {
		if (i % 3 == 0) {
			printf("\t");
		}
		if (i % (field_width * 3) == 0) {
			printf("\n");
		}
		printf(" %d ", field[i]);
	}
}