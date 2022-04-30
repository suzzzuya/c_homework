#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(0) / 4 * 69);
    
    puts("Welcome to ROCK-PAPER-SCISSORS\n");

    int user_score = 0;
    int ai_score = 0;

    while (user_score < 6 && ai_score < 6) {
        puts("[R]ock"); // 1
        puts("[P]aper"); // 2
        puts("[S]cissors"); // 3

        char user_move_char = ' ';
        int user_move_int = 0;
        scanf(" %c", &user_move_char);

        int ai_move = rand() % 3 + 1; // random number [1 - 3]
        
        if (user_move_char == 'R' || user_move_char == 'r') {
            user_move_int = 1; // ROCK
        } else if (user_move_char == 'P' || user_move_char == 'p') {
            user_move_int = 2; // PAPER
        } else if (user_move_char == 'S' || user_move_char == 's') {
            user_move_int = 3; // SCISSORS
        } else {
            puts("Incorrect input, you LOSER!");
        }

        if (ai_move == 1){
            puts("AI chose: Rock");
        } else if (ai_move == 2) {
            puts("AI chose: Paper");
        } else if (ai_move == 3) {
            puts("AI chose: Scissors");
        } else {
            // error
        }

        if (user_move_int == ai_move) {
            puts("DRAW!");
        } else if ((ai_move == 1 && user_move_int == 2) || 
            (ai_move == 2 && user_move_int == 3) || 
            (ai_move == 3 && user_move_int == 1) ) {
            puts("You WINNER!");
            user_score++;
        } else {
            ai_score++;
            puts("You LOSER!");
        }
        printf("Your score: %d\tEnemy score: %d\n", user_score, ai_score);
    }
    return 0;
}
