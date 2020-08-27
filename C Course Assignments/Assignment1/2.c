// (2) Write a program that print your name and your grade
// in a new line.


#include "stdio.h"

#define MY_NAME "Mohamed"
#define MY_GRADE 98.5

int main (void) {
    printf("My name is: %s."
           "\n"
           "My Grade is: %f."
           "\n", MY_NAME, MY_GRADE);
    
    return 0;
}
