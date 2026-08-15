// perform the temperature conversion from Celsius to Fahrenheit and vice-versa as per user's choice

#include <stdio.h>

int main() { // main function
	float temp, ctemp;
	printf("Enter 1 to convert C -> F.\nEnter 2 to convert F -> C.\n"); // take input
	int choice;
	scanf("%d", &choice);
	printf("Enter the temperature:\n"); 
	scanf("%f", &temp);
	switch(choice) { // create the menu
		case 1:
			ctemp = (temp * 1.8) + 32.0; // perform the conversions
			printf("Converted temperature: %f", ctemp);
			break;
		case 2:
			ctemp = (temp - 32.0) * (5.0/9.0);
			printf("Converted temperature: %f", ctemp);
			break;
		default:
			printf("Invalid Input!");

	}
	return 0;
}
