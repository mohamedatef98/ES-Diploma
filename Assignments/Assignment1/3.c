// (3) Write a program for converting temperature from
// degrees Celsius to degrees Fahrenheit,
// given the formula:
// F = C x 9 / 5 + 32


#include "stdio.h"

double to_fahrenheit (double);

int main (void) {
    int celsius = 32;

    printf("%d Degrees Celsius is %.2f Degrees Fahrenheit.\n", celsius, to_fahrenheit(celsius));

    return 0;
}

double to_fahrenheit (double celsius) {
    return celsius * 9 / 5 + 32;
}
