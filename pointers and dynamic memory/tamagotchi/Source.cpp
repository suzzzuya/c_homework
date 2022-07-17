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
	for (;pet.health > 0;) {
		system("cls");
		puts("\tTamagotchi");
		puts("watch your pet's life-necessary bars !\n");
		puts("\tMENU\n");
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
		system("cls");
	}
}

void view_status(Pet * pet) {
	printf("Health: %.2f\nSatiety: %.2f\nPoop level: %.2f\n", pet->health, pet->satiety, pet->poopLevel);

	printf("\n");
	if (pet->health < 100 || pet->satiety <= 50 || pet->poopLevel >= 75) {
		puts("\tWARNINGS");
	}
	if (pet->health < 100) {
		puts("Your pet is losing your health ! Give your pet a pill !");
	}
	if (pet->satiety <= 50) {
		puts("Your pet is hungry ! Give your pet a treat !");
	}
	if (pet->poopLevel >= 75) {
		puts("Your pet wants to poop ! Clean up after it !");
	}
	time(0);
}

void feed_pet(Pet * pet, bool * hasEaten) {
	if (pet->satiety >= 100) {
		puts("pet doesn't want to eat");
		pet->satiety = maxSatietyValue;
	} else if (pet->satiety >= 0 && pet->satiety < 100) {
		printf("You have fed your pet !\n");
		puts("+25 to satiety");
		pet->satiety += 25;
		*hasEaten = true;
		if (pet->satiety >= 100) {
			pet->satiety = maxSatietyValue;
		}
	} else {
		pet->satiety = 0;
	}
	
}

void clean_poop(Pet * pet, bool * hasEaten) {
	if (pet->poopLevel >= 100) {
		pet->poopLevel = maxPoopLevel;
	}
	else if (pet->poopLevel > 0 && pet->poopLevel <= 100) {
		printf("You have cleaned up after your pet !\n");
		puts("now poop level is 0");
		*hasEaten = false;
		pet->poopLevel = 0;
	} else {
		puts("pet doesn't want to poop");
	}
}

void give_pill(Pet * pet) {
	if (pet->health >= 100) {
		puts("max health has been reached");
		pet->health = maxHealthValue;
	} else {
		printf("You gave your pet a pill !\n");
		puts("+30 to health");
		pet->health += 30;
		if (pet->health >= 100) {
			pet->health = maxHealthValue;
		} 
	}
}

void refresh_status(Pet* pet, int *lastActionTime, bool * hasEaten) {
	int timeDiff = 0;
	timeDiff = (time(0) - *lastActionTime) + 1;

	// satiety increase

	if (pet->satiety <= 0) {
		pet->satiety = 0;
	} else {
		pet->satiety -= float(timeDiff * 1.5);
	}

	// poop increase

	if (pet->poopLevel >= maxPoopLevel) {
		pet->poopLevel = 100;
	} else if (*hasEaten) {
		pet->poopLevel += float(timeDiff * 1.7);
	}

	// hp loss

	if (pet->satiety <= 0) {
		pet->health -= float(timeDiff * 4);
	}
	if (pet->poopLevel >= 100) {
		pet->health -= float(timeDiff * 4);
	}
}