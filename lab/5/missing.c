#include <stdio.h>

int main()
{
    printf("Enter a input:\n");
    int strA[26] = {0};
    int str;
    while ((str = getchar()) != EOF)
    {
        int sj = str - 'a';
        strA[sj]++;
    }
    int t = 0;
    for (int i = 0; i < 26; i++)
    {
        if (strA[i] == 0)
        {
            t = 1;
            break;
        }
    }

    if (t)
    {
        printf("Missing letters: ");
        for (int i = 0; i < 26; i++)
        {
            if (strA[i] == 0)
            {
                printf("%c ", 'a' + i);
            }
        }
    }
    else{
        printf("Your input contains all the letters");
    }

    return 0;
}
