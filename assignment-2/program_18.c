// Program 18
/*Write a menu driven program in C to print the left diagonal, right diagonal or boundary elements of a
2D as per user’s choice.*/

#include <stdio.h> // import dependencies
#include <stdlib.h>

#define MAX_ROWS 10 // define macros to store the maximum size of the rows and columns
#define MAX_COLS 10

int main() {
	int arr[MAX_ROWS][MAX_COLS]; // create a 2D matrix
	int n, choice; // to store the dimension and choice in the menu
	int i, j; // iterators
	printf("Enter the dimension of the 2D matrix:"); // take the necessary inputs
	scanf("%d", &n);
	printf("Enter the elements of the 2D matrix:\n");
	for(i = 0; i<n; i++) {
		for(j = 0; j<n; j++) {
			scanf("%d", &arr[i][j]);
		}
	}
	printf("The 2D Matrix is:\n"); // print the original matrix
	for(i = 0; i<n; i++) {
		for(j = 0; j<n; j++) {
			printf("%d\t", arr[i][j]);
		}
		printf("\n");
	}
	// create the menu
	printf("\nEnter 1. to print the left diagonal.\nEnter 2. to print the right diagonal.\nEnter 3 to print the boundary elements.\n\nEnter your choice:\t");
	scanf("%d", &choice);
	switch(choice) {
		case 1: {
			printf("\nThe Left Diagonal elements are:\n"); // print the left diagonal
			for(i = 0; i<n; i++) {
				for(j = 0; j<n; j++) {
					if(i==j) printf("%d\t", arr[i][j]);
				}
			}
			break;
		}
		case 2: {
			printf("\nThe Right Diagonal elements are:\n"); // print the right diagonal
			for(i = 0; i<n; i++) {
				for(j = 0; j<n; j++) {
					if((i+j)==(n-1)) printf("%d\t", arr[i][j]);
				}
			}
			break;
		}
		case 3: {
			printf("\nThe Boundary Elements are:\n"); // print the boundary elements
			for(i = 0; i<n; i++) {
				for(j = 0; j<n; j++) {
					if(i == 0 || j == 0 || i == (n-1) || j == (n-1))
						printf("%d\t", arr[i][j]);
				}
			}
			break;
		}
	}
	return 0;
}
