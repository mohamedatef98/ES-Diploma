/*
 * main.c
 *
 *  Created on: Mar 1, 2020
 *      Author: m7med
 */


//(14) Write a function to reverse a string by passing it to a function.

#include <stdio.h>
#include <string.h>
#define MAX_INPUT 50

void reverse_string (char *);

int main (void) {
	char str[MAX_INPUT];

	printf("Enter a string to be reversed: \n");
	scanf("%s", str);

	reverse_string(str);
	printf("%s\n", str);
	return 0;
}

void reverse_string (char * string) {
	unsigned int const length = strlen(string);
	unsigned int i = 0;
	char temp;

	for(i = 0; i < length / 2; ++i){
		temp = string[i];
		string[i] = string[length - 1 - i];
		string[length - 1 - i] = temp;
	}
}
