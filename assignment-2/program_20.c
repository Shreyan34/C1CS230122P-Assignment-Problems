// Program 20
// Write a program in C to accept a sentence and find the length of each word. Also print the longest word

#include <stdio.h> // import dependencies

int main() {
    char s[1000]; // create a string with maximum length 1000
    int c, n = 0; // for extraction of words
    int i, j; // iterators
    int len = 0, start = 0;
    int longest_len = 0, longest_start = 0;

    printf("Enter a sentence: ");

    /* read the sentence character by character */
    while (n < 999 && (c = getchar()) != '\n' && c != EOF)
        s[n++] = (char)c;
    s[n] = '\0';

    printf("\nWord lengths:\n");

    /* i runs up to and including the '\0' so the last word is handled too */
    for (i = 0; ; i++) {
        if (s[i] != ' ' && s[i] != '\t' && s[i] != '\0') {
            if (len == 0)
                start = i;      /* a new word begins here */
            len++;
        } else {
            if (len > 0) {      /* a word just ended */
                for (j = start; j < start + len; j++)
                    putchar(s[j]);
                printf(" : %d\n", len);

                if (len > longest_len) {
                    longest_len = len;
                    longest_start = start;
                }
                len = 0;
            }
        }
        if (s[i] == '\0')
            break;
    }

    if (longest_len == 0) {
        printf("No words entered.\n");
    } else {
        printf("\nLongest word: ");
        for (j = longest_start; j < longest_start + longest_len; j++)
            putchar(s[j]);
        printf(" (length %d)\n", longest_len);
    }

    return 0;
}
