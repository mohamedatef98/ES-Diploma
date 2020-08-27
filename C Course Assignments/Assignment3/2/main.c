/*
 * main.c
 *
 *  Created on: Feb 26, 2020
 *      Author: m7med
 */


//(2) Write a function which, given a string, return TRUE if all
//characters are distinct and FALSE if any character is repeated.

#include <stdio.h>
#define MAX_STRING_SIZE 20

unsigned char is_unique(char string[]);

int main (void) {
	char string [MAX_STRING_SIZE];
	printf("Enter a String that will be checked if its all unqiue characters: \n");
	scanf("%s", string);

	is_unique(string) ?
			printf("The String Entered is Unique.\n") :
			printf("The String Entered Isn't Unique.\n");

	return 0;

}

unsigned char is_unique(char string[]) {
	int i, j;
	for(i = 0; string[i] != '\0'; ++i) {
		for(j = i + 1; string[j] != '\0'; ++j)
			if(string[i] == string[j]) return 0;
	}
	return 1;
}
