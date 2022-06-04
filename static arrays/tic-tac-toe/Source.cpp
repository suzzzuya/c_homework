#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

enum Choices {
	CROSSES,
	NOUGHTS,
	BLANK
};

void fill_array(int size, int arr[]);
void print_field(int width, int size, int arr[]);

const int WIDTH = 3;
const int HEIGTH = 3;
const int SIZE = WIDTH * HEIGTH;

int field[SIZE] = { 0 };

int main(void) {
	fill_array(SIZE, field);

	printf("Welcome to TIC-TAC-TOES\n");

	int player_choice = 1;
	int ai_choice = 1;

	while (player_choice != 'x' &&
		player_choice != 'X' &&
		player_choice != 'o' &&
		player_choice != 'O' &&
		player_choice != '0') {

		printf("Would you like to play as Xs or Os ?\n");
		scanf(" %c", &player_choice);
	}

	if (player_choice == 'x' || player_choice == 'X') {
		player_choice = CROSSES;
		ai_choice = NOUGHTS;
	} else {
		player_choice = NOUGHTS;
		ai_choice = CROSSES;
	}

	printf("\n");

	while (1) {
		print_field(WIDTH, SIZE, field);

		int player_index = -1;
		int ai_index = -1;

		do {
			printf("\nIt's your turn, choose any number above\n");
			scanf("%d", &player_index);
			player_index = player_index - 1;
		} while ((player_index < 1 || player_index > 9) && field[player_index] != BLANK);
		field[player_index] = player_choice;

		do {
			ai_index = rand() % SIZE;
		} while (field[ai_index] != BLANK);
		field[ai_index] = ai_choice;

		int blankCount = 0;
		for (int i = 0; i < SIZE; i++) {
			if (field[i] == BLANK) {
				blankCount++;
			}
		}
		if (blankCount == 0) {
			break;
		}
	}
 	return 0;
}

void fill_array(int size, int arr[]) {
	for (int i = 0; i < size; i++) {
		arr[i] = BLANK;
	}
}

void print_field(int width, int size, int arr[]) {
	system("cls");
	printf("\n\t");
	for (int i = 0; i < size; i++) {
		switch (arr[i]) {
		case CROSSES:
			printf("[X]");
			break;
		case NOUGHTS:
			printf("[O]");
			break;
		default:
			printf("[%d]", i + 1);
			break;
		}
		if ((i + 1) % width == 0) {
			printf("\n\t");
		}
	}
}