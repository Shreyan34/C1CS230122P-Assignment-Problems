// display the Fibonacci series till a user given limit 'n'

#include <stdio.h>

int main() { // main function
	int n;
	printf("Enter the limit: "); // take input of range
	scanf("%d", &n);
	int a1 = 0, a2 = 1; // initialise the first terms
	printf("%d, %d", a1, a2); // print the first terms
	int sum = a1 + a2; // store the sum temporarily
	int i;
	for(i = 2; i<n; i++) {
		sum += a2; // find the consequent sums
		a2 ^= sum; // swap the variables accordingly
		sum ^= a2;
		a2 ^= sum; 
		printf(", %d", sum); // print the sum
	}
	return 0;
}
