#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Pet {
	float health;
	float satiety;
	float poopLevel;
};

const int maxHealthValue = 100;
const int maxSatietyValue = 100;
const int maxPoopLevel = 100;

Pet pet{ maxHealthValue, maxSatietyValue, 0 };

int lastActionTime = 0;

bool hasEaten = false;

void go_back_button(char menu_input);
void view_status(Pet * pet);
void feed_pet(Pet * pet, bool * hasEaten);
void clean_poop(Pet * pet, bool * hasEaten);
void give_pill(Pet * pet);
void refresh_status(Pet * pet, int *lastActionTime, bool * hasEaten);

int main(void) {
	puts("\tTamagotchi\n");
	for (;pet.health > 0;) {
		system("cls");
		puts("MENU\n");
		puts("[V]iew status");
		puts("[F]eed pet");
		puts("[C]lean up poop");
		puts("[G]ive pill");
		printf("\n");

		char menu_input = 0;
		scanf(" %c", &menu_input);

		switch (menu_input) {
		case 'V':
		case 'v':
			system("cls");
			lastActionTime = time(0);
			view_status(&pet);
			go_back_button(menu_input);

			refresh_status(&pet, &lastActionTime, &hasEaten);
			break;
		case 'F':
		case 'f':
			system("cls");
			lastActionTime = time(0);
			feed_pet(&pet, &hasEaten);
			go_back_button(menu_input);

			refresh_status(&pet, &lastActionTime, &hasEaten);
			break;
		case 'C':
		case 'c':
			system("cls");
			lastActionTime = time(0);
			clean_poop(&pet, &hasEaten);
			go_back_button(menu_input);

			refresh_status(&pet, &lastActionTime, &hasEaten);
			break;
		case 'G':
		case 'g':
			system("cls");
			lastActionTime = time(0);
			give_pill(&pet);
			go_back_button(menu_input); 

			refresh_status(&pet, &lastActionTime, &hasEaten);
			break;
		default:
			system("cls");
			break;
		}
	}
	pet.health = 0;
	system("cls");
	view_status(&pet);
	printf("\n");
	puts("your pet has died.. my deepest sympathies");
	system("pause");
	return 0;
}

void go_back_button(char menu_input) {
	while (menu_input != 'B' && menu_input != 'b') {
		printf("\n[B]ack\n");
		scanf(" %c", &menu_input);
	}
}

void view_status(Pet * pet) {
	printf("Health: %.2f\nSatiety: %.2f\nPoop level: %.2f", pet->health, pet->satiety, pet->poopLevel);
	printf("\n");
	time(0);
}

void feed_pet(Pet * pet, bool * hasEaten) {
	printf("You have fed your pet !\n");
	puts("+20 to satiety");
	pet->satiety += 30;
	if (pet->satiety >= 100) {
		pet->satiety = maxSatietyValue;
	}
	*hasEaten = true;
}

void clean_poop(Pet * pet, bool * hasEaten) {
	printf("You have cleaned up after your pet !\n");
	puts("poop need restored");
	pet->poopLevel = 0;
	*hasEaten = false;
}

void give_pill(Pet * pet) {
	printf("You gave your pet a pill !\n");
	puts("+30 to health");
	pet->health += 30;
	if (pet->health >= 100) {
		pet->health = maxHealthValue;
	}
}

void refresh_status(Pet* pet, int *lastActionTime, bool * hasEaten) {
	int timeDiff = 0;
	timeDiff = (time(0) - *lastActionTime);
	if (pet->satiety <= 0) {
		pet->satiety = 0;
	} else {
		pet->satiety -= float(timeDiff * 2.2);
	}
	if (pet->poopLevel >= maxPoopLevel) {
		pet->poopLevel = 100;
	} else if (*hasEaten) {
		pet->poopLevel += float(timeDiff * 1.7);
	}
	if (pet->satiety <= 0) {
		pet->health -= float(timeDiff * 5);
	}
}