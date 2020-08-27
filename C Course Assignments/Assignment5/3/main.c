/*
 * main.c
 *
 *  Created on: Mar 13, 2020
 *      Author: m7med
 */


//3. C function to add two complex numbers by passing
//two structure to a function and display the results.

#include <stdio.h>

typedef struct {
	float real;
	float img;
} Complex;

Complex sum_complex(const Complex c1, const Complex c2);

int main (void) {
	Complex c1, c2, c3;

	printf("Enter Real and Img Parts of C1.\n");
	scanf("%f%f", &c1.real, &c1.img);

	printf("Enter Real and Img Parts of C2.\n");
	scanf("%f%f", &c2.real, &c2.img);

	c3 = sum_complex(c1, c2);

	printf("The Sum is %.4f + %.4fj.\n", c3.real, c3.img);

	return 0;
}

Complex sum_complex(const Complex c1, const Complex c2) {
	Complex c;

	c.real = c1.real + c2.real;
	c.img = c1.img + c2.img;

	return c;
}
