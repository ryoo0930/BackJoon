//32653
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

long long gcd(long long a, long long b);
long long lcm(long long a, long long b);

int main(void) {
	int testCase = 0;
	scanf("%d", &testCase);
	long long* steak = (long long*)calloc(testCase, sizeof(long long));

	for (int i = 0; i < testCase; i++) {
		scanf("%d", &steak[i]);
	}

	long long result = steak[0];
	for (int i = 1; i < testCase; i++) {
		result = lcm(result, steak[i]);
	}

	printf("%lld", result * 2);

	return 0;
}

long long gcd(long long a, long long b) {
	int remainder = 1;
	while (remainder != 0) {
		remainder = a % b;
		a = b;
		b = remainder;
	}
	return a;
}

long long lcm(long long a, long long b) {
	return (a * b) / gcd(a, b);
}