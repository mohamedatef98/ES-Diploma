/*
 * main.c
 *
 *  Created on: Mar 5, 2020
 *      Author: m7med
 */


//(6) C Program to print all the array elements and the
//maximum number in array using array of pointers.

#include <stdio.h>
#define SIZE 10

void for_each(const int * const arr, const unsigned int size, void (* const func)(const int i));
void print_int(const int i);
int arr_max(const int * const arr, const unsigned int size);

int main (void) {
	int arr[SIZE], i;
	printf("Enter %d numbers.\n", SIZE);

	for(i = 0; i < SIZE; ++i) {
		printf("Enter a Number: ");
		scanf("%d", &arr[i]);
	}

	for_each(arr, SIZE, print_int);
	printf("\n");

	printf("The Max Number is %d.\n", arr_max(arr, SIZE));

}

void for_each(const int * const arr, const unsigned int size, void (* const func)(const int i)) {
	unsigned int i;
	for (i = 0; i < size; i++)
		(*func)(arr[i]);
}

void print_int(const int i) {
	printf("%d ", i);
}

int arr_max(const int * const arr, const unsigned int size) {
	unsigned int i;
	int max = arr[0];

	for(i = 1; i < size; ++i)
		if(arr[i] > max) max = arr[i];

	return max;
}
