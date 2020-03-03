/*
 * main.c
 *
 *  Created on: Feb 26, 2020
 *      Author: m7med
 */


//(1) The sum of an array is the sum of its individual elements. For
//example, if an array is numbers = {1, 2, 3, 4}, the sum of the array
//is 1+2+3+4 = 10.
//Function Description: Complete the function summation. The
//function must return the integer sum of the numbers array.
//int summation(int numbers_size, int* numbers)

#include <stdio.h>
#define INPUT_SIZE 5

int sum_arr(int arr [], unsigned int size);

int main (void) {
	int arr[INPUT_SIZE];
	int i;

	for(i = 0; i < INPUT_SIZE; ++i) {
		printf("Enter a Number: \n");
		scanf("%d", &arr[i]);
	}

	printf("Done.\n");
	printf("The Sum of the numbers Entered %d", sum_arr(arr, INPUT_SIZE));
}

int sum_arr(int arr[], unsigned int size) {
	int sum, i;
	sum = 0;
	i = 0;
	for(i = 0; i < size; ++i) sum += arr[i];
	return sum;
}
