/*
 * main.c
 *
 *  Created on: Feb 21, 2020
 *      Author: m7med
 */


//(15) Write a C function to count the number of 1’s in an unsigned 32-bit
//integer.

#include <stdio.h>

unsigned int count_ones(unsigned int);

int main (void) {
	unsigned int number;

	printf("%s", "Enter a number: \n");
	scanf("%d", &number);

	printf("%d", count_ones(number));

	return 0;
}


unsigned int count_ones(unsigned int n) {
	unsigned int count = 0;
	unsigned int mask = 0x80000000;

	char i;
	for(i = 0; i < 32; ++i) {
		if ((mask & (n << i)) != 0) count ++;
	}

	return count;
}
