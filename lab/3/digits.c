#include <stdio.h>

void digit(int num){
    int sum = 0;
    while (num !=0){
        sum+=num%10;
        num/=10;
    }
    printf("%d", sum);
}

int main(){
    int num;
    scanf("%d", &num);
    digit(num);
    return 0;
}