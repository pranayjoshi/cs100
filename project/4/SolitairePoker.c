/*
 SolitairePoker.c
 
 Notes: The 52 cards of a deck are represented as integers: 0 .. 51
 0..12 are clubs Ace, 2, ..., King
 13..25 are diamonds Ace, 2, ..., King
 26..38 are hearts Ace, 2, ..., King
 39..51 are spades Ace, 2, ..., King

 */

#include <stdio.h> 
#include <string.h> 
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
//do not remove
#include "include.code" //Include custom header file (it contains necessary functions)
//A version of the file:include.code is available from the assignment page
//as studentinclude.code which you should save locally as include.code
//include.code contains implementations for seed, instructions, and private_nextcard(int)
//used by shuffle and next card.
//The version used during testing is slightly different but will not affect your efforts.
//For testing you may modify studentinclude.code -- it will not be part of your submission.


// Function to shuffle the deck
//you should call this before each deal (including the first)
void shuffle() {
    private_nextcard(1); // Call a custom function to shuffle
}

// Function to get the next card to be dealt
//call this to deal a card. Do not call rand().
int nextcard() {
    return private_nextcard(0); // Call a custom function to get the next card
}

// Enumeration for different poker hands
enum hands { UNKNOWN, HIGHCARD, PAIR, TWOPAIR, TRIPS, STRAIGHT,
    FLUSH, FULLHOUSE, QUADS, STRAIGHTFLUSH, ROYALFLUSH };
char * handNames[] ={ "UNKNOWN", "HIGHCARD", "PAIR", "TWOPAIR", "TRIPS", "STRAIGHT",
    "FLUSH", "FULLHOUSE", "QUADS", "STRAIGHTFLUSH", "ROYALFLUSH" }; // Names of each hand

// Enumeration for card suits
enum suits {CLUB, DIAMOND, HEART, SPADE};
char * suitNames[] ={ "CLUB", "DIAMOND", "HEART", "SPADE"}; // Names of card suits

// Enumeration for card ranks
enum ranks {ACE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING};
char * rankNames[] ={ "ACE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN",
    "EIGHT", "NINE", "TEN", "JACK", "QUEEN", "KING"}; // Names of card ranks

//FUNCTION PROTOTYPES: YOU MUST IMPLEMENT THESE FUNCTIONS

// Function to get the rank of a card
enum ranks getrank(int card);

// Function to get the suit of a card
enum suits getsuit(int card);

// Function to evaluate the poker hand
enum hands eval(int []);

// Function to check for a royal flush
int royalflush(int []);

// Function to check for a straight flush
int straightflush(int []);

// Function to check for four of a kind
int fourofkind(int []);

// Function to check for a full house
int fullhouse(int []);

// Function to check for a flush
int flush(int []);

// Function to check for a straight
int straight(int []);

// Function to check for three of a kind
int threekind(int []);

// Function to check for two pairs
int twopair(int []);

// Function to check for a pair
int pair(int []);


char* strToLower(const char* str) {
    char* result = strdup(str);

    for (int i = 0; result[i]; i++) {
        result[i] = tolower(result[i]);
    }

    return result;
}

int Count(int [],int, int);

int calcEval(enum hands);

void Printer(int [10][5], int[]);


int main(int argc, char ** argv) {
    //do not remove
    seed(argc, argv); // Seed the random number generator
    instructions(); // Display game instructions

    //TODO:
        //WRITE CODE TO PLAY 10 HANDS OF POKER
            //DEAL 5 CARDS
            //SHOW DEALT HAND
            //DRAW UP TO 3 CARDS
            //SHOW FINAL HAND
            //EVAL REPPORT AND SAVE INFO FOR LATER
        //GENERATE SCORESHEET USING INFO
    // printf("%s",strlwr(rankNames[0]));
    // for (int i = 0; i < sizeof(sizeRank); i++){
    //     strlwr(rankNames[i]);
    // }
    // for (int i = 0; i < sizeof(sizeSuit); i++){
    //     strlwr(suitNames[i]);
    // }

    int vals[10][5];
    int evals[10];
    // int test[5] = {26,36,35,38,37};
    // printf("%d", royalflush(test));
    // for (int j =0; j<5;j++){
    //         printf("%s-%s   ", strToLower(suitNames[getsuit(test[j])]), strToLower(rankNames[getrank(test[j])]));
    // }
    for (int i =0; i<10;i++){
        int hand[5];
        for (int j =0; j<5;j++){
            hand[j] = nextcard();
        }
        for (int j =0; j<5;j++){
            printf("%s-%s   ", strToLower(suitNames[getsuit(hand[j])]), strToLower(rankNames[getrank(hand[j])]));
        }
        printf("\n");
        printf("Select up to three cards to replace[1-5] and press enter\n");
        for (int j =0; j<5;j++){
            printf("%s-%s   ", strToLower(suitNames[getsuit(hand[j])]), strToLower(rankNames[getrank(hand[j])]));
        }
        printf("\n");
        

        char input[100];
        fgets(input, sizeof(input), stdin);
        int discard[3];
        int count = sscanf(input, "%d %d %d", &discard[0], &discard[1], &discard[2]);
        for (int j =0; j<count;j++){
            hand[discard[j-1]] = nextcard();
        }

        for (int j =0; j<5;j++){
            vals[i][j] = hand[j];
            printf("%s-%s   ", strToLower(suitNames[getsuit(hand[j])]), strToLower(rankNames[getrank(hand[j])]));
        }
        printf("\n");
        evals[i] = eval(hand);
        printf("Hand  %d: Score:    %d %s\n", i+1, calcEval(eval(hand)), handNames[eval(hand)]);
    }

    Printer(vals, evals);
    return 0;
}

void Printer(int vals[10][5], int evals[]){

    printf("********************************************************************************\n");
    printf("***                         S C O R E S H E E T                              ***\n");
    printf("********************************************************************************\n");
    int points = 0;
    for (int i = 0; i < 10; i++){
        points += calcEval(evals[i]);
        printf("Hand%3d: Score:%6d %-14s[%2d %7s-%-5s %2d %7s-%-5s %2d %7s-%-5s %2d %7s-%-5s %2d %7s-%-5s ]\n",
        i+1, calcEval(evals[i]), handNames[evals[i]], vals[i][0], suitNames[getsuit(vals[i][0])], rankNames[getrank(vals[i][0])],
        vals[i][1], suitNames[getsuit(vals[i][1])], rankNames[getrank(vals[i][1])],
        vals[i][2], suitNames[getsuit(vals[i][2])], rankNames[getrank(vals[i][2])],
        vals[i][3], suitNames[getsuit(vals[i][3])], rankNames[getrank(vals[i][3])],
        vals[i][4], suitNames[getsuit(vals[i][4])], rankNames[getrank(vals[i][4])]);
    }
    printf("==============================================================================\n");
    printf("Total points:      %d\n", points);
    printf("==============================================================================\n");
}

// Function to get the suit of a card
enum suits getsuit(int card){
    return card/13;
}

// Function to get the rank of a card
enum ranks getrank(int card){
    return card%13;
}
// Function to evaluate the poker hand
enum hands eval(int hand[]){
    int value = 1;
    if (royalflush(hand)){
        value = 10;
    }
    if (straightflush(hand)){
        value = 9;
    }
    if (fourofkind(hand)){
        value = 8;
    }
    if (fullhouse(hand)){
        value = 7;
    }
    if (flush(hand)){
        value = 6;
    }
    if (straight(hand)){
        value = 5;
    }
    if (threekind(hand)){
        value = 4;
    }
    if (twopair(hand)){
        value = 3;
    }
    if (pair(hand)){
        value = 2;
    }
    return value;
}

int calcEval(enum hands x){
    if (x == 10){
        return 50;
    }
    if (x == 9){
        return 45;
    }
    if (x == 8){
        return 40;
    }
    if (x == 7){
        return 32;
    }
    if (x == 6){
        return 26;
    }
    if (x == 5){
        return 17;
    }
    if (x == 4){
        return 11;
    }
    if (x == 3){
        return 7;
    }
    if (x == 2){
        return 3;
    }
    if (x == 1){
        return 1;
    }
    return 0;
}

// Function to check for a royal flush
int royalflush(int hand[]){
    if (straightflush(hand)){
        for (int i = 0; i < 5; i++){
            if (hand[i]%13 == 0){
                return 1;
            }
        }
    }
    
    return 0;
}

// Function to check for a straight flush
int straightflush(int hand[]){
    if (flush(hand) && straight(hand)){
        return 1;
    }
    return 0;
}

// Function to check for a flush
int flush(int hand[]){
    int st[4] = {0};
    for (int i = 0; i < 5; i++){
        st[hand[i]/13] ++; 
    }
    int ind;
    for (ind = 0; ind < 4; ind++){
        if (st[ind] == 5){
            return 1;
        }
    }
    return 0;
}

// Function to check for a straight
int straight(int hand[]){
    int st[13] = {0};
    
    for (int i = 0; i < 5; i++){
        if (hand[i]%13 == 0 ){
            st[12] ++; 
        }
        else {
            st[hand[i]%13-1] ++;
        } 
    }
    int ind;
    for (ind = 0; ind < 13; ind++){
        if (st[ind] == 1){
            break;
        }
        ind++;
    }
    // printf("%d", ind);
    for (int i = ind; i < ind+5; i++){
        if (st[i] != 1){
            return 0;
        }
    }
    return 1;
}

// Function to check for four of a kind
int fourofkind(int hand[]){
    int count = Count(hand, 5, 4);
    if (count == 1){
        return 1;
    }
    return 0;
}

// Function to check for a full house
int fullhouse(int hand[]){
    int count = Count(hand, 5, 3);
    if (count == 1){
        int count2 = Count(hand, 5, 2);
        if (count2 == 1){
            return 1;
        }
    }
    return 0;
}

// Function to check for three of a kind
int threekind(int hand[]){
    int count = Count(hand, 5, 3);
    if (count == 1){
        return 1;
    }
    return 0;
}

// Function to check for two pairs
int twopair(int hand[]){
    int count = Count(hand, 5, 2);
    if (count == 2){
        return 1;
    }
    return 0;
}

// Function to check for a pair
int pair(int hand[]){
    int count = Count(hand, 5, 2);
    if (count == 1){
        return 1;
    }
    return 0;
}


int Count(int hand[], int size, int num){
    int st[13] = {0};
    for (int i = 0; i < size; i++){
        st[hand[i]%13] ++; 
    }
    int count = 0;
    for (int i = 0; i < 13; i++){
        if (st[i] == num){
            count++;
        }
    }
    return count;
}