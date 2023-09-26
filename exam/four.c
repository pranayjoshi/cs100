#include <stdio.h>

int main(void) {

   int a,b,c;
   
   scanf("%d %d %d", &a, &b, &c);
   
   if ((a <= b && b <= c) || (c <= b && b <= a)){
      printf("%d\n",b);
   }
   else if ((b <= a && a <= c) || (c <= a && a <= b)){
      printf("%d\n",a);
   }
   else {
      printf("%d\n",c);
   }

   return 0;
}
