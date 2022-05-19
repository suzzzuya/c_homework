#include <stdio.h>

float arr_avg(int arr[], int size);

int main(void) {
	const int SIZE = 5;
	int arr[SIZE] = { -12, 45, 3, 5, 2 };

	printf("%f", arr_avg(arr, SIZE));
	return 0;
}

float arr_avg(int arr[], int size) {
	float sum = 0;
	float result = 0;
	for (int i = 0; i < size; i++) {
		sum += arr[i];
	} 
	result = sum / size;
	return result;
}