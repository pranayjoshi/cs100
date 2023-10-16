#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

    FILE *file1 = fopen(argv[1], "r");

    int sum = 0;
    int i1 = fscanf(file1, "%d", &i1);
    int i = 0;
    while (i1 != EOF) {
        sum+=i1;
        if (i == 3) {
            printf("%d ", sum);
            sum = 0;
            i = 0;
        }
        i++;
        i1 = fscanf(file1, "%d", &i1);
    }

    fclose(file1); 

    return 0;
}
