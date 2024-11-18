//9461
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void) {
	long long result[101] = { 0 };
	result[1] = 1;
	result[2] = 1;
	result[3] = 1;
	for (int i = 4; i <= 100; i++) {
		result[i] = result[i - 3] + result[i - 2];
	}

	int testCase = 0;
	scanf("%d", &testCase);

	for (int i = 0; i < testCase; i++) {
		int num = 0;
		scanf("%d", &num);
		printf("%lld\n", result[num]);
	}
	return 0;
}