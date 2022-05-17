#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void rand_nums(int arr[], const int size, int range);

int main(void) {
	const int SIZE = 7;
	int array[SIZE] = { 0 };

	rand_nums(array, SIZE, 10);
	return 0;
}

void rand_nums(int arr[], const int size, int range) {
	srand(time(0));
	
	for (int i = 0; i < size; i++) {
		arr[i] = rand() % range;
		printf("%d\n", arr[i]);
	}
}