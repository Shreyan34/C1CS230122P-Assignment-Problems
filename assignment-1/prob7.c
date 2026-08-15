// Generate the Armstrong numbers within a user-given range

#include <stdio.h>
#include <math.h>

int isArmstrong(int); // function prototype to check if a number is armstrong or not

int main() { // main function
	int range;
	printf("Enter the range:\n"); // take input of the range
	scanf("%d", &range);
	int i;
	for(i = 1; i<=range; i++) { // display all the armstrong numbers within the range
		if(isArmstrong(i)) {
			printf("%d is Armstrong.\n", i);
		}
	}
	return 0;
}

int isArmstrong(int num) { // function to check armstrong numbers 
	int count = 0; // to store the count of the numbers of digits
	int m = num, n = num; // create two copies of th enumber
	int sum = 0; // store the sum
	int digit;
	while(m) {
		count++;
		m /= 10;
	}
	while(n) {
		digit = n % 10;
		sum += pow(digit, count);
		n /= 10;
	}	
	if(sum == num) { // check the required condition
		return 1;
	}
	return 0;
}
