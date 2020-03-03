/*
 * main.c
 *
 *  Created on: Feb 26, 2020
 *      Author: m7med
 */


//(4) Write a C function that use the selection sort algorithm to sort
//an integer array in ascending order (search for the selection
//sorting algorithm).

#include <stdio.h>

void selection_sort(int arr[], unsigned int size);
void print_arr(int arr[], unsigned int size);

int main(void) {
	int arr[] = {1,5,8,2,5,8,8,12,5,7,2,6,9};
	printf("Array Before Sorting.\n");
	print_arr(arr, 13);

	printf("Array After Sorting.\n");
	selection_sort(arr, 13);
	print_arr(arr, 13);
}

void selection_sort(int arr[], unsigned int size) {
	/*sorted_end points at the first element after the sorted array partition*/
	unsigned int i, j, sorted_end, min_index;
	int min, temp;
	i = sorted_end = 0;
	for(i = 0; i < size; i++){
		min = arr[sorted_end];
		min_index = sorted_end;
		for(j = sorted_end + 1; j < size; j++)
			if (arr[j] < min) {
				min = arr[j];
				min_index = j;
			}
		temp = arr[sorted_end];
		arr[sorted_end] = min;
		arr[min_index] = temp;
		sorted_end++;
	}
}

void print_arr(int arr[], unsigned int size) {
	int i;
	for(i = 0; i < size; i++) printf("%d ", arr[i]);
	printf("\n");
}
