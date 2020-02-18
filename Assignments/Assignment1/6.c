// (6) Write a program that print the relation between two
// integer number if those numbers are equal, not equal and
// which one contain the higher value.

#include "stdio.h"

inline int min (int, int);
inline int max (int, int);

int main (void) {

    int number1, number2;
    
    scanf("%d", &number1);
    scanf("%d", &number2);

    if (number1 == number2) printf("The Two numbers are equal %d.\n", number1);
    
    else printf("%d is bigger than %d.\n", max(number1, number2), min(number1, number2));

    return 0;
}

inline int min (int a, int b) {
    return a < b ? a : b;
}

inline int max (int a, int b) {
    return a > b ? a : b;
}
