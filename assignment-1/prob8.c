// Find the roots of the quadratic equation ax2 + bx + c = 0, considering all possible cases

#include <stdio.h>
#include <math.h>

int D(int a, int b, int c) { // function to find the discriminant of a quadratic equation
	return (b*b - 4*a*c);
}

int main() { // main method
	int a, b, c;
	printf("Enter the values of a, b and c:\n"); // take input of the coefficients
	scanf("%d%d%d", &a, &b, &c);
	int d = D(a, b, c); // find the discriminant
	if(d<0) {
		printf("Complex Roots.\n"); // if complex roots, display the necessary message
		return 0;
	} else {
		float x1, x2;
		x1 = (float)(-b+sqrt(d))/(2*a); // find the two roots
		x2 = (float)(-b-sqrt(d))/(2*a);
		printf("Roots of the quadratic eqn %dx2 + %dx + %d are:\n%.2f, %.2f\n", a, b, c, x1, x2); // display the two roots
	}
	return 0;
}
