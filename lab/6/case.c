#include <stdio.h>
#include <ctype.h>

void countCase(char str[], int *pNumUpper, int *pNumLower);

int main() {
    char input[50];

    while (scanf("%49s", input) == 1) {
        int numUpper = 0, numLower = 0;
        countCase(input, &numUpper, &numLower);
        printf("%s: %d uppercase, %d lowercase\n", input, numUpper, numLower);
    }

    return 0;
}

void countCase(char str[], int *pNumUpper, int *pNumLower) {
    *pNumUpper = 0;
    *pNumLower = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (isupper(str[i])) {
            (*pNumUpper)++;
        } else if (islower(str[i])) {
            (*pNumLower)++;
        }
    }
}
