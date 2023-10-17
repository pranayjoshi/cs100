#include <stdio.h>

//you must use this prototype without modification
double trackRiverWaterLevelAvgRainfall(int n, int *rainfall, int dailyAbsorptionInches, int floodStageInches, int *floodDays, int *droughtDays);


//todo: main has a skeleton but needs to be finished. Variables need to be declared
int main() {
   //The first line of input will contain N (int), the number of days for which the rainfall is provided.
   printf("How many days of rainfall to process?\n");
   //todo: read N

   //The second line will contain the inches of rain that can be absorbed per day (int) and the number of inches at which the river reaches flood stage (int).
   int dailyAbsorptionInches;
   int floodStageInches;
   printf("Enter rainfall absorption rate in inches (int) and flood stage in inches (int)?\n");
   scanf("%d %d", dailyAbsorptionInches, floodStageInches);
   //todo: read absoptionRate and floodLevel

   //Following the second line will be a series of N integers that represent daily rainfall amounts.  
   printf("Enter %d daily rainfall totals:\n", n);
   //todo: read the daily values

   //Once the information is collected it will be passed to a function that will tracks the daily river level by adding the daily rainfall and subtracting the daily absorption rates. The water level will start at zero and should not be allowed to go below zero. 
   //Finally, average rainfall should be computed and returned as the function value..  
   //todo: call the function

   //todo: print the results,you may need to adjust variable names
   //printf("The average of rainfall is %.2lf\n", avgRainFall);
   //printf("%d days of drought\n", daysOfDrought);
   //printf("%d days at or above flood stage\n", daysOfFloodStage);

   return 0;
}
//A function will count the number of days that the river is at or above flood level and the number of days that the river level is at zero (these are drought days). Returning these values using reference parameters.
double trackRiverWaterLevelAvgRainfall(int n, int *rainfall, int dailyAbsorptionInches, int floodStageInches, int *floodDays, int *droughtDays){
   //tracks the daily river level by adding the daily rainfall and subtracting the daily absorption rates. 
   //The water level will start at zero and should not be allowed to go below zero. 
   //average rainfall is computed and returned.  
   double avg = 0;
   return avg;
}