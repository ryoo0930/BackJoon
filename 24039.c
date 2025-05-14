#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdbool.h>

int main() {
	int prime[10001] = { 0 };
	for (int i = 2; i <= 10000; i++) { prime[i] = i; }

	for (int i = 2; i <= 10000; i++) {
		if (prime[i] == 0) continue;
		for (int j = i * 2; j <= 10000; j += i) { prime[j] = 0; }
	}

	int onlyPrime[2000] = { 0 };
	for (int i = 0, j = 0; i <= 10000; i++) {
		if (prime[i] != 0) {
			onlyPrime[j] = prime[i];
			j++;
		}
	}

	int input = 0;
	scanf("%d", &input);

	int result = 0;
	for (int i = 0; i < 1999; i++) {
		if (input < onlyPrime[i] * onlyPrime[i + 1]) {
			result = onlyPrime[i] * onlyPrime[i + 1];
			break;
		}
	}
	printf("%d", result);

	return 0;
}
