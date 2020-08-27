/*
 * main.c
 *
 *  Created on: Mar 1, 2020
 *      Author: m7med
 */


//(15) Write a function to concatenate two strings without using
//strcat function.

#include <stdio.h>
#define MAX_INPUT 50

void string_cat(char *, char *);

int main (void) {
	char str1 [MAX_INPUT], str2[MAX_INPUT];

	printf("Enter a string: \n");
	scanf("%s", str1);

	printf("Enter a string: \n");
	scanf("%s", str2);

	string_cat(str1, str2);

	printf("%s\n", str1);

	return 0;
}

void string_cat(char * dist, char * src){
	unsigned int dist_length;
	unsigned int i = 0;

	// determine dist length
	while(dist[i] != '\0') i++;

	dist_length = i;

	// copy all chars from src to dist starting from the \0 in dist
	for(i = 0; src[i] != '\0'; ++i) {
		dist[dist_length + i] = src[i];
	}

	// now place \0 at end of dist
	dist[dist_length + i] = '\0';

}
