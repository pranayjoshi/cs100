#include <stdio.h>
#include <math.h>

int main(){
    double sh;
    double sm;
    double eh;
    double em;
    printf("Enter the start time: \n");
    scanf("%lf %lf", &sh, &sm);
    printf("Enter the end time: \n");
    scanf("%lf %lf", &eh, &em);
    
    double hd = eh - sh;
    
    double md = (em - sm)*5/300;
    printf("%lf %lf", hd, md);
    double miles = (hd + md)*8;
    printf("You have run %lf miles", miles);
}