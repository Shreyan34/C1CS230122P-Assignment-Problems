/*
	Write a menu driven program to generate the following patterns given the number of lines, 'n', from the user using separate functions for the same:
	Example: for n = 5,
	Output:
	
		a)	*****
			 ****
			  ***
			   **
			    *
			    
		b)	    *
			   * *
			  * * *
			 * * * *
			* * * * *  
			
		c)
			  * * *
				* *
			      *
			    * *
			  * * * 

*/

#include <stdio.h>

void firstPattern(int n) {
	/*
			*****
			 ****
			  ***
			   **
			    *
	
	*/
	int i, j, k;
	for(i = n; i>=1; i--) {
		printf("*");
	}
	printf("\n");
	for(i = 1; i<=n; i++) {
		for(j = 1; j<=i; j++) {
			printf(" ");
		}
		for(k = (n-i); k>=1; k--) {
			printf("*");
		}
		printf("\n");
	}
}

void secondPattern(int n) {
	/*
		    	*
			   * *
			  * * *
			 * * * *
			* * * * *  	
	
	*/
	int i, j, k;
	for(i = 0; i<=(n-1); i++) {
		for(j = (n-1); j>=i; j--) {
			printf(" ");
		}
		for(k = 0; k<=i; k++) {
			printf("* ");
		}
		printf("\n");
	}
}

void thirdPattern(int n) {
	/*
		  	  * * *
				* *
			      *
			    * *
			  * * *
	*/
	
	int i, j, c = 2, k;
	for(i = 0; i<(n/2); i++) {
		c++;
		for(j = 0; j<(c-1); j++) {
			printf(" ");
		}
		for(k = (n-c); k>=0; k--) {
			printf("*");
		}
		printf("\n");
	}
	for(i = ((n/2)+1); i<=n; i++) {
		c--;
		for(j = c; j>=0; j--) {
			printf(" ");
		}
		for(k = 0; k<(n-c-1); k++) {
			printf("*");
		}
		printf("\n");
	}
}

int main() {
	int n;
	printf("n = ");
	scanf("%d", &n);
	char choice;
	printf("Enter choice (a, b, c): ");
	scanf(" %c", &choice);
	switch(choice) {
		case 'a':
			firstPattern(n);
			break;
		case 'b':
			secondPattern(n);
			break;
		case 'c':
			thirdPattern(n);
			break;
		default:
			printf("Invalid Input!");
			break;
	}
	return 0;
}
