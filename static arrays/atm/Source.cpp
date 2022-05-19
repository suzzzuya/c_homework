#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

void print_menu();
void print_logs(float arr[], int size);

int main(void) {
    float balance = 5000;
    const float LOAN = 1000;

    char user_input = ' ';

    float deposit_amount = 0;
    float withdraw_amount = 0;

    const int LOGS_SIZE = 10;
    int index = 0;
    float logs_array[LOGS_SIZE] = { 0 };

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
                logs_array[index] = deposit_amount;
                if (index > 10) {
                    for (int i = 1; i < LOGS_SIZE; i++) {
                        logs_array[i - 1] = logs_array[i];
                    }
                } else {
                    index++;
                }
            }
            break;
        case 'W':
        case 'w':
            puts("Enter amount to withdraw, please.");
            scanf("%f", &withdraw_amount);
            if (withdraw_amount <= 0 || withdraw_amount > balance + LOAN) {
                puts("Wrong input.");
            } else {
                printf("You have withdrawn %.2f $\n", withdraw_amount);
                balance = balance - withdraw_amount;
                logs_array[index] = -withdraw_amount;
                if (index > 10) {
                    for (int i = 1; i < LOGS_SIZE; i++) {
                        logs_array[i - 1] = logs_array[i];
                    }
                } else {
                    index++;
                }
            }
            break;
        case 'L':
        case 'l':
            print_logs(logs_array, LOGS_SIZE);
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
    puts("[L]ogs");
    puts("[E]xit");
}

void print_logs(float arr[], int size) {
    puts("LOGS\n");
    for (int i = 0; i < size && arr[i] != 0; i++) {
        if (arr[i] < 0) {
            printf("Withdrawn: %.2f $\n", arr[i]);
        } else if (arr[i] > 0) {
            printf("Deposited: %.2f $\n", arr[i]);
        } else {
            puts("ERROR");
        }
    } printf("\n");
}