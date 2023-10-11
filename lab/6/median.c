#include <stdio.h>

int median (int a, int b, int c);
int main(void) {
   int a, b, c;
   while (3 == scanf("%d%d%d", &a, &b, &c)){
      printf("median of %d, %d, and %d is %d\n", a, b, c, median(a,b,c)); 
   }
   return 0;
}
int median(int a, int b, int c) {
    if ((a >= b && a <= c) || (a <= b && a >= c)) {
        return a;
    } else if ((b >= a && b <= c) || (b <= a && b >= c)) {
        return b;
    } else {
        return c;
    }
}