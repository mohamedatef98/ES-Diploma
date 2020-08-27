/*
 * main.c
 *
 *  Created on: Feb 19, 2020
 *      Author: m7med
 */


//(10) You are designing a poster which prints out numbers with a unique
//style applied to each of them. The styling is based on the number of
//closed paths or holes present in a giver number. The number of holes
//that each of the digits from 0 to 9 have are equal to the number of closed
//paths in the digit. Their values are:
//* 1, 2, 3, 5 and 7 = 0 holes.
//* 0, 4, 6, and 9 = 1 hole.
//* 8 = 2 holes.
//Given a number, you must determine the sum of the number of holes for
//all of its digits. For example, the number 819 has 3 holes.
//Function Description
//Complete the function countHoles. The function must return an integer
//denoting the total number of holes in num.


#include <stdio.h>

unsigned char countHoles(int);

int main (void) {
	int number;
	printf("%s", "Enter a Number: \n");
	scanf("%d", &number);

	printf("%d has %d holes.\n", number, countHoles(number));

	return 0;
}

unsigned char countHoles(int num){
	int count, currentDigit;

	count = 0;
	currentDigit = 0;
	while (num > 0) {
		currentDigit = num % 10;

		num = num / 10;

		switch(currentDigit){
		case 0:
		case 4:
		case 6:
		case 9:
			count ++;
			break;
		case 8:
			count += 2;
			break;
		}
	}

	return count;
}
