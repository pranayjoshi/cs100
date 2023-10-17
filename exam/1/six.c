#include <stdio.h>
#include <string.h>
int main(void) {

    int totalW;
    scanf("%d", &totalW);
    char out[100] = "";
    int res = 0;
    char word1[1000];
    scanf(" %s", word1);
    char min[1000], max[100];
    strcpy(min, word1);
    strcpy(max, word1);
    for (int i = 0; i < totalW-1; i++)
    {
        char word[1000];
        scanf(" %s", word);
        if (strlen(min)>strlen(word)){
            strcpy(min, word);
        }
        if (strlen(max)<strlen(word)){
            strcpy(max, word);
        }
    }
    printf("The shortest word: %s\nThe longest word: %s\n",min, max);

   return 0;
}
