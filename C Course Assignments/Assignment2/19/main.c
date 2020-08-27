/*
 * main.c
 *
 *  Created on: Feb 19, 2020
 *      Author: m7med
 */


//(19) Write a C function that return 0 if a given number is a power of 3,
//otherwise return 1.

#include <stdio.h>
#include <math.h>

float log_base_n(int x, int n);
unsigned char is_power_3(int x);

int main (void) {
	int num;
	printf("%s", "Enter a Number: \n");
	scanf("%d", &num);

	printf("%d %d", num, !is_power_3(num));

	return 0;
}

float log_base_n(int x, int base) {
	return log(x) / log(base);
}

unsigned char is_power_3(int x) {
	float log_x = log_base_n(x, 3);
	return ((log_x - (int)log_x) == 0);
}
