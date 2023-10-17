#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main ()
{
    char sen[256];
    scanf("%s", sen);

    for (int i = 0; i < 256; i++) {
        sen[i] = toupper(sen[i]);
    }

    printf("%s\n", sen);
    return 0;
}