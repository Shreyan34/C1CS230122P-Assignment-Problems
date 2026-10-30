// Program 13 
// Write a program in C to accept a 2D array of integers to find out maximum and minimum across rows and columns

#include <stdio.h>

#define MAX_ROWS 10 // macros to store maximum number of cols and rows
#define MAX_COLS 10 

int main() {
	int arr[MAX_ROWS][MAX_COLS]; // create an array
	int rows, cols; // to take input of the rows and cols
	int i, j; // iterators
	int max_r, max_col; // to store the maximum across rows and columns
	int min_r, min_col; // to store the minimum across rows and columns
	printf("Enter the number of rows:");
	scanf("%d", &rows);
	printf("Enter the number of cols:");
	scanf("%d", &cols);
	printf("Enter the elements of the array:\n");
	for(i = 0; i<rows; i++) {
		for(j = 0; j<cols; j++) {
			scanf("%d", &arr[i][j]);
		}
	}
	printf("\nThe Original Array is:\n"); // print the original array
	for(i = 0; i<rows; i++) {
		for(j = 0; j<cols; j++) {
			printf("%d\t", arr[i][j]);
		}
		printf("\n");
	}
	printf("\nAcross the rows:\n");
	for(i = 0; i<rows; i++) {
		max_r = arr[i][0]; // initialize values accordingly
		min_r = arr[i][0];
		for(j = 0; j<cols; j++) { // compute the max and the min across rows
			if(arr[i][j] >= max_r) {
				max_r = arr[i][j];
			}
			if(arr[i][j] <= min_r) {
				min_r = arr[i][j];
			}
		}
		printf("Maximum and minimum of row %d: %d, %d\n", (i+1), max_r, min_r); // print the values
	}
	printf("\nAcross the cols:\n");
	for(j = 0; j<cols; j++) {
		max_col = arr[0][j]; // initialize values accordingly
		min_col = arr[0][j];
		for(i = 0; i<rows; i++) {
			if(arr[i][j] >= max_col) { // compute the max and the min across cols
				max_col = arr[i][j];
			}
			if(arr[i][j] <= min_col) {
				min_col = arr[i][j];
			}
		}
		printf("Maximum and minimum of col %d: %d, %d\n", (j+1), max_col, min_col); // print the values 
	}
	return 0;
}
