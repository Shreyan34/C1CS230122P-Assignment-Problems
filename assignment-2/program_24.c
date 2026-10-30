// Program 24
//Write a program in C to accept two times in terms of hours, minutes and seconds and compute the
//difference between the two times using structures.

#include <stdio.h> // import dependencies
#include <stdlib.h>

struct time {
	int hours;
	int minutes;
	int seconds;
}; // a structure that holds the details of a time slot

int main() {
	struct time t1, t2; // declare two structres of the time slots
	printf("Enter the hours, minutes, and seconds for the first time slot: \n"); // take inputs of the time slots
	scanf("%d%d%d", &t1.hours, &t1.minutes, &t1.seconds);
	printf("Enter the hours, minutes, and seconds for the second time slot: \n");
	scanf("%d%d%d", &t2.hours, &t2.minutes, &t2.seconds);
	int first_slot_converted = (t1.hours * 3600) + (t1.minutes * 60) + t1.seconds; // convert both the slots into seconds
	int second_slot_converted = (t2.hours * 3600) + (t2.minutes * 60) + t2.seconds;
	int diff = abs(first_slot_converted - second_slot_converted); // find the absolute difference
	int result_hours = diff / 3600; // convert the difference into slots
	int result_minutes = (diff % 3600) / 60;
	int result_secs = (diff % 3600) % 60;
	printf("The resultant difference in the time slots is: %d hours %d minutes %d seconds.", result_hours, result_minutes, result_secs); // print the slots
	return 0;
}
