#include <stdio.h>

int main(void) {

   /* Type your code here. */
   int total;
   scanf("%d", &total);
   int d = 0, q = 0, di = 0, n = 0, p= 0;
    if (total == 0){
        printf("No change\n");
    }
    if (total/100 != 0){
        if (total/100 > 1){
            printf("%d Dollars\n", total/100);
        }
        else {printf("%d Dollar\n", total/100);}
        total %= 100;
    }
    if (total/25 != 0){
        if (total/25 > 1){
            printf("%d Quarters\n", total/25);
        }
        else {printf("%d Quarter\n", total/25);}
        total %= 25;
    }
    if (total/10 != 0){
        if (total/10 > 1){
            printf("%d Dimes\n", total/10);
        }
        else {printf("%d Dime\n", total/10);}
        total %= 10;
    }
    if (total/5 != 0){
        if (total/5 > 1){
            printf("%d Nickels\n", total/5);
        }
        else {printf("%d Nickel\n", total/5);}
        total %= 5;
    }
    if (total != 0){
        if (total > 1){
            printf("%d Pennies\n", total);
        }
        else {printf("%d Penny\n", total);}
    }

   return 0;
}