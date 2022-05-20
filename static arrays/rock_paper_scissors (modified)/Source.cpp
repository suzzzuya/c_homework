#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

enum Move {
    ROCK,
    PAPER,
    SCISSORS
};

enum Result {
    PLAYER_WON,
    AI_WON,
    DRAW
};

void print_result(int ai[], int player[], int size, int player_score, int ai_score);
Result check(int player_move, int ai_move);

int main() {
    srand(time(0));

    puts("Welcome to ROCK-PAPER-SCISSORS");

    const int MAX_SCORE = 5;
    int length = 0;
    int player[100] = { 0 };
    int ai[100] = { 0 };

    int player_score = 0;
    int ai_score = 0;

    while (player_score < MAX_SCORE && ai_score < MAX_SCORE) {
        printf("\n");
        puts("[R]ock");
        puts("[P]aper");
        puts("[S]cissors");

        char player_move_char = ' ';
        int player_move = 0;
        scanf(" %c", &player_move_char);

        int ai_move = rand() % 3 + 1; // random number [1 - 3]

        printf("\n");

        switch (player_move_char) {
        case 'R':
        case 'r':
            player_move = ROCK;
            puts("PLAYER chose: ROCK");
            break;
        case 'P':
        case 'p':
            player_move = PAPER;
            puts("PLAYER chose: PAPER");
            break;
        case 'S':
        case 's':
            player_move = SCISSORS;
            puts("PLAYER chose: SCISSORS");
            break;
        default:
            puts("Incorrect input.");
            break;
        }

        switch (ai_move) {
        case 1:
            ai_move = ROCK;
            puts("AI chose: ROCK");
            break;
        case 2:
            ai_move = PAPER;
            puts("AI chose: PAPER");
            break;
        case 3:
            ai_move = SCISSORS;
            puts("AI chose: SCISSORS");
            break;
        }

        switch (check(player_move, ai_move)) {
        case DRAW:
            puts("DRAW");
            break;
        case PLAYER_WON:
            puts("You won !");
            player_score++;
            break;
        case AI_WON:
            puts("You lost !");
            ai_score++;
            break;
        }

        player[length] = player_move;
        ai[length] = ai_move;

        length++;

        printf("Your score: %d\tEnemy score: %d\n", player_score, ai_score);
    }
    print_result(ai, player, length, player_score, ai_score);
    return 0;
}

enum Result check(int player_move, int ai_move) {
    if (player_move == ai_move) {
        return DRAW;
    }
    if ((ai_move == ROCK && player_move == PAPER) ||
        (ai_move == PAPER && player_move == SCISSORS) ||
        (ai_move == SCISSORS && player_move == ROCK)) {
        return PLAYER_WON;
    } else {
        return AI_WON;
    }
}

void print_result(int ai[], int player[], int size, int player_score, int ai_score) {
    printf("\n");
    puts("\tResults\n");
    for (int i = 0; i < size; i++) {
        printf("\tRound %d \n", i + 1);

        switch (player[i]) {
        case ROCK:
            puts("Player chose: ROCK");
            break;
        case PAPER:
            puts("Player chose: PAPER");
            break;
        case SCISSORS:
            puts("Player chose: SCISSORS");
            break;
        default:
            break;
        }
        switch (ai[i]) {
        case ROCK:
            puts("AI chose: ROCK");
            break;
        case PAPER:
            puts("AI chose: PAPER");
            break;
        case SCISSORS:
            puts("AI chose: SCISSORS");
            break;
        default:
            break;
        }
        switch (check(player[i], ai[i])) {
        case DRAW:
            puts("\tDRAW");
            break;
        case PLAYER_WON:
            puts("\tYou won !");
            break;
        case AI_WON:
            puts("\tYou lost !");
            break;
        }
        printf("\n");
    }
    puts("\tOverall points");
    printf("PLAYER: %d\n", player_score);
    printf("AI: %d", ai_score);

    if (player_score > ai_score) {
        puts("\tYOU WON THE GAME !");
    } else {
        puts("\tYOU LOST THE GAME !");
    }
}