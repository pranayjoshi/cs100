#include <stdio.h>
#include <ctype.h>

int main(int argc, char *argv[]) {

    FILE *inputFile = fopen(argv[1], "r");
    if (inputFile == NULL) {
        printf("Cannot open file '%s'\n", argv[1]);
        return 0;
    }
    FILE *outputFile = fopen(argv[2], "w");
    if (outputFile == NULL) {
        printf("Cannot open file '%s'\n", argv[2]);
        fclose(inputFile);
        return 0;
    }

    char word[51];
    int i;
    while (1 ==fscanf(inputFile, "%50s", word)) {
        for (i = 0; word[i] != '\0'; i++) {
            if (!isalpha(word[i])) {
                break;
            }
        }
        if (word[i] == '\0') {
            fprintf(outputFile, "%s ", word);
        }
    }
    fclose(inputFile);
    fclose(outputFile);

    return 0;
}
