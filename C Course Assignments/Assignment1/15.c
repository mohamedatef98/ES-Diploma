// (15) Write a program to calculate the power of a number.
// The number and its power are input from user.


#include "stdio.h"
#include "math.h"

int main (void) {

    int number, power;
    scanf("%d%d", &number, &power);

    printf("%d to the power of %d is %.0f", number, power, pow(number, power));

    return 0;
}
