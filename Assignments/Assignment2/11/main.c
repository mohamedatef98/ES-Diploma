/*
 * main.c
 *
 *  Created on: Feb 19, 2020
 *      Author: m7med
 */


//(11) Write a C function that returns 1 if the input number is a power of 2
//and return 0 if the input number is power of 2.
//For example: 0, 2 and 16 are power of 2.
//1, 10 and 30 are not power of 2.

#include <stdio.h>
#include "math.h"

unsigned char is_power_of_2(int);

int main (void) {
	int num;
	printf("%s", "Enter a number: \n");
	scanf("%d", &num);

	printf("%d %d", num, is_power_of_2(num));

	return 0;
}

unsigned char is_power_of_2(int n) {
	float log_n = log2(n);
	return ((log_n - (int) log_n) == 0);
}
