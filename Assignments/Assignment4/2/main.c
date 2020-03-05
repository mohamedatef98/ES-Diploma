/*
 * main.c
 *
 *  Created on: Mar 5, 2020
 *      Author: m7med
 */


//(2) C Program to find length of a given string using pointer.

#include <stdio.h>
#define STR_MAX_SIZE 50

unsigned int string_length(const char * const str);

int main (void) {
	char str[STR_MAX_SIZE];

	printf("Enter a String: \n");
	scanf("%49s", str);

	printf("The Length of the given string is %u", string_length(str));
	return 0;
}

unsigned int string_length(const char * const str) {
	unsigned int i = 0;

	while(str[i] != '\0') i++;

	return i;
}
