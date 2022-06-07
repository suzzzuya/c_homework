#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

void show_logs(float weight[], float diff[], int size, float difference);
void shift_array(float weight[], int size);
void remove_entry(float weight[], float diff[], int index, int removeEntry, int empty);
float calc_difference(float weight[], int size, int index);

int main(void) {
	puts("\tWeight tracking application");
	
	bool breakLoop = false;
	char userInput = 0;

	const int SIZE = 10;
	float weightLogs[SIZE] = { 0 };
	float diffLogs[SIZE] = { 0 };
	int index = 0;

	const int EMPTY = 0;

	while (userInput != 'E' && userInput != 'e') {
		puts("\n\tChoose any of the options below");

		userInput = 0;

		while (userInput != 'N' &&
			userInput != 'n' &&
			userInput != 'R' &&
			userInput != 'r' &&
			userInput != 'L' &&
			userInput != 'l' &&
			userInput != 'E' &&
			userInput != 'e') {
			puts("\n[N]ew entry");
			puts("[R]emove entry");
			puts("[L]ogs");
			puts("[E]xit");

			scanf(" %c", &userInput);
		}

		int removeEntry = 0;
		float weight = 0;
		float difference = 0;
		
		switch (userInput) {
		case 'N':
		case 'n':
			puts("Enter your weight, please");
			scanf("%f", &weight);

			weightLogs[index] = weight; // adds new entry to the array

			difference = calc_difference(weightLogs, SIZE, index);
			diffLogs[index] = difference;

			index++; // moves to next entry
			break;
		case 'R':
		case 'r':
			puts("Enter entry number to remove\n");
			show_logs(weightLogs, diffLogs, SIZE, difference);

			scanf("%d", &removeEntry);
			removeEntry -= 1; // match with array

			remove_entry(weightLogs, diffLogs, index, removeEntry, EMPTY);
			index = removeEntry;
			difference = calc_difference(weightLogs, SIZE, index);
			diffLogs[index] = difference;
			removeEntry = 0;
			break;
		case 'L':
		case 'l':
			show_logs(weightLogs, diffLogs, SIZE, difference);
			break;
		case 'E':
		case 'e':
			breakLoop = true;
			break;
		}
		if (breakLoop) {
			break;
		}
		if (index > 10) {
			shift_array(weightLogs, SIZE);
		}
	}
	return 0;
}

void remove_entry(float weight[], float diff[], int index, int removeEntry, int empty) {
	weight[removeEntry] = empty;
	diff[removeEntry] = empty;

	for (int i = 0; removeEntry + i <= index; i++) {
		weight[removeEntry + i] = weight[removeEntry + i + 1];
		diff[removeEntry + i] = diff[removeEntry + i + 1];
	}

}

void shift_array(float weight[], int size) {
	for (int i = 0; i < size; i++) {
		weight[i] = weight[i + 1];
	}
}

void show_logs(float weight[], float diff[], int size, float difference) {
	for (int i = 0; i < size && weight[i] > 0; i++) {
		printf("%d) %.2f kg ", i + 1, weight[i]);
		if (diff[i] > 0) {
			printf("(+%.2f %%)\n", diff[i]);
		} else {
			printf("(%.2f %%)\n", diff[i]);
		}
	}
}

float calc_difference(float weight[], int size, int index) {
	float result = 0;

	if (index > 0) {
		if (weight[index] < weight[index - 1]) {
			result = ((weight[index - 1] / weight[index]) * 100 - 100) * -1;
		} else {
			result = ((weight[index] / weight[index - 1]) * 100 - 100);
		}
		return result;
	}
	return 0;
}