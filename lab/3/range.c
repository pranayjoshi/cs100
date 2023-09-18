#include <stdio.h>
#include <limits.h>

int main() {
    int num, min = INT_MAX, max = INT_MIN;

    while (scanf("%d", &num) != EOF) {
        if (num < min) {
            min = num;
        }
        if (num > max) {
            max = num;
        }
    }
    int range = max - min;
    printf("Range of input = %d\n", range);

    return 0;
}