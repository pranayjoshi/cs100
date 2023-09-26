 /* 
 yahtC
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

void seed(int argc, char ** argv){
    srand(time(NULL)); // Initialize random seed
    if (argc>1){
        int i;
        if (1 == sscanf(argv[1],"%d",&i)){
            srand(i);
        }
    }
}
void instructions(){
    printf("\n\n\n\n"
           "\t**********************************************************************\n"
           "\t*                         Welcome to YahtC                            *\n"
           "\t**********************************************************************\n"
           "\tYahtC is a dice game (very) loosely modeled on Yahtzee\n"
           "\tBUT YahtC is not Yahtzee.\n\n"
           "\tRules:\n"
           "\t5 dice are rolled\n"
           "\tThe user selects which dice to roll again.\n"
           "\tThe user may choose to roll none or all 5 or any combination.\n"
           "\tAnd then the user selects which dice to roll, yet again.\n"
           "\tAfter this second reroll the turn is scored.\n\n"
           "\tScoring is as follows:\n"
           "\t\t*\t50 points \t5 of a kind scores 50 points.\n"
           "\t\t*\t45 points \tNo pairs (all unique) scores 45 points.\n"
           "\t\t*\t40 points \t4 of a kind scores 40 points.\n"
           "\t\t*\t30 points \t3 of a kind scores 30 points.\n"
           "\t\t*\tTotal Dice\tOtherwise score the dice total.\n\n"
           "\tTo indicate nothing to reroll the user will input 0\n"
           "\tThis should end the players turn.\n"
           "\tOtherwise the user will indicate which dice to reroll by position\n"
           "\t135 would indicate to reroll the first, third and last die.\n"
           "\tThe numbers do not have to be given in order\n"
           "\tThe game ends after 7 turns.\n"
           "\t**********************************************************************\n\n\n");
           }

int rollDie() {
    return rand() % 6 + 1;
}

void displayDice(int dice[], int numDice) {
    for (int i = 0; i < numDice; i++) {
        printf("%d ", dice[i]);
    }
    printf("\n");
}

int main(int argc, char ** argv){
    seed(argc, argv);
    instructions();

    for (int i = 0; i<7; i++){
        int numDice = 5;
        int dice[numDice];
        int reroll;
        for (int i = 0; i < numDice; i++) {
            dice[i] = rollDie();
        }
        printf("First Roll =");
        displayDice(dice, numDice);
        for (int q = 0; q< 2;q++){
            printf("Select dice to reroll:");
            scanf("%d", &reroll);
            if (reroll == 0) {
                displayDice(dice,numDice);
                break;
            }
            while (reroll != 0) {
                int i = reroll % 10;
                dice[i-1] = rollDie();
                reroll /= 10;
            }
            displayDice(dice,numDice);
        }
    }


    


    return 0;
}
