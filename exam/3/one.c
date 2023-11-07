/*
The command line for this C program will have 2 arguments. input filename, and a number, n. eg: ./a.out input.txt 13
If all arguments are not present print a message line:
usage: <pgm> filename number

If the last argument, n, is not a valid number print:
usage: <pgm> filename number
number must be an integer value greater than 0

If unable to open the specified input file print
unable to open <file>

Copy the input file to console printing n comma delimited items per line. 

If the file does not have n items for the last line omit it.

*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
    /*
The command line for this C program will have 2 arguments. input filename, and a number, n. eg: ./a.out input.txt 13
If all arguments are not present print a message line:
usage: <pgm> filename number

If the last argument, n, is not a valid number print:
usage: <pgm> filename number
number must be an integer value greater than 0

If unable to open the specified input file print
unable to open <file>

Copy the input file to console printing n comma delimited items per line. 

If the file does not have n items for the last line omit it.

*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char ** argv){

    FILE *inp = fopen(argv[1], "r");
    // check if arg[2] is number
    if (argc != 3) {
        printf("usage: %s filename number\n", argv[0]);
        
        return 0;
    }

    if (atoi(argv[2]) == 0) {
        printf("usage: %s filename number\n", argv[0]);
        printf("number must be an integer value greater than 0\n");
        return 0;
    }

    if (inp == NULL) {
        printf("unable to open %s\n", argv[1]);
        return 0;
    }

    int n = atoi(argv[2]);
    char line[100];
    int count = 1;
    while (fscanf(inp,"%s", line) == 1) {
        if (count == n) {
            printf("%s", line);
            printf("\n");
            count = 0;
        }
        else{
            printf("%s, ", line);
        }
        
        count++;
    }


    return 0;
}
