#include <stdio.h>
#include <ctype.h>

int main() {
    int c;

    while ((c = getchar()) != EOF) {
        if (isalpha(c) || isspace(c) || c == '\n' || c == '\t') {
            printf("%c", c);
        }
    }

    return 0;
}
