/*
 * main.c
 *
 *  Created on: Feb 26, 2020
 *      Author: m7med
 */

//(17) Given two integers: L and R, Find the maximal value of A xor B where
//A and B satisfy the condition L =< A <= B <= R Constrains: 1 <= L <= R <=
//1000
//Input format: the input contains two lines first line contains L and next
//line contains R.
//Output format: The maximum value of A xor B

#include <stdio.h>

int main(void) {
	int l, r;

	int max_xor = 0;
	int temp = 0;
	int i,j;

	printf("Enter L and R: \n");
	scanf("%d%d", &l, &r);


	for(i=l;i<=r;i++) {
		for(j=i;j<=r;j++) {
			temp = i ^ j;
			if(temp > max_xor) {
				max_xor = temp;
			}
		}
	}

	printf("%d\n", max_xor);
}

