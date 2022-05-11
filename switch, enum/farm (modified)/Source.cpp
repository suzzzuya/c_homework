#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

void print_main_menu(float balance, int seeds, int grown_seeds);
void print_shop_menu();
void print_market_menu(int grown_seeds);
void print_garden_menu();

int main(void) {
    const float WIN_BALANCE = 200;
    const int SEEDS_PRICE_TO_BUY = 20;
    const int SEEDS_PRICE_TO_SELL = 30;
    float balance = 100;
    int seeds = 0;
    int amount_to_sell = 0;
    int amount_to_buy = 0;
    int grown_seeds = 0;
    char choice = ' ';

    puts("Welcome to the Farm.");

    while (choice != 'E' && choice != 'e') {
        if (balance >= WIN_BALANCE) {
            puts("Congratulations.You have won the game!");
            break;
        }
        print_main_menu(balance, seeds, grown_seeds);
        scanf(" %c", &choice);

        switch (choice) {
        case 'B':
        case 'b':
            print_shop_menu();
            scanf(" %c", &choice);
            if (choice == 'B' || choice == 'b') {
                puts("Enter amount:");
                scanf("%d", &amount_to_buy);
                if (amount_to_buy <= 0 || balance - amount_to_buy * SEEDS_PRICE_TO_BUY < 0) {
                    puts("Incorrect input.");
                    continue;
                } else {
                    balance = balance - amount_to_buy * SEEDS_PRICE_TO_BUY;
                    seeds = seeds + amount_to_buy;
                    continue;
                }
                break;
        case 'S':
        case 's':
            print_market_menu(grown_seeds);
            scanf(" %c", &choice);
            if (choice == 'S' || choice == 's') {
                puts("Enter amount:");
                scanf("%d", &amount_to_sell);
                if (amount_to_sell > grown_seeds || amount_to_sell <= 0) {
                    puts("Incorrect input.");
                    continue;
                } else {
                    grown_seeds = grown_seeds - amount_to_sell;
                    balance = balance + amount_to_sell * SEEDS_PRICE_TO_SELL;
                    continue;
                }
            } else if (choice == 'E' || choice == 'e') {
                continue;
            } else {
                puts("Incorrect input.");
                continue;
            }
            break;
        case 'G':
        case 'g':
            print_garden_menu();
            scanf(" %c", &choice);
            if (choice == 'W' || choice == 'w') {
                printf("You have watered: %d seeds\n", seeds);
                continue;
            } else if (choice == 'G' || choice == 'g') {
                grown_seeds = seeds + grown_seeds;
                seeds = 0;
                printf("You have gathered %d seeds.\n", grown_seeds);
                continue;
            } else if (choice == 'E' || choice == 'e') {
                continue;
            } else {
                puts("Incorrect input.");
                continue;
            }
            break;
        case 'E':
        case 'e':
            break;
        default:
            puts("Incorrect input.");
            continue;
            break;
            }
        }
        return 0;
    }
}

void print_main_menu(float balance, int seeds, int grown_seeds) {
    puts("\nMenu:");
    puts("[B]uy seeds");
    puts("[G]arden");
    puts("[S]ell");
    puts("[E]xit\n");

    printf("Balance: %.2f $\n", balance);
    printf("Seeds: %d\n", seeds);
    printf("Seeds for sale: %d\n", grown_seeds);
}

void print_shop_menu() {
    puts("Shop");
    puts("Seed - 20 $");
    puts("[B]uy");
    puts("[E]xit");
}

void print_market_menu(int grown_seeds) {
    puts("Market");
    printf("You have: %d seeds for sale.\n", grown_seeds);
    puts("Sell price: 30$");
    puts("[S]ell");
    puts("[E]xit");
}

void print_garden_menu() {
    puts("Garden");
    puts("[W]ater");
    puts("[G]ather");
    puts("[E]xit");
}