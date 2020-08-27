/*
 * main.c
 *
 *  Created on: Feb 18, 2020
 *      Author: engmo
 */

//(1) Write a C Function that prints the cube of any number.

#include <stdio.h>

int cube (int x);

int main (void) {

	int x = 3;

	printf("%d cubed is %d\n", x, cube(x));

	return 0;
}

int cube (int x) {
	return x * x * x;
}
