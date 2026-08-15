// find the largest of three numbers using (i) if-else ladder, (ii) conditional (ternary) operator

#include <stdio.h>

int main() { // main function
	int a, b, c;
	printf("Enter three numbers:\n"); // take input
	scanf("%d %d %d", &a, &b, &c);
	int max;
	// if-else ladder
	if(a > b) {
		if(a > c) {
			max = a;
		} else {
			max = c;
		}
	} else if (b > c) {
		if(b > a) {
			max = b;
		} else {
			max = a;
		}
	} else {
		max = c;
	}
	printf("Maximum through the if-else ladder: %d\n", max);
	
	// through conditional (ternary) operator
	max = (a>b) ? ((a>c) ? a : c) : ((b > c) ? b : c); 
	printf("Maximum through the ternary operator: %d", max);
	return 0;
}
