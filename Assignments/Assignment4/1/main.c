/*
 * main.c
 *
 *  Created on: Mar 5, 2020
 *      Author: m7med
 */


//(1) C Program to compute sum of the array elements using
//pointers.

#include <stdio.h>
#define SIZE 10

int sum_arr(const int * const arr_ptr, const unsigned int size);

int main(void) {
	int arr[SIZE], i, sum;
	printf("Enter array Numbers: \n");

	for(i = 0; i< SIZE; i++){
		printf("Enter a Number: \n");
		scanf("%d", &arr[i]);
	}

	sum = sum_arr(arr, SIZE);

	printf("The Sum is %d.\n", sum);
	return 0;
}

int sum_arr(const int * const arr_ptr, const unsigned int size) {
	unsigned int i = 0;
	int sum = 0;
	for (i = 0; i < size; i++) sum += arr_ptr[i];
	return sum;
}
