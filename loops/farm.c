#include <stdio.h>

int main(void) {
  float balance = 100;
  int seeds = 0;
  const float WIN_BALANCE = 200;
  const int SEEDS_PRICE_TO_BUY = 20;
  const int SEEDS_PRICE_TO_SELL = 30;
  int amount_to_sell = 0;
  int amount_to_buy = 0;
  int growed_seeds = 0;
  char choice = ' ';

  puts("Welcome to the Farm.");

  while (choice != 'E' && choice != 'e') {
    if (balance >= WIN_BALANCE) {
        puts("Congratulations.You have won the game!");
        break;
      }
    puts("\nMenu:");
    puts("[B]uy seeds");
    puts("[G]arden");
    puts("[S]ell");
    puts("[E]xit\n");

    printf("Balance: %.2f $\n", balance);
    printf("Seeds: %d\n", seeds);
    printf("Seeds for sale: %d\n", growed_seeds); 
    scanf(" %c", &choice);  
    if (choice == 'B' || choice == 'b') {
      puts("Shop");
      puts("Seed - 20 $");
      puts("[B]uy");
      puts("[E]xit"); 
      scanf(" %c", &choice);

      if (choice == 'B' || choice == 'b') {
        puts("Enter amount:");
        scanf("%d", &amount_to_buy);  
        if (amount_to_buy <= 0 || balance - amount_to_buy * SEEDS_PRICE_TO_BUY < 0) {
          puts("Incorrect input.");
        }
        else {
          balance = balance - amount_to_buy * SEEDS_PRICE_TO_BUY;
          seeds = seeds + amount_to_buy;
        }
      }
      else if (choice == 'E' || choice == 'e') {
        continue;
      }
      else {
        puts("Incorrect input.");
      }
    }
    else if (choice == 'S' || choice == 's') {
      puts("Market");
      printf("You have: %d seeds for sale.\n", growed_seeds);
      puts("Sell price: 30$");
      puts("[S]ell");
      puts("[E]xit"); 
      scanf(" %c", &choice);

      if (choice == 'S' || choice == 's') {
        puts("Enter amount:");
        scanf("%d", &amount_to_sell);
          if (amount_to_sell > growed_seeds || amount_to_sell <= 0) {
            puts("Incorrect input.");
          }
          else {
            growed_seeds = growed_seeds - amount_to_sell;
            balance = balance + amount_to_sell * SEEDS_PRICE_TO_SELL;
          }
      }
      else if (choice == 'E' || choice == 'e') {
        continue;
      }
      else {
        puts("Incorrect input.");
      }
    }
    else if (choice == 'G' || choice == 'g') {
      puts("Garden");
      puts("[W]ater");
      puts("[G]ather");
      puts("[E]xit"); 
      scanf(" %c", &choice);

      if (choice == 'W' || choice == 'w') {
        printf("You have watered: %d seeds\n", seeds);
      }
      else if (choice == 'G' || choice == 'g') {
        growed_seeds = seeds + growed_seeds;
        seeds = 0;
        printf("You have gathered %d seeds.\n", growed_seeds);
      }
      else if (choice == 'E' || choice == 'e') {
        continue;
      }
      else {
        puts("Incorrect input.");
      }
    }
    else if (choice != 'e' && choice != 'E') {
        puts("Incorrect input.");
      }
  }
  return 0;
}