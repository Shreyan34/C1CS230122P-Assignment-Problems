/* Display the Pascal's triangle till the user given number of lines 'n'
Example: For n = 6,

       1
    1    1
   1   2  1
  1  3  3  1
 1 4   6   4  1
1 5 10  10  5  1

Use the following functions:
	a) long long factorial(int n)
	b) long long binomialCoeff(int n, int k)

*/

#include <stdio.h>

long long factorial(int n) {
	if(n == 0) return 1;
	return n * factorial (n-1);
}

long long binomialCoeff(int n, int k) {
	return (factorial(n)) / ((factorial(k)) * factorial(n-k));
}

int main() {
	int n;
	printf("n = ");
	scanf("%d", &n);
	int sp;
	for(sp = 0; sp<=n; sp++) {
		printf(" ");
	}
	printf("1\n");
	int i, j, k;
	for(i = 1; i<=(n-1); i++) {
		for(j = (n-1); j>=i; j--) {
			printf(" ");
		}
		for(k = 0; k<=i; k++) {
			printf(" %lld ", binomialCoeff(i, k));
		}
		printf("\n");
	}
	return 0;
}
