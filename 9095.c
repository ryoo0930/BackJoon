//9095
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int result(int num);


int main(void) {
	int testCase = 0;
	scanf("%d", &testCase);
	for (int i = 0; i < testCase; i++) {
		int tmp = 0;
		scanf("%d", &tmp);
		printf("%d\n", result(tmp));
	}

	return 0;
}

int result(int num) {
	int* dp = (int*)calloc(num + 1, sizeof(int));
	dp[1] = 1; // 1
	dp[2] = 2; // 1 + 1, 2
	dp[3] = 4; // 1 + 1 + 1, 1 + 2, 3
	for (int i = 4; i <= num; i++) {
		dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
	}

	return dp[num];
}