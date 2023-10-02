#include <stdio.h>

int getInt(char prompt[]);
void getArray(int size, int x[]);
double findMidRange(int size, int x[], int *pNumLess, int *pNumMore);

int main(void)
{
	int size=getInt("Enter the array size:\n");
	int array[size];
	getArray(size, array);
	int count_less; 
	int count_more; 
	double midrange=findMidRange(size, array, &count_less, &count_more); 
	printf("The midrange is %lf\n", midrange);
	printf("%d out of %d integers are less than the midrange\n", count_less, size);
	printf("%d out of %d integers are greater than the midrange\n", count_more, size);
	return 0;
}

int getInt(char prompt[])
{
    int x;
    printf("%s", prompt);
    scanf("%d", &x);
    return x;    
}

void getArray(int size, int x[])
{
    printf("Enter %d integers:\n", size);
    for (int i=0; i<size; i++) {
        scanf("%d", &x[i]);
    }
}

// Do not change anything above this line

double findMidRange(int size, int x[], int *pNumLess, int *pNumMore)
{
    *pNumLess = 0;
    *pNumMore = 0;
    double midrange = 0.0;
    int min = x[0];
    int max = x[0];
    for (int i=0; i<size; i++) {
        if (min > x[i]) min = x[i];
        if (max < x[i]) max = x[i];
    }
    midrange = (double)(min + max)/2;
    for (int i=0; i<size; i++) {
        if ((double)x[i] < midrange){
           (*pNumLess)++;
        }
        else if(x[i] > midrange){
           (*pNumMore) ++;
        }
    }
    
    return midrange;

}