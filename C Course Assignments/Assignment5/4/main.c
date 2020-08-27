/*
 * main.c
 *
 *  Created on: Mar 13, 2020
 *      Author: m7med
 */


//4. C Function to calculate the difference between two
//time periods using structures.

#include <stdio.h>

typedef struct {
	unsigned char minutes;
	unsigned int hours;
} time;

time get_time_difference(const time, const time);

int main (void) {
	time t1, t2, tdiff;

	printf("Enter The T1 hours.\n");
	scanf("%u", &t1.hours);

	do {
		printf("Enter T1 Minutes.\n");
		scanf("%hhu", &t1.minutes);
	} while(!(t1.minutes >= 0 && t1.minutes < 60));


	printf("Enter The T2 hours.\n");
	scanf("%u", &t2.hours);

	do {
		printf("Enter T2 Minutes.\n");
		scanf("%hhu", &t2.minutes);
	} while(!(t2.minutes >= 0 && t2.minutes < 60));


	tdiff = get_time_difference(t1, t2);

	printf("Difference is %u hours and %u minutes.\n", tdiff.hours, tdiff.minutes);

	return 0;
}

time get_time_difference(const time t1, const time t2) {
	time tdiff;
	unsigned int minutes_diff;

	if(t1.hours > t2.hours) minutes_diff = (t1.hours - t2.hours) * 60 + t1.minutes - t2.minutes;
	else if(t1.hours < t2.hours) minutes_diff = (t2.hours - t1.hours) * 60 + t2.minutes - t1.minutes;
	else if(t1.hours == t2.hours) minutes_diff = t1.minutes - t2.minutes;

	while(minutes_diff < 0) minutes_diff += 60;

	tdiff.hours = minutes_diff / 60;
	tdiff.minutes = minutes_diff % 60;

	return tdiff;
}

