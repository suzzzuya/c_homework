#include <stdio.h>

int find_num(int arr[], int size, int number);

int main(void) {
	const int SIZE = 5;
	int arr[SIZE] = { 4, 6, 1, -75, 3 };

	printf("%d", find_num(arr, SIZE, -75));
	return 0;
}

int find_num(int arr[], int size, int number) {
	for (int i = 0; i < size; i++) {
		if (number == arr[i]) {
			return i;
		}
	}
	return -1;
}