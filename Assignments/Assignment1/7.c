// (7) Write a program that takes three integers, and prints
// out the smallest number.


#include "stdio.h"

inline int min (int, int);

int main (void) {
    int number1, number2, number3, smallest;

    scanf("%d%d%d", &number1, &number2, &number3);

    smallest = min(min(number1, number2), number3);

    printf("The smallest is %d.\n", smallest);

    return 0;
}

inline int min (int a, int b) {
    return a < b ? a : b;
}
