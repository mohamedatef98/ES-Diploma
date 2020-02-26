/*
 * main.c
 *
 *  Created on: Feb 18, 2020
 *      Author: engmo
 */


//(6) Write C Function that converts the any letter from lowercase to
//uppercase.


#include <stdio.h>

unsigned char to_uppercase(unsigned char c);

int main (void) {

	char c;

	c = 'o';
	printf("%c %c\n", c, to_uppercase(c));

	c = 't';
	printf("%c %c\n", c, to_uppercase(c));

	c = '8';
	printf("%c %c\n", c, to_uppercase(c));

	c = 'A';
	printf("%c %c\n", c, to_uppercase(c));

	c = 'y';
	printf("%c %c\n", c, to_uppercase(c));

	return 0;
}

unsigned char to_uppercase(unsigned char c) {
	return (c >= 'a' && c <= 'z') ? c - 'a' + 'A' : c;
}
