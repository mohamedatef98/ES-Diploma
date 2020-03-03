/*
 * main.c
 *
 *  Created on: Mar 1, 2020
 *      Author: m7med
 */

//(16) Write a C function that takes an array as input and reverse it.
//Example:
//Input : 1,2,3,4,5
//Output: 5,4,3,2,1

#include <stdio.h>
#define MAX_INPUT 10

void print_array(int *, unsigned int);
void reverse_array (int *, unsigned int);

int main (void) {
	int array[MAX_INPUT];
	char i;


	for(i = 0; i < MAX_INPUT; ++i){
		printf("Enter an Integer number: \n");
		scanf("%d", array + i);
	}

	print_array(array, MAX_INPUT);

	reverse_array(array, MAX_INPUT);

	print_array(array, MAX_INPUT);

	return 0;
}

void print_array(int * arr, unsigned int size) {
	unsigned int i = 0;
	for(i = 0; i < size; ++i) printf("%d ", arr[i]);

	printf("\n");
}

void reverse_array (int * arr, unsigned int size) {
	unsigned int i = 0;
	int temp;

	for(i = 0; i < size / 2; ++i){
		temp = arr[i];
		arr[i] = arr[size - 1 - i];
		arr[size - 1 - i] = temp;
	}
}
