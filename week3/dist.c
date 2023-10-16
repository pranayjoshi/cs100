// C program to find dist between two points on a cartesian place
#include<stdio.h>
#include<math.h>
int main(){
    float x1,y1,x2,y2,dist;
    printf("Enter x1 coordinate : ");
    scanf("%f",&x1);
    printf("Enter y1 coordinate : ");
    scanf("%f",&y1);
    printf("Enter x2 coordinate : ");
    scanf("%f",&x2);
    printf("Enter y2 coordinate : ");
    scanf("%f",&y2);
    dist = ((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1));
    printf("Distance between the said points is : %.4f",sqrt(dist));
    return 0;
}
