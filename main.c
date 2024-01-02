#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int multi_mode(){
    int win;
    int nb_matches = 15 ;
    while (nb_matches > 0){
        // Player 1's turn
        int p1_nb = -1 ;
        while ((p1_nb != 1) || ((p1_nb != 2) || (p1_nb != 3))){
            printf("P1 : enter a number of matches to take (1, 2 or 3) : ");
            scanf("%d", &p1_nb);
        }
        nb_matches = nb_matches - p1_nb;
        if (nb_matches <= 0) {
            win = 2;
            break;
        } 

        int p2_nb = -1;
        while ((p2_nb != 1) || ((p2_nb != 2) || (p2_nb != 3))){
            printf("P2 : enter a number of matches to take (1, 2 or 3) : ");
            scanf("%d", &p2_nb);
        }
        nb_matches = nb_matches - p2_nb;
        if (nb_matches <= 0){
            win = 1;
            break;
        }

    } 
    return win;
}

int bot_mode(){
    return 0;
}

int main(){

    srand(time(NULL));   // Resets the random seed

    int replay = 1;
    while (replay == 1){
    
        int choice = 1;
        printf("Hi ! Welcome to my second mini-game ! (we're getting there) \n");
        printf("If you wish to play in 2 player mode, enter 1. Else, enter 2 to challenge a bot.\n");
        printf("If you desire to quit, enter any other number\n");
        printf("Please enter a number : ");
        scanf("%d", &choice);

        if (choice == 1){
            int winner = multi_mode();
            printf("The winner is Player %d ! Congrats !", winner);
        } else if (choice == 2){
            bot_mode();
            printf("Not done yet, please wait ;)");
        }
        printf("Do you desire to play again ? (1 = yes / 0 = no)\n");
        printf("Please enter your choice : ");
        scanf("%d", &replay);
    }
    return 0;
}