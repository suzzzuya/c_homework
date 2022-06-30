#include <stdio.h>
#include <math.h>

void header(int field_width, int field_height);
void draw_gradient(int field[], int size, int field_width, int field_height, int startr, int startg, int startb, int endr, int endg, int endb, bool horizontal);
void output_array(int field[], int size, int field_width);

int main(void) {
	const int FIELD_WIDTH = 100;
	const int FIELD_HEIGHT = 100;
	const int SIZE = FIELD_WIDTH * FIELD_HEIGHT * 3;

	int field[SIZE] = { 0 };

	header(FIELD_WIDTH, FIELD_HEIGHT);
	draw_gradient(field, SIZE, FIELD_WIDTH, FIELD_HEIGHT, 100, 20, 100, 40, 50, 40, 1);
	output_array(field, SIZE, FIELD_WIDTH);

	return 0;
}

void header(int field_width, int field_height) {
	puts("P3");
	printf("%d %d\n", field_width, field_height);
	printf("255");
}

void draw_gradient(int field[], int size, int field_width, int field_height, int startr, int startg, int startb, int endr, int endg, int endb, bool horizontal) {
	float tmp1 = 0, tmp2 = 0, tmp3 = 0;
	if (horizontal) {
		int k = 3;
		for (int i = 0; i < size && k / 3 <= field_width;) {
			endr > startr ? field[i] = startr + tmp1 : field[i] = (startr - tmp1);
			endg > startg ? field[i + 1] = startg + tmp2 : field[i + 1] = (startg - tmp2);
			endb > startb ? field[i + 2] = startb + tmp3 : field[i + 2] = (startb - tmp3);
			tmp1 += abs(endr - startr) / float(size) * 3.0;
			tmp2 += abs(endg - startg) / float(size) * 3.0;
			tmp3 += abs(endb - startb) / float(size) * 3.0;
			if (i == (field_height - 1) * field_width * 3 + k - 3) { // go to the next line
				i = k;
				k += 3;
			} else {
				i += 3 * field_width;
			}
		}
	} else {
		for (int i = 0; i < size; i += 3) {
			endr > startr ? field[i] = startr + tmp1 : field[i] = (startr - tmp1);
			endg > startg ? field[i + 1] = startg + tmp2 : field[i + 1] = (startg - tmp2);
			endb > startb ? field[i + 2] = startb + tmp3 : field[i + 2] = (startb - tmp3);
			tmp1 += abs(endr - startr) / float(size) * 3.0;
			tmp2 += abs(endg - startg) / float(size) * 3.0;
			tmp3 += abs(endb - startb) / float(size) * 3.0;
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