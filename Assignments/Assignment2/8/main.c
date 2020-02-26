/*
 * main.c
 *
 *  Created on: Feb 19, 2020
 *      Author: engmo
 */


//(8)Write a C Function that display Prime Numbers between Intervals (two
//numbers) by Making Function.


#include <stdio.h>
#include "math.h"

unsigned char is_prime(int n);
void print_primes_between(int n1, int n2);

int main (void) {

	int num1, num2;

	printf("%s", "Enter The first number of the interval: \n");
	scanf("%d", &num1);

	printf("%s", "Enter the Last number of the interval: \n");
	scanf("%d", &num2);

	print_primes_between(num1, num2);

	return 0;
}

unsigned char is_prime(int num) {
     if (num <= 1) return 0;
     if (num % 2 == 0 && num > 2) return 0;
     for(int i = 3; i < num / 2; i++) {
         if (num % i == 0)
             return 0;
     }
     return 1;
}

void print_primes_between(int n1, int n2) {
	int i = n1;
	for(i = n1; i <= n2; ++i)
		if (is_prime(i)) printf("%d\n", i);
}
