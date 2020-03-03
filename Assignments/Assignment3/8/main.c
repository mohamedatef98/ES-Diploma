/*
 * main.c
 *
 *  Created on: Feb 27, 2020
 *      Author: m7med
 */


//(8) Write a program that computes the nth term of the geometric
//series:
//1, 3, 9, 27, …
//Run the program to compute the 10th term of the given series

#include <stdio.h>

void print_multiple_three_series(unsigned int num_of_elements);

int main (void) {
	print_multiple_three_series(10);

	return 0;
}

void print_multiple_three_series(unsigned int num_of_elements) {
	int i = 0;
	int current_multiple_three = 1;
	for(i = 0; i < num_of_elements; ++i) {
		printf("%d ", current_multiple_three);
		current_multiple_three *= 3;
	}
	printf("\n");
}
