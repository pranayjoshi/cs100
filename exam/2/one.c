#include <stdio.h>
double calculatePostage(int weightOunces, double volumeCubicFeet );
int main(void) {
   int weightOunces;
   double volumeCubicFeet;
   scanf("%d %lf",&weightOunces,&volumeCubicFeet);
   double po = calculatePostage(weightOunces, volumeCubicFeet );
   printf("Postage is $%.2lf\n",po);

   return 0;
}
/*
- If the volume in cubic feet is less than 2 cubic feet, the postage is calculated as $.28 per ounce. 
- If the volume is between 2 cubic feet and less than 4 cubic feet, the postage is calculated at $.36 per ounce.  
- If the volume is equal or greater than 4 cubic feet, the postage is calculated at $.56 per ounce.  
*/
double calculatePostage(int weightOunces, double volumeCubicFeet ){
   double po = 0.0;
   if (volumeCubicFeet < 2.0){
      po = weightOunces * 0.28;
   }
   else if (volumeCubicFeet < 4.0){
      po = weightOunces * 0.36;
   }
   else {
      po = weightOunces * 0.56;
   }
   return po;
}