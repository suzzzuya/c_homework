#include <stdio.h>

void make_columns(int arr[], int size, int columns);

int main(void) {
	const int SIZE = 9;
	int columns = 3;
	int array[SIZE] = { 0 };

	make_columns(array, SIZE, columns);
	return 0;
}

void make_columns(int arr[], int size, int columns) {
	for (int i = 1; i <= size; i++) {
		arr[i - 1] = i;
		printf(" %d ", arr[i - 1]);
		if (i % columns == 0) {
			printf("\n");
		}
	}
}