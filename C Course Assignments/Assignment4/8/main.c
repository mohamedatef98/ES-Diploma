/*
 * main.c
 *
 *  Created on: Mar 5, 2020
 *      Author: m7med
 */


//(8) Write a C function to swap the contents of two arrays
//with the same length using pointers.

#include <stdio.h>
#define SIZE 10

void print_arr(const int * const arr, const unsigned int size);
void swap_arr(int * const arr1, int * const arr2, const unsigned int size);

int main (void) {
	int arr1[SIZE] = {5,6,7,8,3,5,7,9,3,5};
	int arr2[SIZE] = {3,5,6,2,5,8,0,3,5,5};

	print_arr(arr1, SIZE);
	print_arr(arr2, SIZE);

	swap_arr(arr1, arr2, SIZE);

	print_arr(arr1, SIZE);
	print_arr(arr2, SIZE);
}

void print_arr(const int * const arr, const unsigned int size) {
	unsigned int i = 0;
	for(i = 0; i < size; ++i) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void swap_arr(int * const arr1, int * const arr2, const unsigned int size) {
	unsigned int i = 0;
	for(i = 0; i < size; ++i) {
		arr1[i] = arr1[i] ^ arr2[i];
		arr2[i] = arr1[i] ^ arr2[i];
		arr1[i] = arr1[i] ^ arr2[i];
	}
}

