#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int getInt(char *prompt);
void getData(int n, int *array);
void calcMeanAndStdDev(int n, int *array, double *pMean, double *pStdDev);

int main(void) {
    int size = getInt("Enter a positive integer for array size: ");

    printf("Enter %d integers:\n", size);
    int *array = malloc(size * sizeof(int));
    getData(size, array);

    double mean, std_dev;
    calcMeanAndStdDev(size, array, &mean, &std_dev);

    printf("Mean is %g\n", mean);
    printf("Standard deviation is %g\n", std_dev);

    return 0;
}

// Print out the prompt, scan in an integer and return it.
int getInt(char *prompt) {
    printf("%s", prompt);
    int n;
    scanf("%d", &n);
    return n;
}

// Do not change anything above this line
//
void getData(int n, int *array){
    // add your code here
    // No [] allowed in this function
    array = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++){
        scanf("%d", &array[i]);
    }
}
void calcMeanStdDev(int n, int *array, , double *pMean, double *pStdDev){
    double sum = 0;
    for (int i = 0; i < n; i++){
        sum += (double)array[i]*1.0;
    }
    *pMean = sum/(n*1.0);
    sum = 0;
    for (int i = 0; i < n; i++){
        sum += pow((array[i] - *pMean),2);
    }
    *pStdDev = sqrt(sum/n);
}
