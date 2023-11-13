#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

/*
lab3.c
 We again define heft of a string as the sum of its cardinal letter values.
 a|A == 1, b|B == 2, ... z|Z == 26

 The command line will specify a filename. Read all words from the file
 Print the last 10 words (or less, if there are not ten) in the file that are greater than average heft. The words must be printed in the order they first appear in the file. Duplicates should be excluded.

 eg: % ./a.out input1.txt
 Average heft: 53
 Last 2 words over heft of:  53
 1. "Crimson" has heft of: 91
 2. "Clown" has heft of: 67

 explanation: The file contained
 Dog Crimson Clown Crimson Alabama Clown
 Crimson and Clown were greater than average heft but they appeared more than once in the file.
 */
int card(char ch)
{

    // The cardinality of a letter. Case insensitive.
    if (ch < 'a')
    {
        return ch - 'A' + 1;
    }
    else
    {
        return ch - 'a' + 1;
    }
    return 0;
}
int heft(char *str)
{
    // Sum of the letters cardinality. Case insensitive, only letters.
    int sum = 0;
    for (int i = 0; i < strlen(str); i++)
    {
        sum += card(str[i]);
    }
    return sum;
}

int main(int argc, char **argv)
{
    // give the heft of command line arguments
    // eg: "heft" has heft of: 39
    FILE *inp = fopen(argv[1], "r");
    if (inp == NULL)
    {
        printf("unable to open %s\n", argv[1]);
        return 0;
    }
    char word[100];
    int count = 0;
    int total = 0;
    char words[100][100];
    while (fscanf(inp, "%s", word) == 1)
    {
        int s = 0;
        for (int j = 0; j < count; j++)
        {
            if (strcmp(words[j], word) == 0)
            {
                s = 1;
                break;
            }
        }
        if (s == 1)
        {
            continue;
        }
        strcpy(words[count], word);
        total += heft(word);
        count++;
    }
    int avg = total / count;
    printf("Average heft: %d\n", avg);
    rewind(inp);
    int last10[10][100];
    int last10count = 0;
    int ind = 9;
    int i = count-1;

    while (ind >0&& i>=0)
    {
        int s = 0;
        for (int j = 0; j < count; j++)
        {
            // printf("%s %s\n", words[i], words[j]);
            if (strcmp(words[j], words[i]) == 0)
            {
                s++;
                if(s>1) break;
            }
        }
        if (s >1)
        {
            continue;
        }
        if (heft(words[i]) > avg)
        {
            // printf("%s\n", words[i]);
            last10count++;
            strcpy(last10[ind], words[i]);
            ind--;
        }
        i--;
    }
    printf("Last %d words over heft of: %d\n", last10count, avg);
    int ij = 0;
    for (int i = 10-last10count; i < 10; i++)
        {
            printf("%d. \"%s\" has heft of: %d\n", ij + 1, last10[i], heft(last10[i]));
            i++;
        }

    return 0;
}
