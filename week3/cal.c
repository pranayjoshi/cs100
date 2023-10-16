// C program to calculate artithmetic expression
#include<stdio.h>
main(){
    char opt;
    float num1, num2;
    printf("Enter one of the operators (+,-,*,/) : ");
    scanf("%c",&opt);
    printf("Enter two numbers sep. by space: ");
    scanf("%f%f", &num1,&num2);
    

    switch(opt){
        case '+':
            printf("%f + %f = %f",num1,num2,num1+num2);
            break;
        case '-':
            printf("%f - %f = %f",num1,num2,num1-num2);
            break;
        case '*':
            printf("%f x %f = %f",num1,num2,num1*num2);
            break;
        case '/':
            printf("%f / %f = %f",num1,num2,num1/num2);
            break;
        default:
            printf("Invalid operator passed as arguemnet");
            break;
    }
}
