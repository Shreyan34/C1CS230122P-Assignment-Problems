// accept two numbers and find out their HCF and LCM

#include <stdio.h>

int main() { // main function
	int a, b; // declare the variables
	int hcf, lcm;
	int max;
	printf("Enter the two numbers:\n"); // take input
	scanf("%d%d", &a, &b); 
	int i, j;
	max = (a>b) ? a : b; // find the maximum of the two numbers
	for(i = 1; i<=max; i++) { // run the loop
		if(a % i == 0 && b % i == 0) {
			hcf = i;
		}
	}
	printf("The HCF of %d and %d is %d", a, b, hcf); // print the output
	lcm = (a*b)/hcf; // find lcm through hcf
	printf("\nThe LCM of %d and %d is %d", a, b, lcm);
	return 0;
}
