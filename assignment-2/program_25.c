// Program 25
//Write a program in C to accept two complex numbers real and imaginary format using structures and
//calculate their sum and product in separate functions.

#include <stdio.h> // import dependencies

struct complex_number {
	int real;
	int imaginary;
}; // a structure that holds the real and imaginary parts of a complex number

int main() {
	struct complex_number n1, n2; // create two complex numbers
	printf("Enter the real and imaginary part of the first complex number: \n"); // input the complex numbers
	scanf("%d%d", &n1.real, &n1.imaginary);
	printf("Enter the real and imaginary part of the second complex number: \n");
	scanf("%d%d", &n2.real, &n2.imaginary);
	int sum_real = n1.real + n2.real; // compute the summation
	int sum_imaginary = n1.imaginary + n2.imaginary;
	printf("The resultant sum of the complex numbers is: %d + (%d)i", sum_real, sum_imaginary);
	int coeff_real = (n1.real*n2.real - n1.imaginary*n2.imaginary); // compute the product coefficients
	int coeff_imaginary = (n1.real*n2.imaginary + n1.imaginary*n2.real);
	printf("\nThe resultant product of the complex numbers is: %d + (%d)i", coeff_real, coeff_imaginary);
	return 0;
}
