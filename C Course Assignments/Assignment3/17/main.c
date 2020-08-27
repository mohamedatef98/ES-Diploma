/*
 * main.c
 *
 *  Created on: Mar 1, 2020
 *      Author: m7med
 */


//(17) Write a C Program for swapping two arrays “A & B” with
//different lengths. B will be always the smallest array.
//int * Swap (int a_size,int *a,int b_size,int *b)

#include <stdio.h>

void print_array(int * arr, unsigned int size);
void swap_array(int * arr1, unsigned int size1, int * arr2, unsigned int size2);

int main (void) {
	int arr1[] = {3, 4, 6, 36, 982, 10, 133, 65, 792, -26, 87, -87, 1010,364, 32, 90};
	int arr2[] = {6, -9, 10, 3645, 100, -8};

	print_array(arr1, 16);
	print_array(arr2, 6);

	swap_array(arr1, 16, arr2, 6);

	print_array(arr1, 16);
	print_array(arr2, 6);

	return 0;
}

void print_array(int * arr, unsigned int size) {
	unsigned int i = 0;
	for(i = 0; i < size; ++i) printf("%d ", arr[i]);

	printf("\n");
}
void swap_array(int * arr1, unsigned int size1, int * arr2, unsigned int size2) {
	int temp;
	unsigned int i;

	for(i = 0; i < size2; i++){
		temp = arr1[i];
		arr1[i] = arr2[i];
		arr2[i] = temp;
	}
}
