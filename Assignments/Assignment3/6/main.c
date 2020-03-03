/*
 * main.c
 *
 *  Created on: Feb 26, 2020
 *      Author: m7med
 */

//(6) Write a C function to return the index of LAST occurrence of a
//number in a given array. Array index start from 0. If the item is not
//in the list return -1. (Linear Search Algorithm)
//Example:
//Array = {1,2,3,4,4,4}
//The required number is 4 it should return 5

#include <stdio.h>

unsigned int linear_search_reverse(int arr[], unsigned int size, int element);

int main(void) {
	int arr [] = { 1,2,5,2,10,4,3,8,3, 10, 6 , 6};
	printf("%d is in the %d.", 10, linear_search_reverse(arr, 12, 10));

	return 0;
}

unsigned int linear_search_reverse(int arr[], unsigned int size, int element) {
	int i;
	for(i = size - 1; i >= 0; --i)
		if (arr[i] == element)
			return i;
	return -1;
}
