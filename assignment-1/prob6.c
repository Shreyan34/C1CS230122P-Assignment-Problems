// enter a number to check if it is a palindrome or not

#include <stdio.h>

int isPalindrome(int n) { // a function to check if a number is palindrome or not
	int copy = n; // create a copy of the parameter
	int digit; // to store the individual digits
	int rev = 0; // to store the reverse
	while(copy != 0) { // find the reverse
		digit = copy % 10;
		rev = rev * 10 + digit;
		copy /= 10;
	}
	if(rev == n) return 1; // return flag accordingly
	return 0;
}

int main() { // main function
	int num;
	printf("Enter the number:\n"); // take input
	scanf("%d", &num);
	if(isPalindrome(num)) // check
		printf("The number is Palindrome."); // throw the output
	else
		printf("The number is NOT Palindrome.");
	return 0;
}
