/*
 * main.c
 *
 *  Created on: Mar 5, 2020
 *      Author: m7med
 */


//(7) C function to swap two numbers using bitwise
//operation and call it using pointer to function.
#include <stdio.h>

void swap(int * const a, int * const b);
void with_arguments(int * const a, int * const b, void (* const func) (int * const, int * const));

int main (void) {
	int a = 5, b = 10;
	printf("%d, %d\n", a, b);

	with_arguments(&a, &b, swap);
	printf("%d, %d\n", a, b);
}

void swap(int * const a, int * const b) {
	*a = *a ^ *b;
	*b = *a ^ *b;
	*a = *a ^ *b;
}

void with_arguments(int * const a, int * const b, void (* const func) (int * const, int * const)) {
	func(a, b);
}
