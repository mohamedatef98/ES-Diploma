/*
 * main.c
 *
 *  Created on: Feb 18, 2020
 *      Author: engmo
 */


//(7) Write a C Function that reads two integers and checks if the first is
//multiple of the second.


#include <stdio.h>

unsigned char is_multiple(int a, int b);

int main (void) {
	int a, b;

	a = 10, b = 2;
	printf("%d %d %d\n", a, b, is_multiple(a, b));

	a = 1, b = 2;
	printf("%d %d %d\n", a, b, is_multiple(a, b));

	a = 10, b = 5;
	printf("%d %d %d\n", a, b, is_multiple(a, b));

	a = -4, b = 2;
	printf("%d %d %d\n", a, b, is_multiple(a, b));

	a = 37, b = 6;
	printf("%d %d %d\n", a, b, is_multiple(a, b));


	return 0;
}

unsigned char is_multiple(int a, int b) {
	return a % b == 0;
}
