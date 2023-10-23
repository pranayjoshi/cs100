/*
 The command line will have an input file name and an output file name.

 The input file will be a series of integer triples.
 Print each triple to the output file in increasing order.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void count(char *str, int *lower, int *upper, int *digit)
{
    for (int i = 0; i < strlen(str); i++)
    {
        if (isalpha(str[i]))
        {
            if (islower(str[i]))
            {
                *lower += 1;
            }
            else
            {
                *upper += 1;
            }
        }
        else if (isdigit(str[i]))
        {
            *digit += 1;
        }
    }
}

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s <input file> <output file>\n", argv[0]);
        exit(1);
    }

    int upper = 0;
    int lower = 0;
    int digit = 0;

    char *str = argv[1];
    count(str, &lower, &upper, &digit);

    printf("Uppers = %d\nLowers = %d\nDigits = %d\n", upper, lower, digit);
    return 0;
}
