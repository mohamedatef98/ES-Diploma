/*
 * main.c
 *
 *  Created on: Feb 27, 2020
 *      Author: m7med
 */


//(11) Write a function that prints the frequency of a certain
//character in a string.

#include <stdio.h>
#define MAX_INPUT_SIZE 50


unsigned int frequency(char * str, char c);

int main (void) {
	char str[MAX_INPUT_SIZE];
	char c;
	printf("Enter a string: \n");
	scanf("%s", str);

	printf("Enter a character that you wish to calculate its frequency in the string: \n");
	scanf("%c%c", &c, &c);

	printf("The frequency of %c in the entered string is %d.\n", c, frequency(str, c));

	return 0;
}

unsigned int frequency(char * str, char c) {
	unsigned int freq, i;
	i = 0;
	freq = 0;
	while(str[i] != '\0'){
		if(str[i] == c)
			freq++;
		++i;
	}

	return freq;
}
