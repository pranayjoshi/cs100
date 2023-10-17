#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main(void) {
   char *inp;
   while (fgets(inp,sizeof(inp),stdin)!=NULL){
      printf("%s", inp);
   }
   return 0;
}