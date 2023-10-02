#include <stdio.h>
#include <string.h>

int main()
{
    int strA[26] = {0};
    char str[51];
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0';
    for (int i = 0; str[i] != '\0'; i++)
    {
        int sj = str[i] - 'a';
        strA[sj]++;
    }
    int t = 0;
    printf("Unique characters include: ");
    for (int i = 0; i < 26; i++)
    {
        if (strA[i] == 1)
        {
            t = 1;
            break;
        }
    }

    if (t)
    {
        for (int i = 0; i < 26; i++)
        {
            if (strA[i] == 1)
            {
                printf("%c ", 'a' + i);
            }
        }
    }
    else{
        printf("NONE");
    }

    return 0;
}
