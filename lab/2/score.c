#include <stdio.h>



int main(){
    int a, b, c, d;

    scanf("%d %d %d %d", &a, &b, &c, &d);

    if ((a < b) && (a < c) && (a < d)){
        a = 0;
    }
    else if ((b < a) && (b < c) && (b < d)){
        b = 0;
    }
    else if ((c < a) && (c < b) && (c < d)){
        c = 0;
    }
    else if (a  == b) a = 0;
    else if (a == c) a = 0;
    else if (a == d) a = 0;
    else if (b == c) b = 0;
    else if (b == d) b = 0;
    else if (c == d) c = 0;
    else {d = 0;}
    double final = (a + b + c + d)/3.0;
    printf("%lf", final);

}