/*
 * main.c
 *
 *  Created on: Mar 5, 2020
 *      Author: m7med
 */


//(5) C function to copy all elements of an array into another
//array using pointers. The two arrays have the same length
//and types.

#include <stdio.h>
#define SIZE 10

void print_arr(const int * const arr, const unsigned int size);
void arr_copy(int * const dist, const int * const src, const unsigned int size);


int main (void) {
	int arr1[SIZE], arr2[SIZE], i;

	printf("Enter arr1 values.\n");

	for(i = 0; i < SIZE; i++) {
		printf("Enter a Number: ");
		scanf("%d", &arr1[i]);
	}

	arr_copy(arr2, arr1, SIZE);

	print_arr(arr1, SIZE);
	print_arr(arr2, SIZE);

}


void print_arr(const int * const arr, const unsigned int size) {
	unsigned int i;
	for(i = 0; i < size; i++) printf("%d ", arr[i]);

	printf("\n");
}

void arr_copy(int * const dist, const int * const src, const unsigned int size) {
	unsigned int i;
	for (i = 0; i < size; ++i) dist[i] = src[i];
}
