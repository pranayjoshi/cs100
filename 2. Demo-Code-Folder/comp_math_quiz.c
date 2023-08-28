#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//number of correct responses required
#define REQUIRED 7
/*
 This function takes two operands and an operator as input
 and performs the corresponding arithmetic operation.
 */
int calculate(int a, char op, int b){
    switch (op) {
        case '+': return a+b;
        case '-': return a-b;
        case '*': return a*b;
        case '/': return a/b;
        case '%': return a%b;
    }
    return 0;
}
/*
 This function determines whether
 left-to-right or right-to-left evaluation
 should be performed based on the precedence of operators.
 */
int computeLR(char op1, char op2) {
    return op1 == '*' || op1 == '/' || op1 == '%' || op2 == '+' || op2 == '-';
}
/*
 Function to evaluate the expression
 */
int evaluate(int a, char op1, int b, char op2, int c){
    int result;
    if (computeLR(op1, op2)){
        int leftFirst = calculate(a, op1, b);
        result = calculate(leftFirst, op2, c);
    }
    else {
        int rightFirst = calculate(b, op2, c);
        result = calculate(a, op1, rightFirst);
    }
    return result;
}
/*
 Function to present a question to the user and validate the answer
 This function presents a question to the user,
 reads their answer,
 computes the result, and
 compares it to the user's answer.
 */
int presentQuestion(int a, char op1, int b, char op2, int c){
    printf("\n%d %c %d %c %d = ? ", a, op1, b, op2, c);
    int answer;
    while (1 != scanf("%d", &answer))
        if (scanf("%*s")==-1)
            exit(1);
    int correct = evaluate(a, op1, b, op2, c);
    if (answer == correct){
        printf("Correct!\n");
        return 1;
    }
    else {
        printf("Incorrect: %d\n", correct);
        return 0;
    }
}
/*
 The main function generates a set of mathematical expressions
 using various operators and operands. The expressions are presented
 to the user as questions, and the user's answers are checked for correctness.
 */
int main() {
    char * operatorCombo[] = {
        "-/", "*+",
        "-%", "/+",
        "-*", "%+",
        "/-", "+*",
        "%-", "+/",
        "*-", "+%",
        "--", "//",
    };
    //New questions every time we play
    srand((int)time(NULL)); // Seed the random number generator
    int counter = 0;
    int score = 100;
    while (counter < REQUIRED && score > 0) {
        //pick two random operators
        char * selectedCombo = operatorCombo[rand() % 14];
        char op1 = selectedCombo[0];
        char op2 = selectedCombo[1];
        //Pick three nums. We avoid zero for b and c
        //to prevent div by zero errors, also we require c > 1
        //to reduce problems ending in "* 1", "/ 1", or  "% 1"
        int a = rand() % 13;  //0..12
        int b = a;
        while (b == a)
            b = rand() % 12+1;//1..12, && different from a
        int c = b;
        while (c == b)
            c = rand() % 11+2;//2..12, && different from b
        int answeredCorrect = presentQuestion(a, op1, b, op2, c);
        if (answeredCorrect)
            counter += 1;
        else {
            score -= 100/REQUIRED;
            if (score < 0) score = 0;
        }
    }
    printf("Your score is %d\n\n", score);
    return 0;
}