/*
 * main.c
 *
 *  Created on: Feb 20, 2020
 *      Author: m7med
 */


//(13) In this challenge write a function to add two floating numbers.
//Determine the integer floor of the sum. The floor is the truncated float
//value, anything after the decimal point is dropped. For instance
//floor(1.1+3.05)=floor(4.15)=4


#include <stdio.h>

int sum_and_floor(float, float);

int main (void) {
	float a, b;

	printf("%s", "Enter Two Float Numbers. \n");
	scanf("%f%f", &a, &b);

	printf("%d\n", sum_and_floor(a, b));

	return 0;
}

int sum_and_floor(float a, float b) {
	return (int)(a + b);
}
