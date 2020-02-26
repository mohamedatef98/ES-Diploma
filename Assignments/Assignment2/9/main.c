/*
 * main.c
 *
 *  Created on: Feb 19, 2020
 *      Author: m7med
 */


//(9)Write a C Function that swaps the value of two integer numbers.

#include <stdio.h>

void swap(int * n1, int * n2);

int main (void) {
	int n1, n2;

	printf("%s", "Enter two numbers: \n");
	scanf("%d%d", &n1, &n2);

	swap(&n1, &n2);

	printf("Swapped %d %d.\n", n1, n2);

	return 0;
}

void swap(int *n1, int *n2) {
	int temp = *n1;
	*n1 = *n2;
	*n2 = temp;
}
