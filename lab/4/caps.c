#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main()
{
    int totalW;
    printf("Enter how many words:\n");
    scanf("%d", &totalW);
    char out[100] = "";
    printf("Enter %d words:\n", totalW);
    int res = 0;
    for (int i = 0; i < totalW; i++)
    {
        char word[51];
        scanf(" %s", word);
        int len = 0;
        while (word[len] != '\0')
        {
            len++;
        }

        if (len > 3)
        {
            for (int j = 0; j < len; j++)
            {
                if (isupper(word[j]))
                {
                    out[res] = word[j];
                    res++;
                }
            }
        }
    }

    printf("The result is '%s'\n", out);

    return 0;
}