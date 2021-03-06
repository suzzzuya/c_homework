#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

void print_menu();

int main(void) {
    float balance = 5000;
    const float LOAN = 1000;
    char user_input = ' ';
    float deposit_amount = 0;
    float withdraw_amount = 0;

    puts("WELCOME TO THE BEST ATM\n");

    while (user_input != 'e' && user_input != 'E') {
        print_menu();
        scanf(" %c", &user_input);

        switch (user_input) {
            case 'D':
            case 'd':
                puts("Enter amount, please.");
                scanf(" %f", &deposit_amount);
                if (deposit_amount <= 0) {
                    puts("Wrong input.");
                } else {
                    printf("You have deposited %.2f $\n", deposit_amount);
                    balance = deposit_amount + balance;
                }
                break;
            case 'W':
            case 'w':
                puts("Enter amount to withdraw, please.");
                scanf("%f", &withdraw_amount);
                printf("You have withdrawn %.2f $\n", withdraw_amount);
                if (withdraw_amount <= 0 || withdraw_amount > balance + LOAN) {
                    puts("Wrong input.");
                } else {
                    balance = balance - withdraw_amount;
                }
                break;
            case 'B':
            case 'b':
                if (balance < 0) {
                    printf("Loan: %.2f\n", -balance);
                } else {
                    printf("Balance: %.2f\n", balance);
                }
                break;
        }
    }
    return 0;
}

void print_menu() {
    puts("MENU\n");
    puts("[D]eposit");
    puts("[W]ithdraw");
    puts("[B]alance");
    puts("[E]xit");
}