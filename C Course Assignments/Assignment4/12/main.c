/*
 * main.c
 *
 *  Created on: Mar 5, 2020
 *      Author: m7med
 */


//(12) Array that contains integer values, some of these
//values are repeated with an even number of repetitions,
//and only one value is repeated with an odd number of
//repetitions. Write a C function that’s take the array as
//input and the array size and return the number which has
//odd numbers of repetitions.

#include <stdio.h>
#define SIZE 17

int main (void) {
	int arr[SIZE] = {1,1,2,2,3,3,3,3,4,4,5,5,5,7,7, 9, 9};
	int current_repeated = arr[0];
	unsigned int i, current_repeated_repetitions = 1, found = 0;

	for(i = 1; i < SIZE; i++) {
		if(arr[i] == current_repeated)
			current_repeated_repetitions++;
		else {
			if (current_repeated_repetitions % 2 != 0){
				found = 1;
				break;
			}
			current_repeated_repetitions = 1;
			current_repeated = arr[i];
		}
	}

	found ? printf("%d is repeated odd times.\n", current_repeated) : printf("No Number found.\n");
}
