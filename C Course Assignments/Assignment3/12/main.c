/*
 * main.c
 *
 *  Created on: Feb 27, 2020
 *      Author: m7med
 */


//(12) Write a function to find the length of a string.

#include <stdio.h>
#define MAX_INPUT_SIZE 50


unsigned int str_length(char * str);

int main(void) {
	char str[MAX_INPUT_SIZE];
	printf("Enter a string: \n");
	scanf("%s", str);

	printf("The length of the entered string is %u", str_length(str));
}

unsigned int str_length(char * str) {
	unsigned int i = 0;
	while(str[i] != '\0') ++i;

	return i;
}
