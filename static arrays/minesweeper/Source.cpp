#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

enum Cells {
	OPENED_CELL,
	CLOSED_CELL
};

void print_field(int arr[], int size, int width, int height);
void gen_field(int arr[], int mineIndeces[], int size, int mineCount, int mine);
void check_around(int arr[], int index, int x, int y, int width, int mine);

int main(void) {
	srand(time(0));

	const int WIDTH = 3;
	const int HEIGHT = 3;
	const int SIZE = WIDTH * HEIGHT;

	int mine = -49;
	const int mineCount = SIZE / 10 + 1;

	int mineIndeces[mineCount] = { 0 };
	int field[SIZE] = { 0 };

	int x = 0;
	int y = 0;

	int index = 0;
	
	gen_field(field, mineIndeces, SIZE, mineCount, mine);
	print_field(field, SIZE, WIDTH, HEIGHT);

	while (1) {
		puts("\nType letter and number with space, please.");

  		scanf(" %c %d", &x, &y);
		
		x = x - 'a';
		y = y - 1;

		index = x + y * WIDTH;

		if (field[index] == mine) {
			mine = -1;
			for (int i = 0; i < mineCount; i++) {
				field[mineIndeces[i]] = mine;
			}
			system("cls");
			print_field(field, SIZE, WIDTH, HEIGHT);
			puts("You lost");
			break;
		}

		int closedCells = 0;

		for (int i = 0; i < SIZE; i++) {
			if (field[i] == -50) {
				closedCells++;
			}
		}

		if (closedCells == 1) {
			mine = -1;
			for (int i = 0; i < mineCount; i++) {
				field[mineIndeces[i]] = mine;
			}
			check_around(field, index, x, y, WIDTH, mine);
			system("cls");
			print_field(field, SIZE, WIDTH, HEIGHT);
			puts("You won !");
			break;
		}

		

		int tmp = 0;
		field[index] = 0;

		print_field(field, SIZE, WIDTH, HEIGHT);
		check_around(field, index, x, y, WIDTH, mine);
		system("cls");
		print_field(field, SIZE, WIDTH, HEIGHT);
	}
	return 0;
}

void check_around(int arr[], int index, int x, int y, int width, int mine) {
	int tmp = 0;
	if (arr[x - 1 + y * width] == mine) { // left
		if (x >= 0) {
			tmp++;
			arr[index] = tmp;
		}
	}
	if (arr[x + 1 + y * width] == mine) { // right
		tmp++;
		arr[index] = tmp;
	}
	if (arr[x + (y - 1) * width] == mine) { // down
		if (y - 1 >= 0) {
			tmp++;
			arr[index] = tmp;
		}
	}
	if (arr[x + (y + 1) * width] == mine) { // up
		tmp++;
		arr[index] = tmp;
	}
	if (arr[x + 1 + (y - 1) * width] == mine) {
		if (y - 1 >= 0) {
			tmp++;
			arr[index] = tmp;
		}
	}
	if (arr[x - 1 + (y - 1) * width] == mine) {
		if (y - 1 >= 0 && x - 1 >= 0) {
			tmp++;
			arr[index] = tmp;
		}
	}
	if (arr[x + 1 + (y + 1) * width] == mine) {
		tmp++;
		arr[index] = tmp;
	}
	if (arr[x - 1 + (y + 1) * width] == mine) {
		if (x - 1 >= 0) {
			tmp++;
			arr[index] = tmp;
		}
	}
}

void gen_field(int arr[], int mineIndeces[], int size, int mineCount, int mine) {
	int gen_rand = 0;
	for (int i = 0; i < size; i++) {
		arr[i] = -50;
	}
	for (int i = 0; i < mineCount; i++) {
		gen_rand = rand() % size;
		arr[gen_rand] = mine;
		mineIndeces[i] = gen_rand;
	}
}

void print_field(int arr[], int size, int width, int height) {
	printf("  ");
	for (int i = 0, xLetter = 'a'; i < width; i++, xLetter++) {
		printf(" %c ", xLetter);
	}
	printf("\n");
	int j = 1;
	printf("%d ", j);
	for (int i = 0; i < size; i++) {
		switch (arr[i]) {
		case -49:
		case -50:
			printf("[.]");
			break;
		case -1:
			printf("[X]");
			break;
		default:
			if (arr[i] >= 0 && arr[i] < 9) {
				printf("[%d]", arr[i]);
			}
			break;
		}
		if ((i + 1) % width == 0 && j < height)  {
			j++;
			printf("\n%d ", j);
		}
	}
	printf("\n");
}