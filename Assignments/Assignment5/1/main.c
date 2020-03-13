/*
 * main.c
 *
 *  Created on: Mar 6, 2020
 *      Author: m7med
 */


//1. C Program to store information (name, roll and
//marks) for a student using structure and display it.
#include <stdio.h>

struct student {
	char name[20];
	unsigned int roll_number;
	unsigned int marks;
};

int main (void) {
	struct student s1;

	printf("Enter Student Name: ");
	scanf("%19s", s1.name);

	printf("Enter Student Roll Number: ");
	scanf("%u", &s1.roll_number);

	printf("Enter Student Marks: ");
	scanf("%u", &s1.marks);

	printf("Roll Number: %d, Student Name: %19s, Marks: %d.\n", s1.roll_number, s1.name, s1.marks);
}
