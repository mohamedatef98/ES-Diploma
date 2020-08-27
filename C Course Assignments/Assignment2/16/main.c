/*
 * main.c
 *
 *  Created on: Feb 21, 2020
 *      Author: m7med
 */


//(16) Write a C function to count the number of 1’s in an unsigned 8-bit
//integer.

#include <stdio.h>

unsigned char count_ones(unsigned char);

int main (void) {
	int number;

	printf("%s", "Enter a number: \n");
	scanf("%d", &number);

	printf("%d", count_ones(number));

	return 0;
}


unsigned char count_ones(unsigned char n) {
	unsigned char count = 0;
	unsigned char mask = 0x80;

	char i;
	for(i = 0; i < 8; ++i) {
		if ((mask & (n << i)) != 0) count ++;
	}

	return count;
}
