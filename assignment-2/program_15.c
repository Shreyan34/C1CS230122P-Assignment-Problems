// Problem 15
// Write a program in C to accept two limits and find and print the prime palindrome numbers within that range

#include <stdio.h> // import dependencies

int is_prime(int num) { // a function to check if a given number is prime or not
	int i;
	for(i = 2; i<=num/i; i++) {
		if(num % i == 0) {
			return 0;
		}
	}
	return 1;
}

int is_palindrome(int num) { // a function to check if a given number is palindrome or not
	int copy = num;
	int rev = 0;
	while(copy!=0) {
		int digit = copy % 10;
		rev = rev * 10 + digit;
		copy /= 10;
	}
	if(rev == num) return 1;
	return 0;
}

int main() {
	int u, l; // to store the upper and lower limits respectively
	int i; // iterator
	printf("Enter the lower limit: "); // take input of the upper and lower bounds
	scanf("%d", &l);
	printf("Enter the upper limit: ");
	scanf("%d", &u);
	for(i = l; i<=u; i++) // run the iterator
		if(is_prime(i) && is_palindrome(i)) // print the prime palindrome numbers
			printf("%d\t", i);
	return 0;
}
