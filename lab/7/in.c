#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

    FILE *file1 = fopen(argv[1], "r");

    int i1;
    int sum = 0;
    int eof = fscanf(file1, "%d", &i1);
    int i = 1;
    while (eof != EOF) {
        // printf("%d ", i1);
        sum+=i1;
        if (i == atoi(argv[2])) {
            printf("%d ", sum);
            sum = 0;
            i = 0;
        }
        i++;
        eof = fscanf(file1, "%d", &i1);
    }

    fclose(file1); 

    return 0;
}
