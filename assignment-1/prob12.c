/*
	Evaluate the sum of the following series:
		a) S = 1 + (1+2) + (1+2+3) + ... + (1+2+3+...+n)
		b) S = 1 + x + x2/2! + x3/3! + ... upto n terms
	
	Use a function fact(int n) to calculate the factorial
*/

#include <stdio.h>
#include <math.h>

long fact(int n) {
	if(n == 0) return 1;
	return n * fact(n-1);
}

int main() {
	int n;
	printf("n = ");
	scanf("%d", &n);
	printf("x = ");
	int x;
	scanf("%d", &x);
	int s1 = 0, s2 = 0;
	// find the first sum
	printf("S1 = ");
	int i, j;
	for(i = 1; i<=n; i++) {
		int st = 0;
		for(j = 1; j<=i; j++) {
			st += j; 
		}
		s1 += st;
	}
	printf("%d\n", s1);
	// find the second sum
	printf("S2 = ");
	for(i = 0; i<=n; i++){
		s2 += pow(x,i) / fact(x);
	}
	printf("%d\n", s2);
	return 0;
}
