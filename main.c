#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int multi_mode(){
    int win;
    int nb_matches = 15 ;
    printf("There are %d matches left\n", nb_matches);

    while (nb_matches > 0){
        // Player 1's turn
        int p1_nb = -1 ;
        while ((1 > p1_nb) || (p1_nb > 3)){ // Check if the number of matches taken is correct 
            printf("P1 : enter a number of matches to take (1, 2 or 3) : ");
            scanf("%d", &p1_nb);
        }
        nb_matches = nb_matches - p1_nb;
        if (nb_matches <= 0) {  // If there's a negatif or null number of matches,
            win = 2;            // the win goes to the other player
            break;
        } 
        printf("There are %d matches left\n", nb_matches);

        // Player 2's turn
        int p2_nb = -1;
        while ((1 > p2_nb) || (p2_nb > 3)){ 
            printf("P2 : enter a number of matches to take (1, 2 or 3) : ");
            scanf("%d", &p2_nb);
        }
        nb_matches = nb_matches - p2_nb;
        if (nb_matches <= 0){
            win = 1;
            break;
        }
        printf("There are %d matches left\n", nb_matches);

    } 
    return win;
}

int bot_mode(){
    int win;
    int nb_matches = 15 ;
    printf("There are %d matches left\n", nb_matches);

    while (nb_matches > 0){
        // Player 1's turn
        int p1_nb = -1 ;
        while ((1 > p1_nb) || (p1_nb > 3)){
            printf("P1 : enter a number of matches to take (1, 2 or 3) : ");
            scanf("%d", &p1_nb);
        }
        nb_matches = nb_matches - p1_nb;
        if (nb_matches <= 0) {
            win = 2;
            break;
        } 
        printf("There are %d matches left\n", nb_matches);

        // Computer's turn
        int p2_nb = (rand() % 3) + 1;     // rand() gives a random number and we make it modulo 3 to get
        nb_matches = nb_matches - p2_nb;    // a value such as 0,1 or 2. The +1 is to prevent any 0 and get a 3 perhaps
        printf("The computer took %d matches\n", p2_nb);
        if (nb_matches <= 0){
            win = 1;
            break;
        }
        printf("There are %d matches left\n", nb_matches);

    } 
    return win;
}

int main(){

    srand(time(NULL));   // Resets the random seed

    printf("Hi ! Welcome to my second mini-game ! (we're getting there) \n");

    int replay = 1;
    while (replay == 1){
    
        int choice = 1;
        printf("If you wish to play in 2 player mode, enter 1. Else, enter 2 to challenge a bot.\n");
        printf("If you desire to quit, enter any other number\n");
        printf("Please enter a number : ");
        scanf("%d", &choice);

        if (choice == 1){
            int winner = multi_mode();
            printf("The winner is Player %d ! Congrats !\n", winner);
        } else if (choice == 2){
            int winner = bot_mode();
            printf("The winner is Player %d ! Congrats !\n", winner);
        } else {
            break;
        }
        printf("Do you desire to play again ? (1 = yes / 0 = no)\n");
        printf("Please enter your choice : ");
        scanf("%d", &replay);
    }
    printf("See you next time !");
    return 0;
}