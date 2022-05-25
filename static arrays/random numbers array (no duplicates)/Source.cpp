#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void rand_nums(int arr[], const int size);
void print_arr(int arr[], const int size);

int main(void) {
	srand(time(0));

	const int SIZE = 5;
	int array[SIZE] = { 0 };

	rand_nums(array, SIZE);
	print_arr(array, SIZE);
	return 0;
}

void rand_nums(int arr[], const int size) {
	int range = size;
	bool is_there = false;

	for (int i = 0; i < size;) {
		is_there = false;
		int new_num = 1 + rand() % range; // [1 - size]
		
		for (int j = 0; j < i; j++) {
			if (arr[j] == new_num) {
				is_there = true;
			}
		}

		if (is_there == false) {
			arr[i] = new_num;
			i++;
		}
	}
}
void print_arr(int arr[], const int size) {
	for (int i = 0; i < size; i++) {
		printf("%d\n", arr[i]);
	}
}