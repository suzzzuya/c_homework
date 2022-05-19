#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void print_result(int ai[], int player[], int size, int user_score, int ai_score);
void check_result(int ai[], int player[], int index, int user_score, int ai_score);

int main() {
    srand(time(0) / 4 * 69);

    puts("Welcome to ROCK-PAPER-SCISSORS\n");

    const int MAX_SCORE = 5;
    int index = 0;
    int player[100] = { 0 };
    int ai[100] = { 0 };

    int user_score = 0;
    int ai_score = 0;

    while (user_score < MAX_SCORE && ai_score < MAX_SCORE) {
        puts("[R]ock"); // 1
        puts("[P]aper"); // 2
        puts("[S]cissors"); // 3

        char user_move_char = ' ';
        int user_move_int = 0;
        scanf(" %c", &user_move_char);

        int ai_move = rand() % 3 + 1; // random number [1 - 3]

        switch (user_move_char) {
        case 'R':
        case 'r':
            user_move_int = 1;
            break;
        case 'P':
        case 'p':
            user_move_int = 2;
            break;
        case 'S':
        case 's':
            user_move_int = 3;
        default:
            puts("Incorrect input.");
            break;
        }

        player[index] = user_move_int;

        switch (ai_move) {
            case 1:
               puts("AI chose: Rock");
               break;
            case 2:
                puts("AI chose: Paper");
                break;
            case 3:
                puts("AI chose: Scissors");
                break;
            default:
                break;
        }

        ai[index] = ai_move;

        index++;
        if (user_move_int == ai_move) {
            puts("DRAW!");
        } else if ((ai_move == 1 && user_move_int == 2) ||
            (ai_move == 2 && user_move_int == 3) ||
            (ai_move == 3 && user_move_int == 1)) {
            puts("You WINNER!");
            user_score++;
        } else {
            ai_score++;
            puts("You LOSER!\n");
        }
        printf("Your score: %d\tEnemy score: %d\n", user_score, ai_score);
    }
    print_result(ai, player, index, user_score, ai_score);
    return 0;
}

void check_result(int ai[], int player[], int index, int user_score, int ai_score) {
    if (player[index] == ai[index]) {
        puts("DRAW!");
    } else if ((ai[index] == 'R' || ai[index] == 'r' && player[index] == 'P' || player[index] == 'p') ||
        (ai[index] == 'P' || ai[index] == 'p' && player[index] == 'S' || player[index] == 's') ||
        (ai[index] == 'S' || ai[index] == 's' && player[index] == 'R' || player[index] == 'r')) {
        user_score++;
        puts("You WINNER!");
    } else {
        ai_score++;
        puts("You LOSER!\n");
    }
}

void print_result(int ai[], int player[], int size, int user_score, int ai_score) {
    printf("\n");
    puts("\tResults\n");
    for (int i = 0; i < size; i++) {
        printf("\tRound %d \n", i + 1);

        switch (player[i]) {
        case 1:
            printf("Player chose: ROCK");
            break;
        case 2:
            printf("Player chose: PAPER");
            break;
        case 3:
            printf("Player chose: SCISSORS");
            break;
        default:
            break;
        }
        printf("\n");
        switch (ai[i]) {
            case 1:
                printf("AI chose: ROCK");
                break;
            case 2:
                printf("AI chose: PAPER");
                break;
            case 3:
                printf("AI chose: SCISSORS");
                break;
            default:
                break;
        } 
        printf("\n");
        check_result(player, ai, i, user_score, ai_score);
    }
    puts("\tOverall points");
    printf("PLAYER: %d\n", user_score);
    printf("AI: %d\n", ai_score);

    if (user_score > ai_score) {
        puts("\tYOU WON THE GAME !");
    } else {
        puts("\tYOU LOST THE GAME !");
    }
}