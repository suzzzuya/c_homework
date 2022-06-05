#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

enum Cells {
	CROSSES = 1,
	NOUGHTS = -1,
	BLANK = 0
};

void fill_array(int size, int arr[]);
void print_field(int side, int size, int arr[]);
void player_move(int index, int choice);
int check_win_condition(int side, int arr[]);

const int SIDE = 3;
const int SIZE = SIDE * SIDE;

int field[SIZE] = { 0 };

int main(void) {
	srand(time(0));

	fill_array(SIZE, field);

	printf("\tWelcome to TIC-TAC-TOES\n");

	int gameModeChoice = 0;

	while (gameModeChoice < 1 || gameModeChoice > 2) {
		puts("\n\tCHOOSE YOUR GAME MODE");
		puts("[1]Player vs Player\n[2]Player vs AI\n\n");
		scanf("%d", &gameModeChoice);
	}

	int player_choice = CROSSES;
	int ai_choice = NOUGHTS;

	printf("\n");

	for (int i = 0; i < SIZE; i++) {
		print_field(SIDE, SIZE, field);

		int player_index = -1;
		int ai_index = -1;

		if (i % 2 == 0) {
			puts("Now it's crosses turn");
			player_move(player_index, player_choice);
		}
		else {
			switch (gameModeChoice) {
			case 1:
				puts("Now it's zeroes turn");
				player_move(player_index, ai_choice);	
				break;
			case 2:
				puts("Now it's zeroes turn");
				do {
					ai_index = rand() % SIZE;
				} while (field[ai_index] != BLANK);
				field[ai_index] = ai_choice;
				break;
			default:
				break;
			}
		}
		print_field(SIDE, SIZE, field);

		if (check_win_condition(SIDE, field) == -3) {
			print_field(SIDE, SIZE, field);
			puts("\n\tZEROES WON !");
			break;
		} else if (check_win_condition(SIDE, field) == 3) {
			print_field(SIDE, SIZE, field);
			puts("\n\tCROSSES WON !");
			break;
		}
		if (i == SIZE - 1) {
			print_field(SIDE, SIZE, field);
			puts("\n\tDRAW !");
			break;
		}
	}
 	return 0;
}

int check_win_condition(int side, int arr[]) {
	int sum = 0;
	for (int y = 0; y < side; y++) { // horizontal
		for (int x = 0; x < side; x++) {
			sum += arr[y * side + x];
		}
		if (sum == 3 || sum == -3) {
			return sum;
		}
		sum = 0;
	}
	for (int x = 0; x < side; x++) { // vertical
		for (int y = 0; y < side; y++) {
			sum += arr[y * side + x];
		}
		if (sum == 3 || sum == -3) {
			return sum;
		}
		sum = 0;
	}
	for (int x = 0, y = 0; x < side; x++, y++) { // diagonal
		sum += arr[y * side + x];
		if (sum == 3 || sum == -3) {
			return sum;
		}
	}
	sum = 0;
	for (int x = side - 1, y = 0; y < side; x--, y++) { // diagonal
		sum += arr[y * side + x];
		if (sum == 3 || sum == -3) {
			return sum;
		}
	}
	sum = 0;
	return 0;
}

void player_move(int index, int choice) {
	do {
		scanf("%d", &index);
		index = index - 1;
	} while ((index < 1 || index > 9) && field[index] != BLANK);
	field[index] = choice;
}

void fill_array(int size, int arr[]) {
	for (int i = 0; i < size; i++) {
		arr[i] = BLANK;
	}
}

void print_field(int side, int size, int arr[]) {
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
		if ((i + 1) % side == 0) {
			printf("\n\t");
		}
	}
}