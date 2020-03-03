/*
 * main.c
 *
 *  Created on: Feb 27, 2020
 *      Author: m7med
 */


//(9) The sequence of numbers 1, 1, 2, 3, 5, 8, 13, … is called
//Fibonacci numbers; each is the sum of the preceding 2. Write a
//program which given n, returns the nth Fibonacci number.
//- with for/while
//- with recursion

#include <stdio.h>

unsigned long long fib_recursion (unsigned int term);
unsigned long long fib_iterative (unsigned int term);

int main (void) {
	printf("fib(10) using recursive method\n");
	printf("fib(10) = %llu\n", fib_recursion(15));

	printf("\n");

	printf("fib(10) using iterative method\n");
	printf("fib(10) = %llu\n", fib_iterative(15));
}

unsigned long long fib_recursion (unsigned int term) {
	if (term == 0 || term == 1) return term;
	return fib_recursion(term - 1) + fib_recursion(term - 2);
}

unsigned long long fib_iterative (unsigned int term) {
	unsigned long long fib_term_minus_one, fib_term_minus_two, fib_current;
	unsigned int i;
	fib_term_minus_one = 1;
	fib_term_minus_two = 0;
	fib_current = 1;
	for(i = 2; i < term; ++i) {
		fib_term_minus_two = fib_term_minus_one;
		fib_term_minus_one = fib_current;
		fib_current = fib_term_minus_one + fib_term_minus_two;
	}

	return fib_current;

}
