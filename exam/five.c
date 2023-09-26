#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void) {

   char str[100];

   scanf("%s", str);

    int v = 0;
    int c = 0;


   for (int i =0; i < strlen(str); i++){
        if (!isalpha(str[i])) {
            continue;
        }
        char q = tolower(str[i]);
        if (q == 'a' || q == 'e' || q == 'i' || q == 'o' || q == 'u'){
            v++;
        }
        else {
            c++;
        }
   }
   printf("vowels: %d\nconsonants: %d\n", v,c);

   return 0;
}