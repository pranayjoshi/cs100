// C program to swap two numbers using a third variable
#include <stdio.h>
int main(){
    int a, b, temp;
    printf("Enter two numbers sep. by space : ");
    scanf("%d%d",&a,&b);
    printf("Numbers before swapping \n a = %d\n b = %d",a,b);
    printf("\n");
    temp=a;
    a=b;
    b=temp;
    printf("Numbers after swapping \n a = %d\n b = %d",a,b);
    
    return 0;

}
