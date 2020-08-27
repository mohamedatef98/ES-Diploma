/*
 * main.c
 *
 *  Created on: Mar 2, 2020
 *      Author: m7med
 */


//(18) Write a C function that return the count of the longest
//consecutive occurrence of a given number in an array.
//Example:
//Array={1,2,2,3,3,3,3,4,4,4,4,3,3,3} and searching for 3 -> result = 4

#include <stdio.h>
#define MAX_INPUT 50

unsigned int get_max_count(char *, char);

int main (void) {
	char str[MAX_INPUT], c;
	unsigned int max_count;

	printf("Enter a String: \n");
	scanf("%s", str);

	printf("Enter a Char: \n");
	scanf("%c%c", &c, &c);

	max_count = get_max_count(str, c);

	printf("Max Count for %c is %d.\n", c, max_count);
	return 0;
}

unsigned int get_max_count(char * str, char c) {
	unsigned int max_count = 0, temp = 0, i = 0;
	for(i = 0; str[i] != '\0'; i++) {
		if(str[i] == c) temp ++;
		else {
			if(temp > max_count) max_count = temp;
			temp = 0;
		}
	}

	return max_count;
}

