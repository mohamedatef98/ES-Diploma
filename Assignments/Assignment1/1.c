// (1) Write a program that take two integers from the user
// and print the results of this equation:
// Result = ((num1 + num2) * 3) – 10


#include "stdio.h"

int main (void) {
    int number1, number2, result;
	
    printf("%s", "Enter the first Number: \n");
    scanf("%d", &number1);

    printf("%s", "Enter the second Number: \n");
    scanf("%d", &number2);

    result = (number1 + number2) * 3 - 10;

    printf("%d\n", result);

    return 0;
}
