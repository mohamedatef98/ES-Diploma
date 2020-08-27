// (8) Write a program that reads a positive integer and
// checks if it is a perfect square.


#include "stdio.h"
#include "math.h"

int main (void) {

    int number;
    int root_number;
    
    scanf("%d", &number);

    // the square root of the entered number
    // stored in an int (to implicitly convert the float to int)
    root_number = sqrt(number);

    // check if the calculated square root (as int) times itself 
    // equals the number
    number == root_number * root_number
        ? printf("%d is a perfect square.\n", number)
        : printf("%d isn't a perfect square.\n", number);

    return 0;
}
