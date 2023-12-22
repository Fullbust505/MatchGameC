#include <stdio.h>
#include <stdlib.h>

int multi_mode(){
    return 0;
}

int bot_mode(){
    return 0;
}

int main_menu(){
    int replay = "Y";
    while (replay == "Y"){
    
        int choice;
        printf("Hi ! Welcome to my second mini-game ! (we're getting there) \n");
        printf("If you wish to play in 2 player mode, enter 1. Else, enter 2 to challenge a bot.\n");
        printf("If you desire to quit, enter any other number\n");
        scanf("Please enter a number : %d", &choice);

        if (choice == 1){
            multi_mode();
        } else if (choice == 2){
            bot_mode();

        printf("Do you desire to play again ? (Y = yes / N = no)\n");
        scanf("Please enter your choice : %d", &replay);
    
    }
    return 0;
}