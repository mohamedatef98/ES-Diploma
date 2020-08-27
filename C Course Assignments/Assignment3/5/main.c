/*
 * main.c
 *
 *  Created on: Feb 26, 2020
 *      Author: m7med
 */


//(5) Write a C function to return the index of FIRST occurrence of a
//number in a given array. Array index start from 0. If the item is not
//in the list return -1. (Linear Search Algorithm)
//Example:
//Array = {1,2,3,4,4,4}
//The required number is 4 it should return 3

#include <stdio.h>

unsigned int linear_search(int arr[], unsigned int size, int element);

int main(void) {
	int arr [] = { 1,2,5,2,10,4,3,8,3};
	printf("%d is in the %d.", 10, linear_search(arr, 9, 10));

	return 0;
}

unsigned int linear_search(int arr[], unsigned int size, int element) {
	int i;
	for(i = 0; i < size; ++i)
		if (arr[i] == element)
			return i;
	return -1;
}
