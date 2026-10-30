// Program 17
// Write a program to accept a set of integers and sort them in ascending order. Also accept an integer and perform linear search.

#include <stdio.h> // import dependencies
#include <stdlib.h>

void sort(int* arr, int len_of_array) {
	// a sorting function to take in an array and sort it using Bubble Sort method
	int i, j; // iterators
	for(i = 0; i<len_of_array-1; i++) {
		for(j = 0; j<len_of_array-i-1; j++) {
			if(arr[j] > arr[j+1]) { // comparison in each step
				int temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
	}
	printf("Sorted Array:\n"); // print the sorted array
	for(i = 0; i<len_of_array; i++) {
		printf("%d\t", arr[i]);
	}
}

int linear_search(int* arr, int len_of_arr, int target) { 
	// a function which performs linear search with a given target on a given integer pointer (presumed array)
	int i;
	for(i = 0; i<len_of_arr; i++) {
		if(arr[i] == target) {
			return 1;
		}
	}
	return 0;
}

int main() {
	int* a; // declare the necessary variables
	int length;
	int i;
	int t;
	printf("Enter the length of the array:\n"); // store the length of the array
	scanf("%d", &length);
	a = (int *)(malloc(length*sizeof(int))); // create the memory space for the array
	printf("Enter the elements of the array:\n"); // input the different elements of the array
	for(i = 0; i<length; i++) {
		scanf("%d", &a[i]);
	}
	sort(a, length); // sort the array
	printf("\nEnter the target integer to be searched:\n"); // perform linear search on the array
	scanf("%d", &t);
	if(linear_search(a, length, t)) {
		printf("Target found!");
	} else {
		printf("Target not found!");
	}
	free(a); // free memory
	return 0;
}
