#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int find_smallest(int arr[], const int size);

int main(void) {
	const int SIZE = 5;
	int arr[SIZE] = { 4, 2, 5, 6, 2 };
	
	printf("%d", find_smallest(arr, SIZE));
	return 0;
}

int find_smallest(int arr[], const int size) {
	int smallest = arr[0];
	for (int i = 0; i < size; i++) {
		if (smallest > arr[i]) {
			smallest = arr[i];
		};
	} return smallest;
}