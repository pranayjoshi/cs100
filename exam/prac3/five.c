
/*
 The command line will have two input file names and an output file name.

 Each input file will be a sorted list integers. 
 Merge these list (sorted). 
 Compute the average. 
 Print the absolute difference of each number from the average to the specified output file.
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char ** argv){
   FILE *inp1 = fopen(argv[1], "r");
   FILE *inp2 = fopen(argv[2], "w");
   FILE *out = fopen(argv[3], "w");
   int numA1[100];
   int numA2[100];
   int total, count1;
   while (scanf(inp1, "%d",&numA1[count1++])==1){
      total+= numA1[count1];
   }
   int count2 = 0;
   while (scanf(inp2, "%d",&numA2[count2++])){
      total+= numA2[count2];
   }
   int avg = total/(count1+count2);
   int i = 0;
   int j = 0;
   int k = 0;
   int merged[count1+count2+1];
   while (i < count1 && count2 > j){
      if ( numA1[i] < numA2[j]){
         merged[k++] = abs(arr1[i++]-avg);
      }
      else {
         merged[k++] = abs(arr2[j++]-avg);
      }
   }
   while (i < count1) {
      merged[k++] = abs(arr1[i++]-avg);
   }

   while (j < count2) {
      merged[k++] = abs(arr2[j++]-avg);
   }
   
   for (int i = 0; i < k; i++){
      fprintf(out, "%d\n", merged[i]);
   }
   
   fclose(inp1);
   fclose(inp2);
   fclose(inp3);
   
   return 0;
}
