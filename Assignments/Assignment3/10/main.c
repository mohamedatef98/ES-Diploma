/*
 * main.c
 *
 *  Created on: Feb 27, 2020
 *      Author: m7med
 */


//(10) Write a function which, given a string, converts all uppercase
//letters to lowercase, leaving the others unchanged.

#include <stdio.h>
#define MAX_INPUT_LENGTH 50

char to_lowercase(char);
void str_to_lowercase(char *);

int main(void) {
	char str [MAX_INPUT_LENGTH];
	printf("Enter a String to be transformed into lower case: \n");
	scanf("%s", str);

	str_to_lowercase(str);

	printf("%s", str);
	printf("\n");
}

char to_lowercase(char c){
	return (c >= 'A' && c <= 'Z') ?
			c + 'a' - 'A' :
			c;
}

void str_to_lowercase(char * str) {
	unsigned int i;
	i = 0;
	while(str[i] != '\0') {
		str[i] = to_lowercase(str[i]);
		i++;
	}
}

