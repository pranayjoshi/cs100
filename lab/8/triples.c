/*
 The command line will have an input file name and an output file name.

 The input file will be a series of integer triples. 
 Print each triple to the output file in increasing order.
*/
#include <stdio.h>
#include <stdlib.h>

void sort_triple(int *a, int *b, int *c) {
    if (*a > *b) {
        int temp = *a;
        *a = *b;
        *b = temp;
    }
    if (*b > *c) {
        int temp = *b;
        *b = *c;
        *c = temp;
    }
    if (*a > *b) {
        int temp = *a;
        *a = *b;
        *b = temp;
    }
}

int main(int argc, char ** argv){
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <input file> <output file>\n", argv[0]);
        exit(1);
    }

    int a, b, c;

    FILE *inputFile = fopen(argv[1], "r");
    FILE *outputFile = fopen(argv[2], "w");

    while (fscanf(inputFile, "%d %d %d", &a, &b, &c) == 3) {
        sortTriple(&a, &b, &c);
        fprintf(outputFile, "%d %d %d\n", a, b, c);
    }

    fclose(inputFile);
    fclose(outputFile);
    return 0;
}
