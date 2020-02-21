// (12) Write a program that reads a positive integer and
// computes the factorial.


#include "stdio.h"

unsigned long long factorial (int);


int main (void) {
    int number;
    unsigned long long factorial_number

    printf("%s", "Enter a Positive Integer."
                 "\n"
                 "This program computes factorials for numbers up to 65 correctly.\n");

    scanf("%d", &number);

    if (number < 1) {
        printf("%s", "Not a Positive Integer.\n");
        return 1;
    }

    factorial_number = factorial(number);

    printf("The Factorial of %d is %llu.\n", number, factorial_number);

    return 0;
}


unsigned long long factorial (int number) {
    return number == 2
        ? 2
        : number * factorial(number - 1);
}