/*
 * main.c
 *
 *  Created on: Mar 5, 2020
 *      Author: m7med
 */


//(9) Given a string, create a new string made up of its last
//two letters, reversed and separated by a space, the word
//is “bat”. Return string contains "t a"

#include <stdio.h>
#include <string.h>
#define MAX_SIZE 50

int main (void) {
	char string[MAX_SIZE];
	char last_and_first [4];
	unsigned int length;
	printf("Enter a String: \n");
	scanf("%49s", string);

	length = strlen(string);

	last_and_first[0] = string[length - 1];
	last_and_first[1] = ' ';
	last_and_first[2] = string[length - 2];
	last_and_first[3] = '\0';

	printf("%s\n", last_and_first);
}
