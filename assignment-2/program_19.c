// Program 19
// Accept two 2D arrays of integers and perform matrix addition and multiplication

#include <stdio.h> // import dependencies

#define MAX_DIM 10 // to store the maximum order of a matrix

void printMatrix(int rows, int cols, int matrix[][MAX_DIM]) {
	// a function to print the matrix on the screen
	int i, j;
	for(i = 0; i<rows; i++) {
		for(j = 0; j<cols; j++) {
			printf("%d\t", matrix[i][j]);
		}
		printf("\n");
	}
}

int main() { 
	int i, j, k; // iterators
	int order; // to store the order
	int arr1[MAX_DIM][MAX_DIM]; // creating two matrices
	int arr2[MAX_DIM][MAX_DIM];
	printf("Enter the order of the matrices:"); // take the necessary inputs
	scanf("%d", &order);
	printf("Enter the elements of the first matrix:\n");
	for(i = 0; i<order; i++) {
		for(j = 0; j<order; j++) {
			scanf("%d", &arr1[i][j]);
		}
	}
	printf("Enter the elements of the second matrix:\n");
	for(i = 0; i<order; i++) {
		for(j = 0; j<order; j++) {
			scanf("%d", &arr2[i][j]);
		}
	}
	printf("\nFirst Matrix:\n"); // print the first matrix
	printMatrix(order, order, arr1);
	printf("\nSecond Matrix:\n"); // print the second matrix
	printMatrix(order, order, arr2);
	// first perform the addition
	int sum[MAX_DIM][MAX_DIM];
	for(i = 0; i<order; i++) {
		for(j = 0; j<order; j++) {
			sum[i][j] = arr1[i][j] + arr2[i][j];
		}
	}
	printf("\nResultant Matrix (after summation):\n");
	printMatrix(order, order, sum); // print the resultant
	// now perform the matrix multiplication
	int prod[MAX_DIM][MAX_DIM];
	for (i = 0; i<order; i++) {
        for (j = 0; j<order; j++) {
            prod[i][j] = 0;
            for (k = 0; k<order; k++) {
                prod[i][j] += arr1[i][k] * arr2[k][j];
            }
        }
    }
    printf("\nResultant Matrix (after product):\n");
	printMatrix(order, order, prod); // print the resultant
	return 0;
}
