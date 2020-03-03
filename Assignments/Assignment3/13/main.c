/*
 * main.c
 *
 *  Created on: Mar 1, 2020
 *      Author: m7med
 */


//(13) Write a function to remove all characters in a string expect
//alphabet.

#include <stdio.h>
#include <string.h>
#define MAX_INPUT 40

unsigned char is_alphabetic (unsigned char c);
void filter_string(char * str);

int main (void) {
	char str [MAX_INPUT];
	printf("Enter a String: \n");
	scanf("%s", str);

	filter_string(str);

	printf("%s", str);
	return 0;
}

unsigned char is_alphabetic (unsigned char c) {
	return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') ?
			1:
			0;
}

void filter_string(char * str) {
	int i = 0;
	for(i = 0; str[i] != '\0'; ++i) {
		if (!is_alphabetic(str[i])) {
			strcpy(str + i, str + i + 1);
			--i;
		}
	}
}
