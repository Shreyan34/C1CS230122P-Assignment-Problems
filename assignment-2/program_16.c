// Program 16
// Write a menu driven program in C to accept a decimal number and convert it to corresponding binary, octal, hexadecimal form.

void printBinary(int n) {
	int i;
    // Assuming a 32-bit integer; adjust to 8 or 16 if needed
    for (i = 31; i >= 0; i--) {
        int k = n >> i; // Shift right by i positions
        
        if (k & 1)
            printf("1");
        else
            printf("0");
    }
    printf("\n");
}

int main() {
	int input, choice; // to store the input and the choice in the menu
	printf("Enter the number: ");
	scanf("%d", &input);
	// create the menu
	printf("Enter 1 to convert to binary.\nEnter 2 to convert to octal.\nEnter 3 to convert to hexadecimal.\nEnter your choice: ");
	scanf("%d", &choice);
	switch(choice) { // perform the menu
		case 1: {
			printf("The binary equivalent of %d is:\n", input);
			printBinary(input); // print the binary equivalent
			break;
		}
		case 2: {
			printf("The octal equivalent of %d is:\n%o", input, input); // print the octal equivalent
			break;
		}
		case 3: {
			printf("The hexadecimal equivalent of %d is:\n%x", input, input); // print the hexadecimal equivalent
			break;
		}
		default: // for making an invalid choice
			printf("INVALID CHOICE!!");
	}
	return 0;
}
