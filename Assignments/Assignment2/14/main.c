/*
 * main.c
 *
 *  Created on: Feb 19, 2020
 *      Author: m7med
 */


//(14) Write a C Function that calculate the Fibonacci series using recursive
//method.
//The Fibonacci Series : 0,1,1,2,3,5,8,13,21,…

#include <stdio.h>

unsigned long long fib(unsigned int);

int main (void) {
	unsigned int num;

	printf("%s", "Enter number to calculate the Fibonacci series for: \n");
	scanf("%d", &num);

	printf("%llu", fib(num));
	return 0;
}

unsigned long long fib(unsigned int x) {
	return x == 2 ? 1 :
			x == 1 ? 0 :
					fib(x - 1) + fib(x - 2);
}
