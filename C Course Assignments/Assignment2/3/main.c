/*
 * main.c
 *
 *  Created on: Feb 18, 2020
 *      Author: engmo
 */


//(3) Write a C Function that check if the number if positive or negative.


#include <stdio.h>

char is_negative(int);

int main (void) {

	int x;

	x = 1;
	printf("%d %d\n", x, is_negative(x));

	x = -1;
	printf("%d %d\n", x, is_negative(x));

	x = 0;
	printf("%d %d\n", x, is_negative(x));

	x = 10242;
	printf("%d %d\n", x, is_negative(x));

	x = -6;
	printf("%d %d\n", x, is_negative(x));

	return 0;
}

char is_negative(int x) {
	return x < 0;
}
