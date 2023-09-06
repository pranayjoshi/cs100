#include <stdio.h>
int main(){
    int a, b, c;
    scanf("%lf %lf %lf", &a, &b, &c);
    double med;
    if (a >= b){
        if (b >= c) med = b;
        else if (c >= a) med = a;
        else med = c;
    }
     
    if (b >= a) {
        if (a >= c) med = a;
        else if (c >= b) med = b;
        else med = c;
    }
    printf("%lf", med);
}