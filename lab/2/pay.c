#include <stdio.h>

int main(){
    double wage;
    int hours;
    double totalWage;
    scanf("%lf %d", &wage, &hours);
    if (hours <= 40){
        totalWage = wage * hours;
    }
    else if (hours <= 50){
        totalWage = wage * 40;
        totalWage += wage * 1.5 * (hours - 40);
    }
    else{
        totalWage = wage * 40;
        totalWage += wage * 1.5 * 10;
        totalWage += wage * 2.0 * (hours - 50);
    }

    printf("%lf", totalWage);
}