// (18) Write a program to display half pyramid using stars
// pattern.
// *
// * *
// * * *
// * * * *
// * * * * *


#include "stdio.h"

#define NUM_ROWS 5


int main (void) {

    int i;
    for (i = 0; i < NUM_ROWS; i++){
        int j;
        for (j = 0; j < i + 1; j++)
            printf("*");
        printf("\n");
        
    }
    

    return 0;
}
