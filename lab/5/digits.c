#include <stdio.h>

int main(){
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);
    int dup = 0;
    int digA[10] = {0};
    while (num > 0) {
        int digit = num % 10;
        digA[digit]++;
        if (digA[digit] >1){
            dup = 1;
        }
        num /= 10;
    }
    if (dup) {
        printf("Duplicate digits found\n");
    } else {
        printf("No duplicate digits found\n");
    }
    return 0;
}