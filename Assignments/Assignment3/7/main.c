/*
 * main.c
 *
 *  Created on: Feb 27, 2020
 *      Author: m7med
 */


//(7) Write a program that computes the nth term of the arithmetic
//series:
//1, 3, 5, 7, 9, …
//Run the program to compute the 100th term of the given series.

#include <stdio.h>

void print_odd_series(unsigned int num_of_elements);

int main (void) {
	print_odd_series(100);

	return 0;
}

void print_odd_series(unsigned int num_of_elements) {
	int i = 0;
	int current_odd_number = 1;
	for(i = 0; i < num_of_elements; ++i) {
		printf("%d ", current_odd_number);
		current_odd_number += 2;
	}
	printf("\n");
}
