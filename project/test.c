#include <stdio.h>

int main()
{
    // Input hexadecimal values
    unsigned char hexValues[] = {0x7E, 0x11, 0x11, 0x11, 0x7E};
    char binaryStrA[5][8];
    for (int row = 0; row < 5; row++)
    {
        for (int i = 7; i >= 0; i--)
        {
            binaryStrA[row][i] = (hexValues[row] & 1) + '0';
            hexValues[row] >>= 1;
        }
        binaryStrA[row][8] = '0';
    }

    // for (int row = 0; row < 5; row++)
    // {
    //     for (int i = 0; i < 8; i++)
    //     {
    //         {
    //             printf("%c", binaryStrA[row][i]);
    //         }
            
    //     }
    //     printf("\n");
    // }
    for (int i = 8; i > 0; i--)
        {
            printf("%c%c%c%c%c", binaryStrA[0][i],binaryStrA[1][i],binaryStrA[2][i],binaryStrA[3][i],binaryStrA[4][i]);
            printf("\n");
    }
        
    return 0;
}