/*
 * main.c
 *
 *  Created on: Mar 6, 2020
 *      Author: m7med
 */


//2. C Program to add two distances (inch-feet) using
//structure and display the result.

#include <stdio.h>

typedef struct {
	unsigned int inches;
	unsigned int feet;
} Distance;

Distance addDistances(const Distance d1, const Distance d2);

int main (void) {
	Distance d1, d2, dSum;

	printf("Enter Distance 1 inches and feet.\n");
	scanf("%d%d", &d1.inches, &d1.feet);

	printf("Enter Distance 2 inches and feet.\n");
	scanf("%d%d", &d2.inches, &d2.feet);

	dSum = addDistances(d1, d2);

	printf("The Sum is %d feet and %d inches.\n", dSum.feet, dSum.inches);

	return 0;
}


Distance addDistances(const Distance d1, const Distance d2) {
	Distance dSum;
	unsigned int sumInches = d1.inches + d2.inches;
	unsigned int sumFeet = d1.feet + d2.feet;

	dSum.feet = sumFeet + sumInches / 12;
	dSum.inches = sumInches % 12;

	return dSum;
}
