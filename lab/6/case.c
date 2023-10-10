#include <stdio.h>
#include <ctype.h>

void countCase(char str[], int *pNumUpper, int *pNumLower){
    for (int i = 0; str[i] != '\0'; i++){
        char st[50] = "";
        int lw;
        int up;
        while (1){
            if (isspace(str[i])){
                break;
            }
            else if ('A' <= str[i] && str[i] <='Z'){
                (*pNumUpper)++;
            }
            else if ('a' <= str[i] && str[i] <= 'z'){
                (*pNumLower)++;
            }
        }
        printf("%s: %d uppercase, %d lowercase", st, pNumUpper, pNumLower);
    }
}

int main(){
    char word[51];
    while (1) {
        if (fgets(word, sizeof(word), stdin) != EOF) {
            // EOF encountered or an error occurred
            break;
        }

        // Process the input (here, we're just printing it)
        printf("You entered:\n %s", word);
        break;
    }
    printf("aawd");
    int pNumUpper = 0;
    int pNumLower = 0;
    countCase(word, &pNumUpper,&pNumLower);
}