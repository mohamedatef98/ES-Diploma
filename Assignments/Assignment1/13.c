// (13) Write a program that reads a positive integer and
// checks if it is a prime.


#include "stdio.h"
#include "math.h"

char is_prime(int);

int main (void) {

    int number;

    scanf("%d", &number);

    char c = is_prime(number);

    c ? printf("%d is prime.\n", number)
        : printf("%d isn't prime.\n", number);


    return 0;
}

/**
 * This function returns 0 value if the given number isn't a prime,
 * postive value otherwise.
 * 
 * It accepts a number as its only parameter,
 * and checks all numbers from 2 to square root number,
 * if any number between this ranges divides the given number completely,
 * then the given number isn't a prime.
 * 
 */
char is_prime (int number) {
    int square_root = sqrt(number);
    int n;

    for(n = 2; n <= square_root; ++n)
        if (number % n == 0) return 0;
    return 1;
}
