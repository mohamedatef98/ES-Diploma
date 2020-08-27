/*
 * main.c
 *
 *  Created on: Mar 5, 2020
 *      Author: m7med
 */


//(11) Write a c program that SWAP the value of the two 16-bits of 32-bits integer number.
#include <stdio.h>

unsigned int swap(unsigned int x);

int main (void) {
	unsigned int x = 0xAABBCCDD, swapped_x;
	printf("%x\n", x);

	swapped_x = swap(x);

	printf("%x", swapped_x);
}

unsigned int swap(unsigned int x) {
	return x << 16 | x >> 16;
}
