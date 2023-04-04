#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

#define PAPER 1
#define ROCK 2
#define SCISSORS 3
int PLAYER_RESULT;
int RESULT_OF_THE_PROGRAM;
int TIE;
int NUMBER_ROUNDS;



void game_rules(){
    printf("-----------------------------------------------------------------------------------------------------------------------------------\n");
    printf("|                                            *HI WELCOME TO THE GAME*                                                             |\n");
    printf("|                                               RULES OF THE GAME:                                                                |\n");
    printf("| 1. THE GAME IS PLAYED AS YOU ENTER A SEQUENTIAL NUMBER OF MOVES                                                                 |\n");
    printf("| 2. IF YOU WANT TO END THE GAME, ENTER ZERO OR ANY NEGATIVE NUMBER                                                               |\n");
    printf("| 3. GAME RESULTS LOSE THE DRIVE TO SHUT DOWN/EXIT THE GAME                                                                       |\n");
    printf("| 4. DO NOT ENTER LETTERS INSTEAD OF SEQUENTIAL NUMBERS (BUG THAT OUR DEV. TEAM CANNOT SOLVE FOR NOW BUT WE ARE WORKING ON IT)    |\n");
    printf("|                                                                                                                                 |\n");
    printf("|                                       !!!    ENJOY PLAYING   !!!                                                                |\n");
    printf("-----------------------------------------------------------------------------------------------------------------------------------\n");
}

void paper(){
    printf("\n         PAPER\n");
    printf("       ______\n");
    printf("______/   ___)___\n");
    printf("            _____)_\n");
    printf("            _______)\n");
    printf("______    ________)\n");
    printf("      \\________)\n");
}

void rock(){
    printf("\n         ROCK\n");
    printf("       ______\n");
    printf("______/   ___)__\n");
    printf("          (_____)\n");
    printf("          (_____)\n");
    printf("______    (_____)\n");
    printf("      \\___(_____)\n");
}

void scissors(){
    printf("\n         SCISSORS\n");
    printf("       ______\n");
    printf("______/   ___)______\n");
    printf("            ________)_\n");
    printf("           ___________)\n");
    printf("______    (_____)\n");
    printf("      \\__(____)\n");
}

int move(){
    return rand() % (3 - 1 + 1) + 1;
}

void moves(int *input, int *program){

    if(*input == PAPER && *program == PAPER) {
        paper(); //Player
        paper(); //Program
        printf("\n\n\tIT'S A TIE\n");
        TIE++;
    }

    if(*input == ROCK && *program == ROCK) {
        rock(); //Player
        rock(); //Program
        printf("\n\n\tIT'S A TIE\n");
        TIE++;
    }

    if(*input == SCISSORS && *program == SCISSORS) {
        scissors(); //Player
        scissors(); //Program
        printf("\n\n\tIT'S A TIE\n");
        TIE++;
    }

    if(*input == PAPER && *program == SCISSORS) {
        paper();    //Player
        scissors(); //Program
        printf("\n\n\tYOU LOST\n");
        RESULT_OF_THE_PROGRAM++;
    }

    if(*input == PAPER && *program == ROCK) {
        paper(); //Player
        rock();  //Program
        printf("\n\n\tYOU WIN\n");
        PLAYER_RESULT++;
    }

    if(*input == ROCK && *program == PAPER) {
        rock();  //Player
        paper(); //Program
        printf("\n\n\tYOU LOST\n");
        RESULT_OF_THE_PROGRAM++;
    }

    if(*input == ROCK && *program == SCISSORS) {
        rock();     //Player
        scissors(); //Program
        printf("\n\n\tYOU WIN\n");
        PLAYER_RESULT++;
    }

    if(*input == SCISSORS && *program == PAPER) {
        scissors();   //Player
        paper();      //Program
        printf("\n\n\tYOU WIN\n");
        PLAYER_RESULT++;
    }

    if(*input == SCISSORS && *program == ROCK) {
        scissors();   //Player
        rock();       //Program
        printf("\n\n\tYOU LOST\n");
        RESULT_OF_THE_PROGRAM++;
    }  
}

void results(){
    printf("----------------------------------------------------------------------------------------------------------\n");
    printf("|                                        *GAME RESULTS:*                                                 |\n");
    printf("|                                   YOU PLAYED %d ROUNDS AND THIS IS THE RESULT:                          |\n", NUMBER_ROUNDS);
    printf("|                                             WIN:  %d                                                    |\n", PLAYER_RESULT);
    printf("|                                             LOST: %d                                                    |\n", RESULT_OF_THE_PROGRAM);
    printf("|                                             TIE:  %d                                                    |\n", TIE);
    printf("| ~ THANKS FOR PLAYING AND IF YOU WISH YOU CAN REPORT ANY BUGS YOU ENCOUNTERED WHEN PLAYING THE GAME    ~|\n");
    printf("----------------------------------------------------------------------------------------------------------\n");
}

int main(){
    int input;
    int program;

    srand(time(0));

    game_rules();

    do{
        printf("\nEnter the move you want to play\n");
        printf("1 - PAPER\n");
        printf("2 - ROCK\n");
        printf("3 - SCISSORS\n");
        printf("\n>> ");
        scanf("%d",&input);

        if(input > 3){
            printf("\n\nYOU LOST BECAUSE AN INVALID MOVE WAS ENTERED\n\n");
            continue;
        }

        program=move();
        
        moves(&input, &program);
        NUMBER_ROUNDS++;
    } while(input>0);

    NUMBER_ROUNDS--;
    results();

    system("pause");
}