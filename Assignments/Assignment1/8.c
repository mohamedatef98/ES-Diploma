// (8) Write a program that reads a positive integer and
// checks if it is a perfect square.


#include "stdio.h"
#include "math.h"

int main (void) {

    int number;
    
    scanf("%d", &number);

    // the square root of the entered number
    float root_number = sqrt(number);

    // check if the calculated square root isn't a float
    char is_square = (int)root_number == root_number;

    is_square == 1
        ? printf("%d is a perfect square.\n", number)
        : printf("%d isn't a perfect square.\n", number);

    return 0;
}
