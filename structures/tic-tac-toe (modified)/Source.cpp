#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

enum Cells {
	CROSSES = 1,
	ZEROES = -1,
	BLANK = 0
};

struct Move {
	Cells choice;
	int cell;
};

void fill_array(int size, int field[]);
void print_field(int side, int size, int field[]);
void player_move(int index, Cells choice, Move history[], int moveNumber);
int check_win_condition(int side, int field[]);
void print_history(int size, int field[], Move history[], int moveNumber);

const int SIDE = 3;
const int SIZE = SIDE * SIDE;


Move history[SIZE] = { BLANK, 0 };
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

	Cells player_choice = CROSSES;
	Cells ai_choice = ZEROES;

	printf("\n");
	int moveNumber = 0;
	for (;moveNumber < SIZE;) {
		print_field(SIDE, SIZE, field);

		int player_index = -1;
		int ai_index = -1;

		if (moveNumber % 2 == 0) {
			puts("Now it's crosses turn");
			player_move(player_index, player_choice, history, moveNumber);
			moveNumber++;
		} else {
			switch (gameModeChoice) {
			case 1:
				puts("\nNow it's zeroes turn");
				player_move(player_index, ai_choice, history, moveNumber);
				moveNumber++;
				break;
			case 2:
				puts("\nNow it's zeroes turn");
				do {
					ai_index = rand() % SIZE;
				} while (field[ai_index] != BLANK);
				field[ai_index] = ai_choice;
				moveNumber++;
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
		if (moveNumber == SIZE - 1) {
			print_field(SIDE, SIZE, field);
			puts("\n\tDRAW !");
			break;
		}
	}
	printf("\n");
	puts("\tHISTORY\n");
	print_history(SIZE, field, history, moveNumber);
	return 0;
}

void print_history(int size, int field[], Move history[], int moveNumber) {
	for (int i = 0; i < size; i++) {
		switch (history[i].choice) {
			case CROSSES:
				printf("Move %d: Crosses moved to cell %d\n", i + 1, history[i].cell + 1);
				break;
			case ZEROES:
				printf("Move %d: Zeroes moved to cell %d\n", i + 1, history[i].cell + 1);
				break;
			default:
				break;
		}
	}
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

void player_move(int index, Cells choice, Move history[], int moveNumber) {
	do {
		scanf("%d", &index);
		index = index - 1;
	} while ((index < 1 || index > 9) && field[index] != BLANK);
	field[index] = choice;
	history[moveNumber].cell = index;
	history[moveNumber].choice = choice;
}

void fill_array(int size, int field[]) {
	for (int i = 0; i < size; i++) {
		field[i] = BLANK;
	}
}

void print_field(int side, int size, int field[]) {
	system("cls");
	printf("\n\t");
	for (int i = 0; i < size; i++) {
		switch (field[i]) {
		case CROSSES:
			printf("[X]");
			break;
		case ZEROES:
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