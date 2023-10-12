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
#include "studentinclude.code" //Include custom header file (it contains necessary functions)
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
    for (int i =0; i<10;i++){
        int hand[5];
        for (int j =0; j<5;j++){
            hand[j] = nextcard();
        }
        printf("Your hand is: %d\n", hand[2]);
        for (int j =0; j<5;j++){
            printf("%s-%s   ", strToLower(suitNames[getsuit(hand[j])]), strToLower(rankNames[getrank(hand[j])]));
        }
        printf("\n");
        printf("Select up to three cards to replace[1-5] and press enter\n");
        for (int j =0; j<5;j++){
            printf("%s-%s   ", strToLower(suitNames[getsuit(hand[j])]), strToLower(rankNames[getrank(hand[j])]));
        }
        printf("\n");
        int discard[3];
        scanf("%d %d %d", &discard[0], &discard[1], &discard[2]);
        for (int j =0; j<3;j++){
            hand[discard[j]] = nextcard();
        }
        for (int j =0; j<5;j++){
            printf("%s-%s   ", strToLower(suitNames[getsuit(hand[j])]), strToLower(rankNames[getrank(hand[j])]));
        }
        printf("\n");
        // printf("You have a %s\n", handNames[eval(hand)]);
    }
    return 0;
}

//TODO:
//THE FOLLOWING STUBS NEED TO BE IMPLEMENTED CORRECTLY

// Function to get the suit of a card
enum suits getsuit(int card){
    return card/13;
}

// Function to get the rank of a card
enum ranks getrank(int card){
    return card/4;
}
// Function to evaluate the poker hand
enum hands eval(int hand[]){
    return 0;
}

// Function to check for a royal flush
int royalflush(int hand[]){
    return 0;
}

// Function to check for a straight flush
int straightflush(int hand[]){
    return 0;
}

// Function to check for a flush
int flush(int hand[]){
    return 0;
}

// Function to check for a straight
int straight(int hand[]){
    return 0;
}

// Function to check for four of a kind
int fourofkind(int hand[]){
    return 0;
}

// Function to check for a full house
int fullhouse(int hand[]){
    return 0;
}

// Function to check for three of a kind
int threekind(int hand[]){
    return 0;
}

// Function to check for two pairs
int twopair(int hand[]){
    int st[5];
    for (int i = 0; i < 5; i++){
        st[hand[i]-1] ++; 
    }
    return 0;
}

// Function to check for a pair
int pair(int hand[]){

    return 0;
}
