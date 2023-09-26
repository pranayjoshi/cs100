#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main(void) {

   char s[257];
   scanf(" %s", &s);
   for (int a = 0; strlen(s); a++)
    { 
        printf("%c",toupper(s[a]));
    }
    printf("\n")
   return 0;
}