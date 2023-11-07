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
    if (!isdigit(argv[2])) {
        printf("usage: <pgm> filename number\n");
        printf("number must be an integer value greater than 0\n");
        return 0;
    }

    if (inp == NULL) {
        printf("unable to open %s\n", argv[1]);
        return 0;
    }

    int n = atoi(argv[2]);
    char line[100];
    int count = 0;
    while (fgets(line, 100, inp) != NULL) {
        char *token = strtok(line, " ");
        while (token != NULL) {
            printf("%s", token);
            count++;
            if (count % n == 0) {
                printf("\n");
            } else {
                printf(",");
            }
            token = strtok(NULL, " ");
        }
    }


    return 0;
}


    return 0;
}
