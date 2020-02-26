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

float calculate(unsigned char op, int operand1, int operand2, char * err_ptr);

int main (void) {
    int op1, op2;
    char op, err;
    float res;

    printf("Enter The Operator (+, -, *, /): \n");
    scanf("%c", &op);

    printf("Enter Two Numbers: \n");
    scanf("%d%d", &op1, &op2);

    res = calculate(op, op1, op2, &err);
    if (!err) printf("%3d %c %3d = %10.6f", op1, op, op2, res);
    else printf("Wrong Operator Entered.");

    printf("\n");

    return 0;
}

float calculate(unsigned char operation, int op1, int op2, char * err_ptr) {
	switch(operation){
	case '+':
		*err_ptr = 0;
		return op1 + op2;
	case '-':
		*err_ptr = 0;
		return op1 - op2;
	case '*':
		*err_ptr = 0;
		return op1 * op2;
	case '/':
		*err_ptr = 0;
		return (float)op1 / op2;
	default:
		*err_ptr = 1;
		return -1;
	}
}
