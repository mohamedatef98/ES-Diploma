/*
 * main.c
 *
 *  Created on: Mar 3, 2020
 *      Author: m7med
 */


//(22) Write a c function that removes the repeated number of an
//input sorted array and return a new array without the repeated
//numbers. The function shall return error if the size of the input
//array is ZERO. The function takes four inputs:
//a. Old array.
//b. Old array size.
//c. New array (empty array).
//d. The size of the new array after fill it in the function.
//int removeDuplicates(int arr_old[], int n_old, int arr_new[], int
//*n_new)
//Example:
//arr1 = {1,2,3,3,3,4,4,5,5,5} -> arr2 = {1,2,3,4,5}

#include <stdio.h>
#define SIZE 10

void print_arr(const int * const arr, const unsigned int size);
unsigned int uniquify(const int * const arr1, const unsigned int size1, int * const arr2, int * const new_size);

int main (void) {
	int arr1[SIZE], arr2[SIZE], i = 0, new_size;

	printf("Enter Array Values: \n");
	for(i = 0; i < SIZE; i++){
		printf("Enter a Number: \n");
		scanf("%d", &arr1[i]);
	}

	print_arr(arr1, SIZE);

	uniquify(arr1, SIZE, arr2, &new_size);

	print_arr(arr2, new_size);
	return 0;
}

void print_arr(const int * arr, const unsigned int size) {
	unsigned int i = 0;
	for(i = 0; i < size; i++) printf("%d ", arr[i]);

	printf("\n");
}

unsigned int uniquify(const int * const arr1, const unsigned int size1, int * const arr2, int * const new_size) {
	unsigned int i = 1, size = 0;
	int temp;
	if (size1 == 0) return 0;

	temp = arr1[0];
	arr2[size++] = temp;
	for(i = 1; i < size1; ++i) {
		if(arr1[i] != temp) {
			arr2[size++] = arr1[i];
			temp = arr1[i];
		}
	}
	*new_size = size;
	return 1;
}

