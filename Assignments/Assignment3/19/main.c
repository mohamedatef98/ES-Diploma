/*
 * main.c
 *
 *  Created on: Mar 2, 2020
 *      Author: m7med
 */


//(19) Write a C function that compare between 2 arrays with the
//same length. It shall return 0 if the two arrays are identical and 1
//if not.

#include <stdio.h>
#define SIZE_1 10
#define SIZE_2 10

unsigned char are_arrays_identical(const int * const arr1, const unsigned int size1, const int * const arr2, const unsigned int size2);

int main (void) {
	int arr1 [SIZE_1];
	int arr2 [SIZE_2];

	int i = 0;

	printf("Enter Array 1 Numbers: \n");
	for(i = 0; i < SIZE_1; i++) {
		printf("Enter a Number: \n");
		scanf("%d", &arr1[i]);
	}

	printf("Enter Array 2 Numbers: \n");
	for(i = 0; i < SIZE_2; i++) {
		printf("Enter a Number: \n");
		scanf("%d", &arr2[i]);
	}

	are_arrays_identical(arr1, SIZE_1, arr2, SIZE_2) ?
			printf("Two Arrays are identical.\n") :
			printf("Two arrays are different.\n");

	return 0;
}

unsigned char are_arrays_identical(const int * const arr1, const unsigned int size1, const int * const arr2, const unsigned int size2) {
	unsigned int i = 0;

	if (size1 != size2) return 0;

	for(i = 0; i < size1; ++i)
		if(arr1[i] != arr2[i]) return 0;

	return 1;
}
