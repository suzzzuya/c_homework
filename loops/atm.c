#include <stdio.h>

int main(void) {
    float balance = 5000;
    const float LOAN = 1000;
    char user_input = ' ';
    float deposit_amount = 0;
    float withdraw_amount = 0;  
    puts("WELCOME TO THE BEST ATM\n");
    puts("MENU\n"); 
    while (user_input != 'e' && user_input != 'E') {
      puts("[D]eposit");
      puts("[W]ithdraw");
      puts("[B]alance");
      puts("[E]xit");
      scanf(" %c", &user_input);
    
      if (user_input == 'D' || user_input == 'd') {
        puts("Enter amount, please.");
        scanf("%f", &deposit_amount);
        printf("You have deposited %.2f $\n", deposit_amount);  
        if (deposit_amount <= 0) {
          puts("Wrong input.");
          }
        else {
          balance = deposit_amount + balance;
          }
        }
      else if (user_input == 'W' || user_input == 'w') {
        puts("Enter amount to withdraw, please.");
        scanf("%f", &withdraw_amount);
        printf("You have withdrawn %.2f $\n", withdraw_amount); 
        if (withdraw_amount <= 0 || withdraw_amount > balance + LOAN) {
          puts("Wrong input.");
          }
        else {
          balance = balance - withdraw_amount;
          }
        }
      else if (user_input == 'B' || user_input == 'b') {
        if (balance < 0) {
          printf("Loan: %.2f\n", -balance);
        }
        else {
          printf("Balance: %.2f\n", balance);
        }
      }
    }
  return 0;
}