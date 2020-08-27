// (9) Write a program that reads a student grade percentage
// and prints "Excellent" if his grade is greater than or equal
// 85, "Very Good" for 75 or greater; "Good" for 65, "Pass"
// for 50, "Fail" for less than 50.


#include "stdio.h"

int main (void) {

    char grade;
    scanf("%d", &grade);

    if (grade >= 85) printf("%s", "Excellent.");
    else if (grade >= 75) printf("%s", "Very Good.");
    else if (grade >= 60) printf("%s", "Good.");
    else if (grade >= 50) printf("%s", "Pass.");
    else printf("%s", "Fail.");

    printf("\n");
    
    return 0;
}
