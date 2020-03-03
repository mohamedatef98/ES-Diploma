/*
 * main.c
 *
 *  Created on: Feb 26, 2020
 *      Author: m7med
 */


//(3) Write a C function that use the bubble sort algorithm to sort
//an integer array in ascending order (search for the bubble sorting
//algorithm).

#include <stdio.h>

void bubble_sort(int arr [], unsigned int size);
void print_arr(int arr[], unsigned int size);

int main (void) {
	int arr[] = {1,5,8,2,5,8,8,12,5,7,2,6,9};
	printf("Array Before Sorting.\n");
	print_arr(arr, 13);

	printf("Array After Sorting.\n");
	bubble_sort(arr, 13);
	print_arr(arr, 13);
}

void bubble_sort(int arr [], unsigned int size) {
	int i, j, temp;
	for (i = size - 1; i >= 0; --i)
		for (j = 0; j < i; j++)
			if(arr[j] > arr[j + 1]) {
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
}

void print_arr(int arr[], unsigned int size) {
	int i;
	for (i = 0; i < size; ++i) printf("%d ", arr[i]);
	printf("\n");
}
