#include <stdio.h>

int main()
{
    int s;
    scanf("%d", &s);
    for (int i = 0; i < s; i++)
    {
        for (int j = 0; j < s; j++)
        {
            if (i == 0 || i == s - 1)
            {
                printf("x");
            }
            else if (j == 0 || j == s - 1)
            {
                printf("x");
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }
}