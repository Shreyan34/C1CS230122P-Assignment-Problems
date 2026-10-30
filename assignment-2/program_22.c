// Program 22
// Make iniitials program

#include <stdlib.h> // import dependencies
#include <stdio.h>
#include <string.h>

#define MAX_STRING_LENGTH 100 // macro to store the maximum length of string allowed

char* get_substring(char* source, int s, int e) {
	// a function to get substrings from specified indices of a string
	char* target;
	int i, j;
	int len = e - s + 1;
	target = malloc(len*sizeof(char) + 1);
	for(i = s, j = 0; i<e; i++, j++) {
		target[j] = source[i];
	}
	target[j] = '\0';
	return target;
}

int main() {
	char input[MAX_STRING_LENGTH]; // to store the input
	printf("Input: ");
	scanf("%[^\n]", input);
	int p = 0, i; // iterator variables
	int last_space_count = 0;
	printf("Output: ");
	for(i = 0; i<strlen(input); i++) { // to traverse through the entire string
		if(input[i] == ' ') {
			char* word = get_substring(input, p, i);
			printf("%c. ", word[0]); // print the initials
			p = i + 1;
			last_space_count = i;
		}
	}
	char* surname = get_substring(input, last_space_count+1, strlen(input)); // to store the last word, ie, the surname
	printf("%s", surname);
	return 0;
}
