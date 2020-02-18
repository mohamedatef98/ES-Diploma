// (1) Write a program that take two integers from the user
// and print the results of this equation:
// Result = ((num1 + num2) * 3) – 10


#include "stdio.h"

int main (void) {
    int number1, number2;

    scanf("%d", &number1);
    scanf("%d", &number2);

    int result = (number1 + number2) * 3 - 10;

    printf("%d", result);

    return 0;
}
