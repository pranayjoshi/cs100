#include <stdio.h>
#include <ctype.h>

int main()
{
    int totalW;
    scanf("%d", &totalW);
    char out[100];
    for (int i = 0; i < totalW; i++) {
        char word[51];
        scanf(" %s", word);
        for (int i = 0; word[i] != '\0'; i++)
        {
            if (isupper(word[i])){
                out+=word[i];
            }
        }
    }

    printf("The result is '%s'", out);

    return 0;
}