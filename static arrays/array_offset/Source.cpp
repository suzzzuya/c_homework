#include <stdio.h>

void make_offset(int arr[], int size, int offset);
void print(int arr[], int size);

int main(void) {
	const int SIZE = 5;
	const int offset = -2;
	int array[SIZE] = { 1, 2, 3, 4 ,5 };
	

	make_offset(array, SIZE, offset);
	print(array, SIZE);
	return 0;
}

void make_offset(int arr[], int size, int offset) {
	int num = 0;
	if (offset > 0) {
		for (int i = 0; i < offset; i++) {
			num = arr[size - 1]; // get last num
			for (int j = 1; j <= size - i + offset - 2; j++) {
				arr[size - j] = arr[size - j - 1]; // shift right
			}
			arr[0] = num;
		}
	}
	if (offset < 0) {
		for (int i = 0; i > offset; i--) {
			num = arr[0]; // get first num
			for (int j = 1; j <= size - i - (offset - 2); j++) {
				arr[j - 1] = arr[j]; // shift left
			}
			arr[size - 1] = num;
		}
	}
	
}

void print(int arr[], int size) {
	for (int i = 0; i < size; i++) {
		printf("%d ", arr[i]);
	}
}