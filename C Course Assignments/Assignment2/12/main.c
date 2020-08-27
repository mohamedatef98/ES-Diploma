/*
 * main.c
 *
 *  Created on: Feb 20, 2020
 *      Author: m7med
 */

//(12) Write a C function that calculates the required heater activation time
//according to the input temperature of water.
//- if input temperature is from 0 to 30, then required heating time = 7
//mins.
//- if input temperature is from 30 to 60, then required heating time = 5
//mins.
//- if input temperature is from 60 to 90, then required heating time = 3
//mins.
//- if input temperature is more than 90, then required heating time = 1
//mins.
//- if temperature is invalid (more than 100), return 0
//Example:
//Input = 10 -> output = 7
//Input = 35 -> output = 5d

#include <stdio.h>

unsigned char calculate_time(int);

int main (void) {
	int temp;

	printf("%s", "Enter the temp: \n");
	scanf("%d", &temp);

	printf("%d, %d", temp, calculate_time(temp));

	return 0;
}

unsigned char calculate_time(int temp) {
	if (temp >=0 && temp <= 30) return 7;
	else if(temp >=30 && temp <= 60) return 5;
	else if(temp >=60 && temp <= 90) return 3;
	else if(temp >=90 && temp < 100) return 3;
	else return 0;
}
