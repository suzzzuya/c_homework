#include <stdio.h>

void add_num(int arr[], int size, int num);
void print_arr(int arr[], int size);

int main(void) {
	const int SIZE = 5;
	int arr[SIZE] = { 2, 5, 1, 7, 2 };

	add_num(arr, SIZE, -1);
	print_arr(arr, SIZE);
	return 0;
}

void add_num(int arr[], int size, int num) {
	for (int i = 0; i < size - 1; i++) {
		arr[i] = arr[i + 1];
	} 
	arr[size - 1] = num;
}

void print_arr(int arr[], int size) {
	for (int i = 0; i < size; i++) {
		printf("%d\n", arr[i]);
	}
}