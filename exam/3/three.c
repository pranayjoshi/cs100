//Name this program three.c - This program counts how many times a non-whitespace character appears in the command line arguments excluding argv[0]. The character is read from stdin and prompts the user for a new character until EOF. For example:

#include <stdio.h>
#include <string.h>

int main(int argc, char ** argv) {
    char c;
   printf("Enter a char (EOF exits):\n");
    while (scanf("%c", &c) != EOF) {
        int count = 0;
        for (int i = 1; i < argc; i++) {
            for (int j = 0; j < strlen(argv[i]); j++) {
                if (argv[i][j] == c) {
                    count++;
                }
            }
        }
        printf("%c occurs %d times\n\n", c, count);
        printf("Enter a char (EOF exits):\n");
        getchar();
    }

   return 0;
}
