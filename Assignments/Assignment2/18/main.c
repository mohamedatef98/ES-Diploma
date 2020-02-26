/*
 * main.c
 *
 *  Created on: Feb 26, 2020
 *      Author: m7med
 */


//(18) Given a positive integer z, check if z can be written as 𝑝𝑞, where p
//and q are positive integers than 1, if z can be written as 𝑝𝑞 return 1 else
//return 0.
//Description:
//A positive integer that needs to be determined if it can be expressed as a
//power of square number.

#include <stdio.h>
#include <math.h>

double log_base(int, int);
int find_base(int);

int main (void) {
	int x;
	int q;

	printf("Enter a number that will be checked if it can be expressed as p to the power of q where p and q isn't 1: \n");
	scanf("%d", &x);

	q = find_base(x);
	q != -1 ?
			printf("there exists p such that p ^ %d = %d", q, x) :
			printf("No, %d cannot be expressed as p ^ q", x);

	printf("\n");
}

double log_base(int x, int base) {
	return log(x) / log(base);
}

int find_base(int n) {
	int p;
	double q;
	for(p = 2; p < n; ++p){
		q = log_base(n, p);
		if (q - (int)q == 0) return q;
	}
	return -1;
}
