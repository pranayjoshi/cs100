#include <stdio.h>

double trackRiverWaterLevelAvgRainfall(int n, int *rainfall, int dailyAbsorptionInches, int floodStageInches, int *floodDays, int *droughtDays) {
    int riverLevel = 0;  // Initial river water level
    int totalRainfall = 0;

    *floodDays = 0;
    *droughtDays = 0;

    for (int i = 0; i < n; i++) {
        riverLevel += rainfall[i] - dailyAbsorptionInches;

        // Ensure the river level doesn't go below zero
        if (riverLevel < 0) {
            riverLevel = 0;
        }

        totalRainfall += rainfall[i];

        if (riverLevel >= floodStageInches) {
            (*floodDays)++;
        }

        if (riverLevel == 0) {
            (*droughtDays)++;
        }
    }

    return (double)totalRainfall / n;
}

int main() {
    int N;
    int dailyAbsorptionInches, floodStageInches;

    scanf("%d", &N);
    scanf("%d %d", &dailyAbsorptionInches, &floodStageInches);

    int rainfall[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &rainfall[i]);
    }

    int floodDays, droughtDays;
    double avgRainfall = trackRiverWaterLevelAvgRainfall(N, rainfall, dailyAbsorptionInches, floodStageInches, &floodDays, &droughtDays);

    printf("Flood Days: %d\n", floodDays);
    printf("Drought Days: %d\n", droughtDays);
    printf("Average Rainfall: %.2lf inches\n", avgRainfall);

    return 0;
}
