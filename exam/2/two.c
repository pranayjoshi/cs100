#include <stdio.h>
#include <math.h>

double fixUnitsReportCelRangeAvg(int n, int *x, int *lowCelValue, int *highCelValue);

int main(void)
{

    printf("How many measurements?\n");
    int n;
    scanf("%d", &n);
    printf("Enter %d measurements:\n", n);
    int x[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &x[i]);
    }
    int lowCelValue;
    int highCelValue;
    double avg = fixUnitsReportCelRangeAvg(n, x, &lowCelValue, &highCelValue);
    printf("The average of good readings is %.2lf\n", avg);
    printf("%d lowest Celsius value\n", lowCelValue);
    printf("%d highest Celsius value\n", highCelValue);

    return 0;
}

double fixUnitsReportCelRangeAvg(int n, int *x, int *lowCelValue, int *highCelValue)
{
    int sum = 0;
    int count = 0;
    int low = x[0];
    int high = x[0];
    for (int i = 0; i < n; i++)
    {
        if (x[i] < 0 || x[i] > 100)
        {
            x[i] = (x[i] - 32) / 1.8000;
        }
        if (x[i] < low)
        {
            low = x[i];
        }
        if (x[i] > high)
        {
            high = x[i];
        }
        
        sum += x[i];
        count++;
    }
    *lowCelValue = low;
    *highCelValue = high;
    if (count == 0)
    {
        return 0;
    }
    return (double)sum / count;
    return 0;
}
