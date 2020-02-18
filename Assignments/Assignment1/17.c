// (16) Write a program to reverse a number.


#include "stdio.h"
#include "math.h"

#define ENTERED_NUMBER_TYPE unsigned long long

int main (void) {
    ENTERED_NUMBER_TYPE number;

    scanf("%llu", &number);

    // now assume our number is in this form
    // a1a2a3a4.....an, where a1, a2, a3 .... an are digits

    // this variable will be used to get the digits from the number
    ENTERED_NUMBER_TYPE temp = number;

    int counter = 0;


    // each step of the loop we will get the last digit and print it
    while (temp > 0) {
        //to get the last digit, we divide the number by 10
        // then the part after the decimal sign is the digit
        double divided_by_ten = (double)temp / 10;
        
        char last_digit = round((divided_by_ten - (ENTERED_NUMBER_TYPE)divided_by_ten) * 10);
        counter ++;
        temp = divided_by_ten;
    }

    printf("%d\n", counter);

    return 0;
}
