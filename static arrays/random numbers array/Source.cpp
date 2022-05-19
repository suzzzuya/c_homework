#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void rand_nums(int arr[], const int size, int range);
void print_arr(int arr[], const int size);

int main(void) {
	srand(time(0));

	const int SIZE = 7;
	int array[SIZE] = { 0 };

	rand_nums(array, SIZE, 10);
	print_arr(array, SIZE);
	return 0;
}

void rand_nums(int arr[], const int size, int range) {
	for (int i = 0; i < size; i++) {
		arr[i] = rand() % range;
	}
}
void print_arr(int arr[], const int size) {
	for (int i = 0; i < size; i++) {
		printf("%d\n", arr[i]);
	}
}