#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void print_field(int arr[], int size, int columns, int choice);
int place_mine(int arr[], int size);
int convert(char player_row, int player_column);

int main(void) {
	srand(time(0));

	const int SIZE = 9;
	int columns = 3;
	int array[SIZE] = { 0 };

	char player_row = 0;
	int player_column = 0;

	int player_choice = -1;
	int mine_choice = -2;

	for (int i = 0; i < SIZE; i++) {
		array[i] = '.';
	}

	int i = 1;

	puts("\tWELCOME TO THE MINESWEEPER!\n");

	print_field(array, SIZE, columns, player_choice);

	while (player_choice != mine_choice || i < 9) {
		while (player_row < 'a' || player_row > 'c') {
			puts("\nEnter row letter, please.\n");
			scanf(" %c", &player_row);
		}

		while (player_column < 1 || player_column > 3) {
			puts("\nEnter column number, please.\n");
			scanf(" %d", &player_column);
		}

		player_choice = convert(player_row, player_column);
		mine_choice = place_mine(array, SIZE);

		print_field(array, SIZE, columns, player_choice);

		i++;
		player_row = 0;
		player_column = 0;
	}
	
	puts("\n\tXXXX YOU LOST XXXX\n");
	
	return 0;
}

int convert(char row, int column) {
	switch (row) {
	case 'a':
		if (column == 1) {
			return 0;
			break;
		}
		if (column == 2) {
			return 3;
			break;
		}
		if (column == 3) {
			return 6;
			break;
		}
	case 'b':
		if (column == 1) {
			return 1;
			break;
		}
		if (column == 2) {
			return 4;
			break;
		}
		if (column == 3) {
			return 7;
			break;
		}
	case 'c':
		if (column == 1) {
			return 2;
			break;
		}
		if (column == 2) {
			return 5;
			break;
		}
		if (column == 3) {
			return 8;
			break;
		}
	default:
		break;
	}
}

int place_mine(int arr[], int size) {
	int gen_row = 1 + rand() % 3;
	switch (gen_row) {
	case 1:
		gen_row = 'a';
		break;
	case 2:
		gen_row = 'b';
		break;
	case 3:
		gen_row = 'c';
		break;
	}
	int gen_column = 1 + rand() % 3;

	return convert(gen_row, gen_column);
}

void print_field(int arr[], int size, int columns, int choice) {
	printf("   ");
	for (int i = 'a'; i <= 'c'; i++) {
		printf(" %c ", i);
	}
	printf("\n");
	printf(" %d ", 1);
	for (int i = 1, j = 2; i <= size; i++) {
		if (choice != -1) {
			arr[choice] = '1';
		}
		printf(" %c ", arr[i - 1]);
		if (i % columns == 0) {
			printf("\n");
			if (j <= 3) {
				printf(" %d ", j);
				j++;
			}
		}
	}
	
}