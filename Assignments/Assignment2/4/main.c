/*
 * main.c
 *
 *  Created on: Feb 18, 2020
 *      Author: engmo
 */

//(4) Write a C Function that return the addition or subtraction or
//multiplication or division for two numbers. The function should take the
//required operation and two numbers as arguments. It also should check
//that the input operation is one of those operation that mentioned before
//and if not it should return error. The function should be implemented
//using switch case.


#include "stdio.h"

void calculate(unsigned char op, int operand1, int operand2);

int main (void) {
    calculate('+', 1, 3);

    calculate('+', 553, 863);

    calculate('+', 3, -3);

    calculate('-', 10, 2);

    calculate('-', 2, 5);

    calculate('*', 10, 3);

    calculate('*', -2, -4);

    calculate('/', 4, 2);

    calculate('/', 10, 2);

    return 0;
}

void calculate(unsigned char operation, int op1, int op2) {
	switch(operation){
	case '+':
		printf("%d + %d = %d\n", op1, op2, op1 + op2);
		return;
	case '-':
		printf("%d - %d = %d\n", op1, op2, op1 - op2);
		return;
	case '*':
		printf("%d * %d = %d\n", op1, op2, op1 * op2);
		return;
	case '/':
		printf("%d / %d = %d\n", op1, op2, op1 / op2);
		return;
	default:
		printf("%s", "Wrong Operation\n");
	}
}
