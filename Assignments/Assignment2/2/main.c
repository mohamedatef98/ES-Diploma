/*
 * main.c
 *
 *  Created on: Feb 18, 2020
 *      Author: engmo
 */


//(2) Write a C Function that takes one character and checks if it alphabet
//or not.

#include <stdio.h>

char is_alphabetic(unsigned char c);

int main (void) {

	char c;


	c = '4';
	printf("%c %d\n", c, is_alphabetic(c));


	c = 't';
	printf("%c %d\n", c, is_alphabetic(c));

	c = '\a';
	printf("%c %d\n", c, is_alphabetic(c));

	c = 'V';
	printf("%c %d\n", c, is_alphabetic(c));

	c = 54;
	printf("%c %d\n", c, is_alphabetic(c));

	return 0;
}


char is_alphabetic(unsigned char c) {
	return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
}
