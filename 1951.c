#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define MOD 1234567

int main(void) {
	long long num = 0;
	scanf("%lld", &num);

	long long result = 0;
	for (long long start = 1, length = 1; start <= num; start *= 10, length++) {
		long long end = start * 10 - 1;
		if (end > num) { end = num; }
		long long count = end - start + 1;
		result += count * length;
		result %= MOD;
	}

	printf("%lld", result);
	return 0;
}
