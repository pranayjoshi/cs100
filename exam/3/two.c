#include <stdio.h>
#include <stdlib.h>

int *filter(int x[], int n, int lower, int upper, int *pNewSize);

int main() {
   int lower, upper;
   printf("Enter a lower then upper bound:\n");
   scanf("%d %d", &lower, &upper);
   
   int n;
   printf("How many integers?\n");
   scanf("%d", &n);
   
   printf("Enter %d integers:\n", n);
   int x[n];
   for (int i = 0; i < n; i++) {
      scanf("%d", &x[i]);
   }
   int size;
   int *res = filter(x, n, lower, upper, &size);
   
   printf("Filtered numbers between %d and %d (inclusive):\n", lower, upper);
   for (int i = 0; i < size; i++) {
      printf("%d ", res[i]);
   }
   printf("\n");

   return 0;
}

/*
The parameters and return value are as follows:
 `x` - array of integers to filter. This array should not be modified.
 `n` - number of items in `x` where `n >= 1`
 `lower` - the lower bound of a range
 `upper` - the upper bound of a range
 `pNewSize` - a *Pass By Reference* parameter used to return the size of the new array
 `int * return value` - the new array containing the filtered items between `lower` and `upper` (inclusive). 
 Assume the return array will always contain at least 1 value.
*/
int *filter(int x[], int n, int lower, int upper, int *pNewSize) {
   //TODO:
   //1. Find how many items are in the range
    *pNewSize = 0;
   for (int i = 0; i < n; i++) {
      if (x[i] >= lower && x[i] <= upper) {
         (*pNewSize)++;
      }
   }
   //2. Allocate an array of the size
    int *res = malloc(sizeof(int) * (*pNewSize));
   
   //3. Fill the array and return it
    int j = 0;
    for (int i = 0; i < n; i++) {
      if (x[i] >= lower && x[i] <= upper) {
         res[j++] = x[i];
      }
    }
    return res;
}
