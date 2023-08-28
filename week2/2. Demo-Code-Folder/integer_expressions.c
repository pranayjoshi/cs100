//
//  week2a.c
//  CS100F23
//
//  Created by Don Yessick and chatGPT on 8/27/23.
//
#include <stdio.h>

//prototypes -- the functions are defined elsewhere (below main)
int operatorPrecedence(void);
int integerDivision(void);
int automaticConversion(void);

int main(void) {
    printf("Hello, World!\n");
    return operatorPrecedence();
    return integerDivision();
    return automaticConversion();
    return 0;
}

/*------------------------------------------------------------------------------------
 The first function demonstrates the concept of operator precedence
 by performing various arithmetic operations using different operators (+, -, /, *, %).
 The parentheses control the order in which these operations are performed.
 
 The second function shows integer division and modulus operations.
 It calculates the quotient and remainder when dividing two integers.
 
 The third function highlights automatic conversion between double and int types.
 When performing arithmetic operations involving mixed data types, automatic
 type conversion occurs based on the rules of C's type promotion and conversion.
 --------------------------------------------------------------------------------------*/

int operatorPrecedence(void) {
    printf("operatorPrecedence!\n");
    int a = 10, b = 5, c = 2;
    int result = a + b * c - (a + b) / c % b;
    printf("Result: %d\n", result);
    return 0;
}

int integerDivision(void) {
    printf("integerDivision!\n");
    int numerator = 17, denominator = 4;
    int quotient = numerator / denominator;
    int remainder = numerator % denominator;
    
    printf("Integer division result: %d\n", quotient);
    printf("Remainder: %d\n", remainder);
    
    return 0;
}

int automaticConversion(void) {
    printf("automaticConversion!\n");
    int num1 = 5;
    double num2 = 2.5;
    
    double result1 = num1 + num2; // Automatic conversion of 'num1' to double
    int result2 = num1 * num2;    // Automatic conversion of 'num2' to int
    
    printf("Result 1: %lf\n", result1);
    printf("Result 2: %d\n", result2);
    
    return 0;
}