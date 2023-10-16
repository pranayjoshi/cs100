#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s file1.txt file2.txt\n", argv[0]);
        return 1;
    }

    FILE *file1 = fopen(argv[1], "r");
    FILE *file2 = fopen(argv[2], "r");

    if (file1 == NULL || file2 == NULL) {
        perror("Error opening input files");
        return 1;
    }

    int num1, num2;
    int eof1 = fscanf(file1, "%d", &num1);
    int eof2 = fscanf(file2, "%d", &num2);

    while (eof1 != EOF || eof2 != EOF) {
        if (eof1 == 1 && eof2 == 1) {
            if (num1 < num2) {
                printf("%d ", num1);
                eof1 = fscanf(file1, "%d", &num1);
            } else if (num1 > num2) {
                printf("%d ", num2);
                eof2 = fscanf(file2, "%d", &num2);
            } else {
                printf("%d ", num1);
                eof1 = fscanf(file1, "%d", &num1);
                eof2 = fscanf(file2, "%d", &num2);
            }
        } else if (eof1 == 1) {
            printf("%d ", num1);
            eof1 = fscanf(file1, "%d", &num1);
        } else if (eof2 == 1) {
            printf("%d ", num2);
            eof2 = fscanf(file2, "%d", &num2);
        }
    }

    fclose(file1);
    fclose(file2);

    return 0;
}
