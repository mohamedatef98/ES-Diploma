/*
 * main.c
 *
 *  Created on: Mar 5, 2020
 *      Author: m7med
 */


//(3)C Program to read 10 integers into an array from user
//and print them in reversing order using pointers.

#include <stdio.h>
#define SIZE 10

void print_int(int i);
void reversal(const int * const arr, const unsigned int size, void (*func) (int));

int main (void) {
	int arr[SIZE], i;

	printf("Enter %d Numbers.\n", SIZE);
	for (i = 0; i < SIZE; i++) {
		printf("Enter a Number: ");
		scanf("%d", &arr[i]);
	}

	reversal(arr, SIZE, print_int);
	printf("\n");
	return 0;
}

void print_int(int i) {
	printf("%d ", i);
}

void reversal(const int * const arr, const unsigned int size, void (*func) (int)) {
	unsigned int i;
	for (i = 0; i < size; i++){
		(*func)(arr[size - 1 - i]);
	}
}
