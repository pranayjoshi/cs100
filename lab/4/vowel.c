#include <stdio.h>
#include <ctype.h>

int main()
{
    int vowelCounts[5] = {0, 0, 0, 0, 0};
    char word[50];

    char vowels[5] = {'a', 'e', 'i', 'o', 'u'};
    while (scanf("%s", word) != EOF)
    {
        for (int i = 0; word[i] != '\0'; i++)
        {
            char c = tolower(word[i]);
            for (int j = 0; j < 5; j++)
            {
                if (c == vowels[j])
                {
                    vowelCounts[j]++;
                }
            }
        }
    }

    for (int i = 0; i < 5; i++)
    {
        printf("The vowel %c occurred %d times\n", vowels[i], vowelCounts[i]);
    }

    return 0;
}