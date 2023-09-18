#include <stdio.h>
#include <string.h>
int countLower(char str[]){
    int sum = 0;
    for (int i = 0; i < strlen(str); i++){
        if ('a'<=str[i] && str[i] <= 'z'){
            sum +=1;
        }
    }
    return sum;
}
void lower(){
    printf("Enter two strings:\n");
    char str1[80], str2[80];
    scanf("%s %s", str1, str2);
    int s1, s2;
    s1 = countLower(str1);
    s2 = countLower(str2);
    if (s1 == s2){
        printf("'%s' and '%s' both contain %d lowercase letter(s).", str1, str2, s1);
    }
    else if (s1 > s2){
        printf("'%s' contains %d more lowercase letter(s) than '%s'.",str1, s1-s2, str2);
    }
    else {
        printf("'%s' contains %d more lowercase letter(s) than '%s'.",str2, s2-s1, str1);
    }
}

int main(){
    lower();
    return 0;
}