// (20) Write a program to display a full pyramid using stars
// pattern.
//     *
//    ***
//   *****
//  *******
// *********

#include "stdio.h"

#define NUM_ROWS 9


int main (void) {

    // each row is composed from 
    // 1. X number of blank spaces
    // 2. Y number of *
    // 3. Again, X Number of blank spaces
    //
    // (X spaces) (Y ***) (X spaces)
    // where X + Y + X = 1 + 2 * (NUM_ROWS - 1)

    int line_length = 1 + 2 * (NUM_ROWS - 1);


    // each row
    int i;
    for (i = 0; i < NUM_ROWS; i++){

        //Number of * (Y)
        int y = 1 + 2 * i;

        //Number of blank spaces each side (X)
        int x = (line_length - y) / 2;

        int j;

        //draw X blanks
        for(j = 0; j < x; ++j) printf("%s", " ");

        //draw Y *
        for(j = 0; j < y; ++j) printf("%s", "*");

        //draw X blanks
        //for(j = 0; j < x; ++j) printf("%s", " ");

        printf("%s", "\n");
        
    }
    

    return 0;
}
