/*
 * main.c
 *
 *  Created on: Mar 5, 2020
 *      Author: m7med
 */


#include <stdio.h>

void swap (int ** a, int ** b);

int main (void) {
	int a = 8, b = 10;

	int * a_ptr = &a, * b_ptr = &b;

	printf("*%p: %d, *%p: %d\n", a_ptr, *a_ptr, b_ptr, *b_ptr);

	swap(&a_ptr, &b_ptr);

	printf("*%p: %d, *%p: %d\n", a_ptr, *a_ptr, b_ptr, *b_ptr);
}

void swap (int ** a, int ** b) {
	int * temp;
	temp = *a;
	*a = *b;
	*b = temp;
}
