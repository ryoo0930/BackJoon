//11050: 이항 계수 1
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int factorial(int a);

int main(void) {
	int N = 0, K = 0;
	scanf("%d %d", &N, &K);

	int result = factorial(N) / (factorial(N - K) * factorial(K));

	printf("%d", result);
	return 0;
}

int factorial(int a) {
	int result = 1;
	for (int i = 1; i <= a; i++) {
		result *=  i;
	}
	return result;
}