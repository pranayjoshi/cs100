#include <stdio.h>
#include <ctype.h>

int main() {
    int count_a = 0, count_e = 0, count_i = 0, count_o = 0, count_u = 0;
    char ch;
    // scanf("%s",ch);
    printf("Enter words (Ctrl-D to end):\n");

    while (scanf("%s",&ch) != EOF) {
        if (isalpha(ch)) { // Check if the character is alphabetic
            ch = tolower(ch); // Convert the character to lowercase
            switch (ch) {
                case 'a':
                    count_a++;
                    break;
                case 'e':
                    count_e++;
                    break;
                case 'i':
                    count_i++;
                    break;
                case 'o':
                    count_o++;
                    break;
                case 'u':
                    count_u++;
                    break;
                default:
                    break;
            }
        }
    }

    // Print the results
    printf("The vowel a occurred %d times\n", count_a);
    printf("The vowel e occurred %d times\n", count_e);
    printf("The vowel i occurred %d times\n", count_i);
    printf("The vowel o occurred %d times\n", count_o);
    printf("The vowel u occurred %d times\n", count_u);

    return 0;
}