// input a number and check whether it is prime or composite

#include <stdio.h>

int main() { // main function 
	int num;
	printf("Enter the number:\n"); // take input
	scanf("%d", &num);
	int i;
	for(i = 2; i<=(num/i); i++) { // check prime or composite
		if(num % i == 0) {
			printf("The number is composite.");
			break;
		}
	}
	if (i > (num/i)) {
		printf("The number is prime.");
	}
	return 0;
}
