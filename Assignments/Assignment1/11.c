// (11) Print sum of first 100 integers. (With data validation)


#include "stdio.h"


int main (void) {

    int sum = 0;
    int n;

    for (n = 0; n < 100; ++n, sum += n);

    printf("The Sum of the first %d integer is %d.\n", n - 1, sum);

    return 0;
}
