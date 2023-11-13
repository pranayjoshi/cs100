#include <stdio.h>
#include <string.h>
#include <ctype.h>

/*
 lab1.c

 We define cardinality of letters such that a|A == 1, b|B == 2, ... z|Z == 26.
 We define a heft function for a string as the sum of the letters cardinality.
 Case insensitive, only letters.
 
 eg: int heft = card('h')+card('e')+card('f')+card('t')// The heft of "heft" is heft.

 Write a program that gives the heft of any arguments specified on the command line.
  eg:
 ```
 terminal%  ./a.out Test this heft

 "Test" has heft of: 64
 "this" has heft of: 56
 "heft" has heft of: 39
 
 Explanation:
 The computed heft is the sum of the letter cardinalities shown below
 "Test" = T(20) + e(5) + s(19) + t(20) = 64
 "this" = t(20) + h(8) + i(9) + s(19) = 56
 "heft" = h(8) + e(5) + f(6) + t(20) = 39
 ```
 */
int card(char ch){
   
    //The cardinality of a letter. Case insensitive.

    if (ch < 'a'){
        return ch - 'A' + 1;

    }
    else {
        return ch - 'a' + 1;
    }
   return 0;
}
int heft(char * str){
    //Sum of the letters cardinality. Case insensitive, only letters.
    int sum = 0;
    for (int i = 0; i < strlen(str); i++){
        sum += card(str[i]);
    }
    return sum;
}

int main(int argc, char ** argv){
   //give the heft of command line arguments
   //eg: "heft" has heft of: 39
    for (int i = 1; i < argc; i++){
        printf("\"%s\" has heft of: %d\n", argv[i], heft(argv[i]));
    }
    return 0;
}
