#include <stdio.h>

int main() {
    double weights[5]; // Create an array to store the weights
    double max = 0.0;
    double total = 0.0;

    // Prompt the user to enter five numbers (weights)
    for (int i = 0; i < 5; i++) {
        printf("Enter weight %d:\n", i + 1);
        scanf("%lf", &weights[i]);
    }

    printf("You entered: ");
    for (int i = 0; i < 5; i++) {
        printf("%0.2lf ", weights[i]);
        total += weights[i];
        if (weights[i]>max){
            max=weights[i];
        }
    }
    printf("\n\n");

    printf("Total weight: %0.2lf\nAverage weight: %0.2lf\nMax weight: %0.2lf\n", total, total/5, max);

    return 0;
}