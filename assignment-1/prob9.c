/*
	Write a menu driven program to implement a simple arithmetic calculator to perform the following:
	
	a) Addition
	b) Subtraction
	c) Multiplication
	d) Division
	e) Exponentiation
	f) Modulus

*/

#include <stdio.h>
#include <math.h>

int main() { // main function
	int a, b; // variables to store the two operands
	float result; // variable to store the result
	printf("Enter the two integers:\n"); // take input
	scanf("%d%d", &a, &b);
	int choice; // variable to store the choice
	printf("-----MENU-----\n"); // display the menu
	printf("Enter 1 to add.\nEnter 2 to subtract.\nEnter 3 to multiply.\nEnter 4 to divide.\nEnter 5 to raise to a power.\nEnter 6 to get the remainder.\n");
	scanf("%d", &choice);
	switch(choice) { // perform the menu operations
		case 1:
			result = a + b;
			printf("Result: %f", result);
			break;
		case 2:
			result = a - b;
			printf("Result: %.2f", result);
			break;
		case 3:
			result = a * b;
			printf("Result: %.2f", result);
			break;
		case 4:
			result = (float )a / b;
			printf("Result: %.2f", result);
			break;
		case 5:
			result = pow(a, b);
			printf("Result: %.2f", result);
			break;
		case 6:
			result = a % b;
			printf("Result: %.2f", result);
			break;
		default:
			printf("Invalid Input!");
	}
	return 0;
}
