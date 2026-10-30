// Program 21
// find the palindrome words in a sentence

#include <stdio.h> // import dependencies
#include <string.h>
#include <ctype.h>

#define MAX_STRING_LENGTH 100 // macro to define the maximum length of string allowed

char* get_substring(char* source, int s, int e) {
	// a function that returns the substring from an opening and closing index from a source string pointer
	char* target;
	int i, j;
	int len = e - s + 1;
	target = malloc(len*sizeof(char)+1);
	for(i = s, j = 0; i<e; i++, j++) {
		target[j] = source[i];
	}
	target[j] = '\0';
	return target;
}

int is_palindrome(char* str) {
	// checks whether a given string is palindrome or not
	char* rev;
	int i, j;
	for (i = 0; i < strlen(str); i++) { // converts the characters of a string to lowercase first
        str[i] = tolower(str[i]);
    }
	rev = (char*)(malloc(MAX_STRING_LENGTH*sizeof(char)));
	for(i = 0, j = strlen(str) - 1; i<strlen(str) && j>=0; i++, j--) {
		rev[i] = str[j];
	}
	if(strcmp(rev, str) == 0)
		return 1;
	return 0;
}

int main() {
	char input[MAX_STRING_LENGTH]; // to store the input
	printf("Input-- ");
	scanf("%[^\n]", input);
	strcat(input, " ");
	printf("Ouput-- ");
	int p = 0, i;
	for(i = 0; i<strlen(input); i++) { // extract each word and check if palindrome or not
		if(input[i] == ' ') {
			char* word = get_substring(input, p, i);
			if(is_palindrome(word)) {
				printf("%s\t", word);
			}
			p = i + 1;
		}
	}
	return 0;
}
