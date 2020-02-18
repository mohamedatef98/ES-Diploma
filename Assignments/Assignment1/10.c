// (10) Write a program to make a simple calculator using
// switch-case. The calculator takes the operation
// (+ or – or * or /) and takes the two input arguments and
// print the results.


#include "stdio.h"

int main (void) {
    char op;

    scanf("%c", &op);

    int number1, number2;

    scanf("%d%d", &number1, &number2);

    float result;

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
        result = (float)number1 / number2;
        break;
    default:
        result = 0;
        break;
    }

    printf("%d %c %d = %.2f\n", number1, op, number2, result);

    return 0;
}
