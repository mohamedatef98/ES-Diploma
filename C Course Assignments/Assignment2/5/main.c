/*
 * main.c
 *
 *  Created on: Feb 18, 2020
 *      Author: engmo
 */


//(5) Write a C function to check if the input is an even number or an odd
//number, if even number return 0 if odd number return 1.
//Example:
//Input 7, Output = 1 (Odd)
//Input 6, Output = 0 (Even)


#include <stdio.h>

unsigned char is_odd(int x);

int main (void) {

	int num;
	scanf("%d", &num);

	printf("%d\n", is_odd(num));

	return 0;
}

unsigned char is_odd(int x) {
	return x%2 != 0;
}
