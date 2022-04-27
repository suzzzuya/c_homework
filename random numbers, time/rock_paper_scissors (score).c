#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(0) / 4 * 69);
    
    int ai_score = 0;
    int user_score = 0;
    puts("Welcome to ROCK-PAPER-SCISSORS\n");

    while (ai_score != 5 && user_score != 5) {
        puts("[R]ock"); // 1
        puts("[P]aper"); // 2
        puts("[S]cissors"); // 3

        char user_move_char = ' ';
        int user_move_int = 0;
        
    
        scanf(" %c", &user_move_char);
        printf("\n\n\n");
        if (user_move_char == 'R' || user_move_char == 'r') {
            int ai_move = rand() % 3 + 1; // random number [1 - 3]
            user_move_int = 1; // ROCK
            
            if (user_move_int == ai_move) {
                puts("DRAW!");
                printf("Your score: %d\nAI score: %d\n\n", user_score, ai_score);
            } else if (ai_move == 2) {
                puts("AI chose: PAPER");
                puts("You LOSER!");
                ai_score++;
                printf("Your score: %d\nAI score: %d\n\n", user_score, ai_score);
            } else {
                puts("AI chose: Scissors");
                puts("You WINNER!");
                user_score++;
                printf("Your score: %d\nAI score: %d\n\n", user_score, ai_score);
            }
        } else if (user_move_char == 'P' || user_move_char == 'p') {
            int ai_move = rand() % 3 + 1; // random number [1 - 3]
            user_move_int = 2; // PAPER

            if (user_move_int == ai_move) {
                puts("DRAW!");
                printf("Your score: %d\nAI score: %d\n\n", user_score, ai_score);
            } else if (ai_move == 1) {
                puts("AI chose: ROCK");
                puts("You WINNER!");
                user_score++;
                printf("Your score: %d\nAI score: %d\n\n", user_score, ai_score);
            } else {
                puts("AI chose: Scissors");
                puts("You LOST!");
                ai_score++;
                printf("Your score: %d\nAI score: %d\n\n", user_score, ai_score);
            }
        } else if (user_move_char == 'S' || user_move_char == 's') {
            int ai_move = rand() % 3 + 1; // random number [1 - 3]
            user_move_int = 3; // SCISSORS

            if (user_move_int == ai_move) {
                puts("DRAW!");
                printf("Your score: %d\nAI score: %d\n\n", user_score, ai_score);
            } else if (ai_move == 2) {
                puts("AI chose: Paper");
                puts("You WINNER!");
                user_score++;
                printf("Your score: %d\nAI score: %d\n\n", user_score, ai_score);
            } else {
                puts("AI chose: ROCK");
                puts("You LOSER!");
                ai_score++;
                printf("Your score: %d\nAI score: %d\n\n", user_score, ai_score);
            }
        } else {
            puts("Incorrect input");
            printf("Your score: %d\nAI score: %d\n\n", user_score, ai_score);
        }
    }

    if (user_score == 5) {
        puts("\n\nYou won the game!");
    } else {
        puts("\n\nYou lost the game!");
    }
    return 0;
}
