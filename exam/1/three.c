#include <stdio.h>

int main(void) {

   int x;
   scanf("%d", &x);

   printf("%d\n", ((x%1000) -(x%100))/100);

   return 0;
}