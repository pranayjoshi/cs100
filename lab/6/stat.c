#include <stdio.h>
#include <math.h>

int getInt(char prompt[]){
    printf("%s", prompt);
    int size;
    scanf("%d", &size);
    return size;
}
void getData(char prompt[], int array[], int size){
    printf("%s", prompt);
    for (int i = 0; i < size; i++){
        scanf("%d", &array[i]);
    }
}
void calcMeanStdDev(int array[], int size, double *pMean, double *pStdDev){
    double sum = 0;
    for (int i = 0; i < size; i++){
        sum += (double)array[i]*1.0;
    }
    *pMean = sum/(size*1.0);
    sum = 0;
    for (int i = 0; i < size; i++){
        sum += pow((array[i] - *pMean),2);
    }
    *pStdDev = sqrt(sum/size);

}
void printResults(double mean, double stdDev){
    printf("The mean is %.2lf and the standard deviation is %.2lf\n", mean, stdDev);
}

int main(){
    double pMean = 0;
    double pStdDev = 0;
    int size;
    int array[size];
    size = getInt("Enter the array size:\n");
    getData("Enter the numbers:\n", array, size);
    calcMeanStdDev(array, size, &pMean, &pStdDev);
    printResults(pMean, pStdDev);

}