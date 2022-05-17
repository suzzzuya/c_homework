#include <stdio.h>

void reverse(int arr[], int size);

int main(void) {
	const int SIZE = 5;
	int arr[SIZE] = { 2, 6, 7, -1, 643 };

	reverse(arr, SIZE);
	return 0;
}

void reverse(int arr[], int size) {
	for (int i = size - 1; i >= 0; i--) {
		printf("%d\n", arr[i]);
	}
}