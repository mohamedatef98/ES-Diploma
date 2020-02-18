// (19) Write a program to display inverted half pyramid using
// stars pattern.
// * * * * *
// * * * *
// * * *
// * *
// *


#include "stdio.h"

#define NUM_ROWS 100


int main (void) {

    int i;
    for (i = 0; i < NUM_ROWS; i++){
        int j;
        int n = NUM_ROWS - i;
        for (j = 0; j < n; j++)
            printf("*");
        printf("\n");
        
    }
    

    return 0;
}
