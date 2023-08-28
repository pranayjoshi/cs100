#include <stdio.h>

int main(){
    double a;
    double b;
    double c;
    double d;
    printf("Enter four integers:");
    scanf("%lf %lf %lf %lf", &a,&b,&c,&d);
    double e = (a+b+c+d)/4;
    printf("The average is %lf", e);
}