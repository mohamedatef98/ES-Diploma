// (10) Write a program to make a simple calculator using
// switch-case. The calculator takes the operation
// (+ or – or * or /) and takes the two input arguments and
// print the results.


#include "stdio.h"

int main (void) {
    char op;
    float result;
    float number1, number2;

    scanf("%c", &op);

    scanf("%f%f", &number1, &number2);

    

    switch (op) {
    case '+':
        result = number1 + number2;
        break;
    case '-':
        result = number1 - number2;
        break;
    case '*':
        result = number1 * number2;
        break;
    case '/':
        result = number1 / number2;
        break;
    default:
        result = 0;
        break;
    }

    printf("%.2f %c %.2f = %.2f\n", number1, op, number2, result);

    return 0;
}
