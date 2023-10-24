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
    printf("argc: %d\n", argc);
    printf("%s\n", *argv);
    int a = -1;
    int b = -1;
    
    for (int i =2; i < argc; i++) {
        if(atoi(argv[i]) > a) {
            a = atoi(argv[i]);
        }
        if (atoi(argv[i]) < b) {
            b = atoi(argv[i]);
        }
    }
    printf("%d\n",argc);
    printf("%s\n",*argv);
    printf("%d\n", a);
    printf("%d\n", b);

    return 0;
}
