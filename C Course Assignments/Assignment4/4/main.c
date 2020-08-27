/*
 * main.c
 *
 *  Created on: Mar 5, 2020
 *      Author: m7med
 */

//(4) C function to get the value of the smallest element in
//array using pointers.

#include <stdio.h>
#define SIZE 10

int arr_smallest(const int * const arr, const unsigned int size);

int main (void) {
	int arr[SIZE], i;

	printf("Enter %d Numbers.\n", SIZE);
	for (i = 0; i < SIZE; i++) {
		printf("Enter a Number: ");
		scanf("%d", &arr[i]);
	}

	printf("The smallest is %d.\n", arr_smallest(arr, SIZE));
	return 0;
}

int arr_smallest(const int * const arr, const unsigned int size) {
	unsigned int i;
	int min = arr[0];
	for(i = 1; i < size; ++i) {
		if (arr[i] < min) min = arr[i];
	}
	return min;
}
