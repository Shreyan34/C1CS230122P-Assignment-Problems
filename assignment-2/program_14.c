// Program 14

#include <stdio.h> // import the dependencies
#include <string.h>
#include <stdlib.h>

#define MAX_STRING_SIZE 100 // define a macro to store the maximum string size

int vowel_count(char* str) { // function to return the count of the number of vowels in a string
	int i;
	int count;
	count = 0;
	for(i = 0; i<strlen(str); i++) {
		if(str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u' ||
		   str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U')
		   	count++;
	}
	return count;
}

int main() {
	// create the menu
	int choice;
	int i,j;
	printf("Press 1 to show the address of each character in a string.\n");
	printf("Press 2 to concatenate two strings without strcat().\n");
	printf("Press 3 to concatenate two strings with strcat().\n");
	printf("Press 4 to compare two strings.\n");
	printf("Press 5 to convert all lowercase characters to uppercase.\n");
	printf("Press 6 to convert all uppercase characters to lowercase.\n");
	printf("Press 7 to calculate the number of vowels.\n");
	printf("Press 8 to reverse a given string.\n");
	printf("\nEnter your choice: ");
	scanf("%d", &choice);
	while (getchar() != '\n'); // flush the newline character
	switch(choice) {
		case 1: {
			char* s;
			s = (char *)(malloc(MAX_STRING_SIZE*sizeof(char))); // create a free string memory block of maximum 100 characters
			printf("Enter the string:"); // input the string
			fgets(s, MAX_STRING_SIZE, stdin);
			printf("Address of each character within the string:\n"); // print address of each character
			for(i = 0; i<strlen(s); i++) {
				printf("Address of %c is %p.\n", s[i], (void*)&s[i]);
			}
			free(s); // free the pointer from memory
			break;
		}
		case 2: {
			char *s1, *s2, *joined; // declare three pointers
			int max_concat_size = 2 * MAX_STRING_SIZE; // size of the maximum concatenated string
			s1 = (char *)(malloc(MAX_STRING_SIZE*sizeof(char)));
			printf("Enter the first string:"); // take input of the first string
			fgets(s1, MAX_STRING_SIZE, stdin);
			s2 = (char *)(malloc(MAX_STRING_SIZE*sizeof(char)));
			printf("Enter the second string:"); // take input of the second string
			fgets(s2, MAX_STRING_SIZE, stdin);
			s1[strcspn(s1, "\n")] = '\0'; // remove the newline characters from the string
			s2[strcspn(s2, "\n")] = '\0';
			joined = (char *)(malloc(max_concat_size*sizeof(char)));
			for(i = 0, j = 0; i<strlen(s1); i++, j++) { // copy the contents of the first string into the string which will hold the concatenation
				joined[j] = s1[i];
			}
			for(i = 0; i<strlen(s2); i++, j++) { // now copy the contents of the second string
				joined[j] = s2[i];
			}
			joined[j] = '\0'; // add a null character to terminate
			printf("The concatenated string is:%s", joined); // print the concatenated string
			free(s1); free(s2); free(joined); // free memory
			break;
		}
		case 3: {
			char *s1, *s2; // two strings to store the inputs
			s1 = (char *)(malloc(MAX_STRING_SIZE*sizeof(char)));
			printf("Enter the first string:"); // input of the first string
			fgets(s1, MAX_STRING_SIZE, stdin);
			s2 = (char *)(malloc(MAX_STRING_SIZE*sizeof(char))); // input of the second string
			printf("Enter the second string:");
			fgets(s2, MAX_STRING_SIZE, stdin);
			s1[strcspn(s1, "\n")] = '\0'; // replace the newline characters with null onesw
			s2[strcspn(s2, "\n")] = '\0';
			strcat(s1, s2); // concatenate
			printf("Concatenated strings are: %s", s1); // print the concatenation	
			free(s1); free(s2);	// free memory
			break;
		}
		case 4: {
			char *s1, *s2; // input two strings as done above
			s1 = (char *)(malloc(MAX_STRING_SIZE*sizeof(char)));
			printf("Enter the first string:");
			fgets(s1, MAX_STRING_SIZE, stdin);
			s2 = (char *)(malloc(MAX_STRING_SIZE*sizeof(char)));
			printf("Enter the second string:");
			fgets(s2, MAX_STRING_SIZE, stdin);
			s1[strcspn(s1, "\n")] = '\0'; // replace the newline characters with the null ones
			s2[strcspn(s2, "\n")] = '\0';
			int result = strcmp(s1, s2); // compare the two strings
			if(result == 0) { // print result accordingly
				printf("Two strings are equal!");
			} else if(result > 0) {
				printf("\"%s\" comes after \"%s\" in the dictionary.\n", s1, s2);
			} else {
				printf("\"%s\" comes before \"%s\" in the dictionary.\n", s1, s2);
			}
			free(s1); free(s2); // free the memory
			break;
		}
		case 5: {
			char *input, *output; // to store the input and the output string
			input = (char *)(malloc(MAX_STRING_SIZE*sizeof(char)));
			output = (char *)(malloc(MAX_STRING_SIZE*sizeof(char)));
			printf("Enter the source:"); // to take the input
			fgets(input, MAX_STRING_SIZE, stdin);
			for(i = 0; i<strlen(input); i++) { // do the needful conversion
				if(input[i] >= 97 && input[i] <= 122) {
					output[i] = input[i] - 32;
				} else {
					output[i] = input[i];	
				}
			}
			printf("Converted string: %s", output); // print the output
			free(input); free(output); // free the memory
			break;
		}
		case 6: {
			char *input, *output; // same as above, only the conversion algorithm changes
			input = (char *)(malloc(MAX_STRING_SIZE*sizeof(char)));
			output = (char *)(malloc(MAX_STRING_SIZE*sizeof(char)));
			printf("Enter the source:");
			fgets(input, MAX_STRING_SIZE, stdin);
			for(i = 0; i<strlen(input); i++) {
				if(input[i] >= 65 && input[i] <= 90) {
					output[i] = input[i] + 32;
				} else {
					output[i] = input[i];	
				}
			}
			printf("Converted string: %s", output);
			free(input); free(output);
			break;
		}
		case 7: {
			char *input; // to store the input
			input = (char *)(malloc(MAX_STRING_SIZE*sizeof(char)));
			printf("Input String: "); // take the input
			fgets(input, MAX_STRING_SIZE, stdin);
			printf("Number of vowels in the string is: %d", vowel_count(input)); // count and return the number of vowels in the string
			free(input); // free the pointer from memory
			break;
		}
		case 8: {
			char *input, *output; // to store the input and output
			input = (char *)(malloc(MAX_STRING_SIZE*sizeof(char)));
			output = (char *) (malloc(MAX_STRING_SIZE*sizeof(char)));
			printf("Input String: ");
			fgets(input, MAX_STRING_SIZE, stdin);
			for(i = 0, j = strlen(input)-1; i<=strlen(input) && j>=0; i++, j--) { // reverse the given string using the iterators
				output[i] = input[j];
			}
			printf("Reversed String: %s", output); // show the reversed string
			free(input); free(output); // free memory
			break;
		}
		default: // to print the message if invalid choice is made
			printf("INVALID CHOICE!!");
	}
	return 0;
}
